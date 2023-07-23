#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <climits>

using namespace std;

/**
 * Solution:
 * Suppose we have a problem like this: num1 [op1] num2 [op2] num3 ... [op_n] num_n,
 * where op1, op2, ..., op_n are either +, -, or *. 
 * To maximize the output, we can consider all possible permutations of adding parentheses. 
 * For example: (num1 [op1] num2) [op2] (num3 ... [op_n] num_n).
 * We can then solve each of the permutations recursively, compare the results, and choose the one with the highest output.
 * We can notice that eventually, the problem reduces to an operation between two numbers: numFirst [op2] num3_to_n.
 * In this example, numFirst is (num1 [op1] num2), and num3_to_n is (num3 ... [op_n] num_n).
 * For the * operation to be maximum, the two operands have to be as big as possible,
 * or as small as possible (since -ve * -ve = +ve).
 * For the + operation to be maximum, the two operands have to be as big as possible.
 * For the - operation to be maximum, the first operand has to be as big as possible,
 * and the second operand has to be as small as possible.
 * Therefore, for the expression (numFirst [op2] num3_to_n) to be maximum, numFirst and num3_to_n
 * have to be either the maximum possible value we can get by solving the recursive subproblems or the minimum ones.
 * We can create a table to keep track of the maximum values obtained from solving the * smaller problems and another table to keep track of the minimum values. 
 * We can use these tables to compute the answer without recalculating anything.
 */
long long dpMin[20][20];
long long dpMax[20][20];

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}
void minMax(int i, int j, vector<char> &ops)
{
	/* calculating the min and max value for the 2 tables */
	if (i == j)
		return;
	long long minNum = LLONG_MAX;
	long long maxNum = LLONG_MIN;
	vector<long long> nums(4);
	for (int k = i; k < j; k++)
	{
		nums[0] = eval(dpMin[i][k], dpMin[k+1][j], ops[k]);
		nums[1] = eval(dpMin[i][k], dpMax[k+1][j], ops[k]);
		nums[2] = eval(dpMax[i][k], dpMin[k+1][j], ops[k]);
		nums[3] = eval(dpMax[i][k], dpMax[k+1][j], ops[k]);
		minNum = min(minNum, min(nums[0], min(nums[1], min(nums[2], nums[3]))));
		maxNum = max(maxNum, max(nums[0], max(nums[1], max(nums[2], nums[3]))));
	}
	dpMin[i][j] = minNum;
	dpMax[i][j] = maxNum;
}

long long get_maximum_value(const string &exp) {
	int n = (exp.size() - 1)/2;
	int j = 0;
	vector<char> ops;
	for (int i = 0; i <= n; i++)
	{
		/* The diagonal of the matrix is our base case
		 * Because this meanse we are considering a zero range, which means that
		 * we are considering only one number, and we need at least 2 numbers
		 * to preform an operation
		 */
		dpMin[i][i] = (exp[j] - '0');
		dpMax[i][i] = (exp[j] - '0');
		j += 2;
	}
	for (int i = 1; i<exp.size(); i+=2)
	{
		/* keeping a vector of chars for operations */
		ops.push_back(exp[i]);
	}
	for (int s = 0; s <= n; s++)
	{
		for (int i = 0; i <= (n - s); i++)
		{
			j = i + s;
			minMax(i, j, ops);
		}
	}
  return dpMax[0][n];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
