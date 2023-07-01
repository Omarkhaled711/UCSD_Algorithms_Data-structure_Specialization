#include <bits/stdc++.h>

int get_change(int m) {
	int coins10 = m / 10;
	int coins5 = (m % 10) / 5;
	int coins1 = (m % 10) % 5;
	return coins10 + coins5 + coins1;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
