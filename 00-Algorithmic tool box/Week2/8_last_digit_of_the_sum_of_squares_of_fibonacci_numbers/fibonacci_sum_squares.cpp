#include <iostream>
#include <vector>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;
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
		pSumFib.push_back(((fib[index] * fib[index]) % 10 + pSumFib[index - 1]) %10);
	}
	return (n/(fib.size() -1) * pSumFib[fib.size() - 2] + pSumFib[n%(fib.size() - 1)]) %10;

}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_naive(n);
}
