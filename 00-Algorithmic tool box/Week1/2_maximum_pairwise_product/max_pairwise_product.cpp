#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = INT_MIN;
    int n = numbers.size();
	int max1 = INT_MIN, max2 = INT_MIN, min1 = INT_MAX, min2 = INT_MAX;

    for (int first = 0; first < n; ++first) {
		if (numbers[first] >= max1)
		{
			max2 = max1;
			max1 = numbers[first];
		}
		else if (numbers[first] > max2)
		{
			max2 = numbers[first];
		}
		if (numbers[first] <= min1)
		{
			min2 = min1;
			min1 = numbers[first];
		}
		else if (numbers[first] < min2)
		{
			min2 = numbers[first];
		}
    }
	max_product = std::max((long long )max1 * max2, (long long)min1 * min2);
    return max_product;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
