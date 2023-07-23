#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int dp[(int) 1e5 + 9];
int get_weight(int W, const vector<int> &w, int i)
{
	if (i < 0 || W == 0)
		return (0);
	if (dp[W] != -1)
		return dp[W];
	if (w[i] <= W)
	{
			int num1 = w[i] + get_weight(W-w[i], w, i-1);
			int num2 = get_weight(W, w, i-1);
			dp[W] = max(num1, num2);
	}
	else
	{
		dp[W] = get_weight(W, w, i-1);
	}
	return dp[W];
}

int optimal_weight(int W, const vector<int> &w) {
	return (get_weight(W, w, w.size() - 1));
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
