#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

/**
 * Solution:
 * First, we need to check whether the sum of the array elements is divisible by 3.
 * If it's not, we return 0.
 * Otherwise, we can solve this as a two-knapsack problem by filling two knapsacks
 * at the same time, and whatever is left will be in the third knapsack.
 * We only need to check that both knapsacks have a capacity of (sum/3).
 * If this is true, we return 1; otherwise, we return 0.
 * Since the sum is divisible by 3, we are sure that if the two knapsacks carry
 * (sum/3), the third one will carry (sum/3) as well without the need
 * for further calculations.
 */

int dp[1009][1009];

int part(int Wx, int Wy, vector<int> &A, int i)
{
	if (Wx == 0 && Wy == 0)
		return 1;
	if (Wx < 0 || Wy < 0 || i < 0)
		return 0;
	if (dp[Wx][Wy] != -1)
		return dp[Wx][Wy];
	dp[Wx][Wy] = part(Wx-A[i], Wy, A, i-1) | part(Wx, Wy-A[i], A, i-1) | part(Wx, Wy, A, i-1);
	return dp[Wx][Wy];
}
int partition3(vector<int> &A)
{
	long long sum = 0;
	for (int i =0; i<A.size(); i++)
	{
		sum += A[i];
	}
	if (sum % 3 != 0)
		return 0;
	return (part(sum/3, sum/3, A, A.size()-1));

}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  memset(dp, -1, sizeof(dp));
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
