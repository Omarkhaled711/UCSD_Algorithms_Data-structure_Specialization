#include <bits/stdc++.h>

using namespace std;

struct Segment {
  int start, end;
};

bool compare(Segment &s1, Segment &s2)
{
	return s1.end < s2.end;
}
void get_intersect(int coord, vector <Segment> &segments, vector <int> &side, unordered_map <int, int> &seg)
{
	for (int i = 0; i < segments.size(); i++)
	{
		if (seg[i] == 1)
			continue;
		int left = segments[i].start;
		int right = segments[i].end;
		if (coord >= left && coord <= right)
		{
			side.push_back(i);
		}
	}
}
vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  unordered_map <int, int> seg(segments.size());
  sort(segments.begin(), segments.end(),compare);
  for (int i = 0; i< segments.size(); i++)
  {
	vector<int> right_side;
	if (seg[i] == 1)
		continue;
	get_intersect(segments[i].end, segments, right_side, seg);
	for (int j = 0; j<right_side.size(); j++)
	{
		seg[right_side[j]] = 1;
	}
	points.push_back(segments[i].end);
	right_side.clear();
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
