#include <bits/stdc++.h>

using namespace std;

/**
Approach breifly:
first split the given n points into 2 halves (S_1, and S_2) of size n/2
By making two recursive calls for the sets S_1 and S_2 , we find the
minimum distances d_1 and d_2 in these subsets. Let d = min{d 1 , d 2 }.

It remains to check whether there exist points p_1 ∈ S_1 and p_2 ∈ S_2 such that
the distance between them is smaller than d.To check this in a fast way, 
we first discard all points from S_1 and S_2 whose x-distance to the
middle line is greater than d. (more on that is explained in the comments of the functions)
*/

bool compare2 (pair<int, int> point1, pair<int, int> point2)
{
	/* Compare the points based on the y coords */
	if (point1.second == point2.second)
		return point1.first < point2.first;
	return point1.second < point2.second;
}
double get_dist(pair<int, int> p1, pair<int, int> p2)
{
	/* computing the distance for 2 given points */
	return sqrt(pow((p1.first-p2.first),2) + pow((p1.second - p2.second),2));
}
void consider_left_part(vector<pair<int,int>>& connecting_segments, vector<pair<int, int>> &points, int left, int mid, double d_min_temp, int mid_point)
{
	/* as stated earlier we want to check shortest distances between the 2 segments, and we discard the points that will result in a distance bigger that d_min_temp, so this function consider only those who have potential from the left segment*/
	for (int i = left; i < mid; i++)
	{
		if ((mid_point - points[i].first) <= d_min_temp)
		{
			connecting_segments.push_back(points[i]);
		}
	}
	connecting_segments.push_back(points[mid]); /* our reference point */
}

void consider_right_part(vector<pair<int,int>>& connecting_segments, vector<pair<int, int>> &points, int mid_1, int right, double d_min_temp, int mid_point)
{
	/* like the one above it, but for right segment; we could have combined them in one function, but I prefered to keep them seperate, as it makes the code easier to visualize, and write */
	for (int i = mid_1; i <= right; i++)
	{
		if ((points[i].first - mid_point) <= d_min_temp)
		{
			connecting_segments.push_back(points[i]);
		}
	}
}
double get_min_dist(vector<pair<int, int>> &connecting_segments,double d_min_temp)
{
	/* sorting with respect to y-axis to compare the distances of the connected segments*/
	double d_min_connected = d_min_temp;
	sort(connecting_segments.begin(), connecting_segments.end(),compare2);
	int n = connecting_segments.size();
	/* we used j<= i+7, because if j >= i+8, then the distance between the two points will for sure exceed d_min_temp (try and draw it)*/
	for (int i = 0; i<n && i <= n; i++)
	{
		for (int j = i + 1; j<n && j<= i+7; j++)
		{
			double dist = get_dist(connecting_segments[i], connecting_segments[j]);
			d_min_connected = min(dist, d_min_connected);
		}
	}
	return d_min_connected;
}
double minimal_distance(vector<pair<int,int>> &points, int left, int right)
{
	/* using divide and conqure, and the functions above to get the minimum distance */
	if (left >= right)
		return numeric_limits<double>::max();
	if (left+1 == right)
	{
		double dist = get_dist(points[left], points[right]);
		return dist;
	}
	int mid = left + (right - left)/2;
	double d_left = minimal_distance(points, left, mid);
	double d_right = minimal_distance(points, mid + 1, right);
	double d_min_temp = min(d_left, d_right);
	vector<pair<int,int>> connecting_segments;
	consider_left_part(connecting_segments, points, left, mid, d_min_temp, points[mid].first);
	consider_right_part(connecting_segments, points, mid + 1, right, d_min_temp, points[mid].first);
	double d_min_connected = get_min_dist(connecting_segments, d_min_temp);
	return (d_min_connected);
}
bool compare1(pair<int, int> point1, pair<int, int>point2)
{
	/* compare based on the x-axis */
	if (point1.first == point2.first)
		return point1.second < point2.second;
	return point1.first < point2.first;
}

int main() {
  size_t n;
  std::cin >> n;
  int x, y;
  vector<pair<int,int>> points;
  for (size_t i = 0; i < n; i++)
  {
    std::cin >> x >> y;
	points.push_back(make_pair(x, y));
  }
  sort(points.begin(), points.end(), compare1);
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(points, 0, points.size() - 1) << "\n";
}
