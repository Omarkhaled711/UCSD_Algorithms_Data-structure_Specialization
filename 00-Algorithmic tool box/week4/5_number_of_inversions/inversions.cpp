#include <iostream>
#include <vector>

using std::vector;

long long merge(vector<int>& a, int left, int ave, int right)
{
	long long number_of_inversions = 0;
	vector<int> left_arr(ave - left);
	vector<int> right_arr(right - ave);

	for (int i = 0; i < left_arr.size(); i++)
	{
		left_arr[i] = a[left + i];
	}
	for (int i =0; i<right_arr.size();i++)
	{
		right_arr[i] = a[ave + i];
	}
	int i_left, j_right, i = left;
	for (i_left = 0, j_right = 0; i_left < left_arr.size() && j_right < right_arr.size();)
	{
		if(right_arr[j_right] < left_arr[i_left])
		{
			number_of_inversions += left_arr.size() - i_left;
			a[i] = right_arr[j_right];
			j_right++;
		}
		else
		{
			a[i] = left_arr[i_left];
			i_left++;
		}
		i++;
	}
	while (i_left < left_arr.size())
	{
		a[i] = left_arr[i_left];
		i++;
		i_left++;
	}
	while (j_right < right_arr.size())
	{
		a[i] = right_arr[j_right];
		j_right++;
		i++;
	}
	return number_of_inversions;
}
long long get_number_of_inversions(vector<int> &a, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, left, ave);
  number_of_inversions += get_number_of_inversions(a, ave, right);
  number_of_inversions += merge(a, left, ave, right);
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << get_number_of_inversions(a, 0, a.size()) << '\n';
}
