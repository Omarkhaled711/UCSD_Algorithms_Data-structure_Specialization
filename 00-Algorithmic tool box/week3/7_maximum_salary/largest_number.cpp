#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

bool compare(string &s1, string &s2)
{
	string s_temp1 = s1;
	string s_temp2 = s2;
	int sz1 = s1.size(), sz2 = s2.size();
	if (sz1>sz2)
	{
		for (int i = sz2; i<sz1; i++)
		{
			s_temp2 += s_temp2[0];
		}
	}
	else if (sz2 > sz1)
	{
		for (int i = sz1; i<sz2; i++)
		{
			s_temp1 += s_temp1[0];
		}
	}
	if (s_temp1 == s_temp2)
	{
		char max_l = s_temp1[0];
		int max_l_index = 0;
		for (int i = 1; i<s_temp1.size();i++)
		{
			if (s_temp1[i] >= max_l)
			{
				max_l = s_temp1[i];
				max_l_index = i;
			}
		}
		if (max_l_index != 0 && max_l_index != (s_temp1.size() - 1))
		{
			return sz1 < sz2;
		}
		return sz1 > sz2;
	}
	return s_temp1 > s_temp2;
}
string largest_number(vector<string> a) {
	sort(a.begin(), a.end(), compare);
	string ans = a[0];
	for (int i = 1; i< a.size(); i++)
	{
		ans += a[i];
	}
	return ans;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
