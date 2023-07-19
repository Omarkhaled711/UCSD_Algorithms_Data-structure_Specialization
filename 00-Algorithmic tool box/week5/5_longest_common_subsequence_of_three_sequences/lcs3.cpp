#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int dp[109][109][109];

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c, int i, int j, int k)
{
	if (i < 0 || j < 0 || k < 0)
		return 0;
	if (dp[i][j][k] != -1)
		return dp[i][j][k];
	if ((a[i] == b[j]) && (a[i] == c[k]))
	{
		dp[i][j][k] = 1 + lcs3(a, b, c, i-1, j-1, k-1);
		return dp[i][j][k];
	}
	dp[i][j][k] = max(max(lcs3(a, b, c, i - 1, j, k), lcs3(a,b,c, i, j-1, k)), lcs3(a,b,c, i, j, k-1));
	return dp[i][j][k];
}

int main() {
  memset(dp, -1, sizeof(dp));
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c, a.size() - 1, b.size() - 1, c.size() - 1) << std::endl;
}
