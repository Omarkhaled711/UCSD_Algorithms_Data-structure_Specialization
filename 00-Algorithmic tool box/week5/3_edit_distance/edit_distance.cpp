#include <iostream>
#include <string>

using namespace std;
int dp[109][109];
int mis_match;
int edit_distance(const string &str1, const string &str2) {
  for (int i = 0; i <= str1.size(); i++)
	  dp[i][0] = i;
  for (int j = 0; j<= str2.size(); j++)
	  dp[0][j] = j;
  for (int i = 1; i<=str1.size(); i++)
  {
	for (int j = 1; j<=str2.size(); j++)
	{
		mis_match = (str1[i - 1] == str2[j - 1] ? 0 : 1);
		dp[i][j] = min(min(dp[i-1][j] + 1, dp[i][j-1] + 1), dp[i-1][j-1] + mis_match);
	}
  }
  return dp[str1.size()][str2.size()];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
