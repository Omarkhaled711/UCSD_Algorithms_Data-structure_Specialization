#include <iostream>
#include <vector>

long long get_fibonacci_huge(long long n, long long m) {
    if (n <= 1)
        return n;
	int index = 2;
	std::vector<long long> v;
    v.push_back(0);
	v.push_back(1);
	while (1)
	{
        long long current = (v[index - 1] % m + v[index - 2] %m) %m;
		if (current == 1 && v[index - 1] ==0)
		{
			break;
		}
		v.push_back(current);
		index++;
    }
    return v[n % (v.size() -1 )];
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge(n, m) << '\n';
}
