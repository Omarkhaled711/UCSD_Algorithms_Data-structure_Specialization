#include <iostream>

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return (gcd(b, a%b));
}

int main() {
  int a, b;
  std::cin >> a >> b;
  if(a >= b)
	std::cout << gcd(a, b) << std::endl;
  else
	std::cout << gcd(b, a) << std::endl;
  return 0;
}
