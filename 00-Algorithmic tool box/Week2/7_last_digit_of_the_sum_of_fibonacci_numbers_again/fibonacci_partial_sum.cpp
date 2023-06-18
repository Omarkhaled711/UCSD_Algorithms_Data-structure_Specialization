#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
	std::vector<int> pSumFib, fib;
	pSumFib.push_back(0);
	pSumFib.push_back(1);
	fib.push_back(0);
	fib.push_back(1);
	for (int index = 2; ;index++)
	{
		long long current = (fib[index - 1] % 10 + fib[index - 2] %10)%10;
		if (current == 1 && fib[index - 1] == 0)
		{
			break;
		}
		fib.push_back(current);
		pSumFib.push_back((fib[index] + pSumFib[index - 1]) %10);
	}
	long long num2 = (to/(fib.size() -1) * pSumFib[fib.size() - 2] + pSumFib[to%(fib.size() - 1)]) %10;
	long long num1 = ((from-1)/(fib.size() -1) * pSumFib[fib.size() - 2] + pSumFib[(from - 1)%(fib.size() - 1)]) %10;
	if (from == 0)
		num1 = 0;
	return (num2 - num1 + 10) % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
}
