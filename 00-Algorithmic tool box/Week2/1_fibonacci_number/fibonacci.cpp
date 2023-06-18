#include <iostream>
#include <vector>
#include <cassert>

long long fibonacci_fast(int n) {
	std::vector<long long> Fib(n+1);
	Fib[0] = 0;
	Fib[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		Fib[i] = Fib[i - 1] + Fib [i - 2];
	}
    return Fib[n];
}
int main() {
    int n = 0;
    std::cin >> n;
    std::cout << fibonacci_fast(n) << '\n';
    return 0;
}
