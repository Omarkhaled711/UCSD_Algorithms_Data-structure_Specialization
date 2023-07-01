#include <bits/stdc++.h>

using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  int n = weights.size();
  vector<pair<double, int>>valuePerWeight;
  for (int i = 0; i<n ; i++)
  {
	valuePerWeight.push_back (make_pair((double)values[i]/weights[i], i));
  }
  sort(valuePerWeight.rbegin(), valuePerWeight.rend());
	int i = 0;
	while (capacity != 0 && i < n)
	{
		int a = min(capacity, weights[valuePerWeight[i].second]);
		value += (a * valuePerWeight[i].first);
		i++;
		capacity -= a;
	}
	return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
