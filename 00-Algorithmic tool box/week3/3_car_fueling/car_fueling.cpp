#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
	int i = 0, ans = 0, prev = 0;

	while(dist > 0 && i < stops.size())
	{
		if ((dist - tank) <= 0)
		{
			dist -= tank;
			break;
		}
		if ((prev + tank) >= stops[i])
		{
			if ((i == stops.size() - 1) || stops[i + 1] > (prev + tank))
			{
				dist -= (stops[i] - prev);
				ans++;
				prev = stops[i];
			}
			i++;
		}
		else
		{
			break;
		}
	}
	if (prev == stops[stops.size() - 1])
	{
		dist -= tank;
	}
	if (dist <= 0)
	{
		return ans;
	}
	return -1;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
