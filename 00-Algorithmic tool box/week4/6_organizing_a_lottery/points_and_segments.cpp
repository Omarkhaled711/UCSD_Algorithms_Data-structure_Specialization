#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int, int> one, pair<int, int> two)
{
	/* note: I guess that's how pairs are compared by defaul, but
	 * since I'm not sure and I'm too lazy to search, I just implemented this
	 * comparison function
	 */
	if (one.first == two.first)
	{
		return (one.second < two.second);
	}
	return one.first < two.first;
}

vector<int> fast_count_segments(vector<int> &starts, vector<int> &ends, vector<int> &points) {
  vector<int> cnt(points.size());
  /* combining all vectors in one vector, keeping in mind whether this data is
   * related to "starts" or "ends" or "points", we can use a pair to help us in
   * the determination process (pair.second -> the origin of the data point) then
   * we can easily and efficiently count the segments that each point cut
   */
  vector<pair<int,int>> all;
  int segments_cut = 0;
 map<int, vector<int>> remeber_index; /* keeping track of the original index of the points, usually each point will has only one index, but a corner case will emerge if a point has more than one index, and that's way I'm mapping an int to a vector */
  for (int i = 0; i<starts.size(); i++)
  {
	all.push_back(make_pair(starts[i], 0));
	all.push_back(make_pair(ends[i], 2));
  }
  for (int i = 0; i<points.size();i++)
  {
	remeber_index[points[i]].push_back(i);
	all.push_back(make_pair(points[i], 1));
  }
  sort(all.begin(), all.end(), compare);
  for (int i = 0; i<all.size(); i++)
  {
	if (all[i].second == 0)
		segments_cut++;
	else if (all[i].second == 2)
		segments_cut--;
	else
	{
		int sz = remeber_index[all[i].first].size();
		for (int j =0; j<sz; j++)
		{
			cnt[remeber_index[all[i].first][j]] = segments_cut;
		}
	}
  }
  return (cnt);
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
