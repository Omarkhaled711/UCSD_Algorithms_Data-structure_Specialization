#include <algorithm>
#include <iostream>
#include <vector>
#include <random>
using namespace std;

/**
 * This problem can be solved easily using a map, but since this is a divide and conqure training, I will use quick sort with 3 partitions to solve this problem
 */
void swap (int &first, int &second)
{
	int temp = first;
	first = second;
	second = temp;
}
int get_random(std::mt19937& gen, int left, int right)
{
	std::uniform_int_distribution<> dis(left, right - 1);
	return dis(gen);
}
std::pair<int, int> partition3(vector<int> &a, int left, int right)
{
	int x = a[left];
	int j = left;
	for (int i = left + 1; i < right; i++)
	{
		if (a[i] <= x)
		{
			j = j+1;
			swap (a[i], a[j]);
		}
	}
	swap(a[left], a[j]);
	int m_second = j;
	for (int i = left; i < j; i++)
	{
		if (a[i] == x)
		{
			j--;
			while (j > i && a[j] == x)
				j--;
			swap(a[j], a[i]);
		}
	}
	return std::make_pair(j, m_second);
}
int get_majority_element(vector<int> &a, int left, int right, std::mt19937& gen)
{
  if (left >= right) return (0);
  int k = get_random(gen, left, right);
  std::pair<int, int> m_pair;
  swap(a[left], a[k]);
  m_pair = partition3(a, left, right);
  if (m_pair.second - m_pair.first + 1 > (a.size() / 2))
  {
	return (1);
  }
  int return1 = get_majority_element(a, left, m_pair.first, gen);
  int return2 = get_majority_element(a, m_pair.second + 1, right, gen);
  return (return1 || return2);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::random_device rd;
  std::mt19937 gen(rd());
  std::cout << get_majority_element(a, 0, a.size(), gen) << '\n';
}
