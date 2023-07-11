#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

std::pair<int, int> partition3(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x)
	{
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  int m_second = j;
  for (int i = l; i < j;i++)
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

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  std::pair<int, int> m_pair;
  swap(a[l], a[k]);
  m_pair = partition3(a, l, r);
  randomized_quick_sort(a, l, m_pair.first - 1);
  randomized_quick_sort(a, m_pair.second + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
