#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

int dp[(int)1e3 + 9];

int get_change(int m)
{
	for (int i = 1; i<= m; i++)
	{
		if (i < 3)
			dp[i] = dp[i - 1] + 1;
		else if (i < 4)
			dp[i] = min(dp[i-1], dp[i - 3]) + 1;
		else
		{
			dp[i] = min(min(dp[i-1], dp[i-3]), dp[i - 4]) + 1;
		}
	}
	return dp[m];
}
int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
