#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

int dp[(int)1e6 + 9];
vector<int> optimal_sequence(int n)
{
	vector<int> v;
	dp[1] = 1;
	dp[0] = INT_MAX;
	for (int i = 2; i<= n; i++)
	{
		int p1= i - 1;
		int p2 = (i/2.0 - i/2 == 0 ? i/2 : 0);
		int p3 = (i/3.0 - i/3 == 0 ? i/3 : 0);
		dp[i] = min(min(dp[p1], dp[p2]), dp[p3]) + 1;
	}
	v.push_back(n);
	for (int i = n; i> 1; )
	{
		if (dp[i] == (dp[i -1] + 1))
		{
			v.push_back(i - 1);
			i -= 1;
		}
		else if ((i/2.0 - i/2 == 0) && dp[i] == (dp[i/2] + 1))
		{
			v.push_back(i/2);
			i /= 2;
		}
		else
		{
			v.push_back(i/3);
			i /= 3;
		}
	}
	reverse(v.begin(), v.end());
	return v;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
