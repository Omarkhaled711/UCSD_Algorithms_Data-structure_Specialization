#include <bits/stdc++.h>
using namespace std;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  int sum = 0;
  map<int, int> m;
  for (int i = 1; sum != n; i++)
  {
	m[i] = 1;
	if (m[n - (sum + i)] != 1)
	{
		summands.push_back(i);
		sum +=i;
	}
  }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
