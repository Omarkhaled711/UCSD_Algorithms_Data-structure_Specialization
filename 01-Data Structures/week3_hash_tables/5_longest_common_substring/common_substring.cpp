#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int const prime1 =  1e9 + 7;
int const prime2 = 1e9 + 9;
int x = 31;

struct Answer {
	size_t i, j, len;
};

int power(int num, int y, int p)
{
	int res = 1;  
	while (y > 0)
	{
	    if (y % 2 == 1)
	        res = (res*(ull)num) % p;
	    y = y>>1;
	    num = ((ull)num*num) % p;
	}
	return res % p;
}
int poly_hash(string &s, int prime)
{
    ull hash = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        hash = (((hash * x) % prime) + s[i]) % prime;
    }
    return hash;
}

void create_substrings(const string &s, int length, unordered_map<int, pair<bool,int>> &hash_map1, unordered_map<int, bool> &hash_map2)
{
	int i = s.size() - length;
    string s_sub_str = s.substr(i, s.size());
    int last_calc1 = poly_hash(s_sub_str, prime1);
    int last_calc2 = poly_hash(s_sub_str, prime2);
    //cout << last_calc1 << " " << last_calc2 <<endl;
    hash_map1[last_calc1].first = 1;
    hash_map1[last_calc1].second = i;
    hash_map2[last_calc2] = 1;
    ull x_pow_len_1 = power(x, length, prime1);
	ull x_pow_len_2 = power(x, length, prime2);
	for (i = s.size() - length - 1; i >= 0; i--)
	{
		int current;
		current = ((((x * (ull)last_calc1) % prime1) + s[i] - ((x_pow_len_1 * s[i + length]) % prime1)) + prime1)%prime1;
		hash_map1[current].first = 1;
		hash_map1[current].second = i;
		last_calc1 = current;
		current = ((((x * (ull)last_calc2) % prime2) + s[i] - ((x_pow_len_2 * s[i + length]) % prime2)) + prime2)%prime2;
		hash_map2[current] = 1;
		last_calc2 = current;
	}
}
bool check_substring(const string &t, int length, unordered_map<int, pair<bool, int>> &hash_map1, unordered_map<int, bool> &hash_map2, Answer &ans)
{
	int i = t.size() - length;
    string t_sub_str = t.substr(i, t.size()); 
    int last_calc1 = poly_hash(t_sub_str, prime1);
    int last_calc2 = poly_hash(t_sub_str, prime2);
    //cout<< "hash_map " << hash_map1[last_calc1]<< " "<<hash_map2[last_calc2] << endl;
    if (hash_map1[last_calc1].first && hash_map2[last_calc2])
    {
    	ans.i = hash_map1[last_calc1].second;
    	ans.j = i;
    	ans.len = length;
    	return 1;
    }
    ull x_pow_len_1 = power(x, length, prime1);
	ull x_pow_len_2 = power(x, length, prime2);
    for (i = t.size() - length - 1; i >= 0; i--)
	{
		//cout << "Hi\n";
		int current;
		current = ((((x * (ull)last_calc1) % prime1) + t[i] - ((x_pow_len_1 * t[i + length]) % prime1)) + prime1)%prime1;
		last_calc1 = current;
		current = ((((x * (ull)last_calc2) % prime2) + t[i] - ((x_pow_len_2 * t[i + length]) % prime2)) + prime2)%prime2;
		last_calc2 = current;
		if (hash_map1[last_calc1].first && hash_map2[last_calc2])
    	{
    		ans.i = hash_map1[last_calc1].second;
    		ans.j = i;
    		ans.len = length;
    		return 1;
    	}
	}
	return 0;
}
Answer solve(const string &s, const string &t) {
	Answer ans = {0, 0, 0};
	int left = 1, right = min(s.size(), t.size());
	while(left <= right)
	{
		int mid = left + (right - left)/2;
		unordered_map<int, pair<bool, int>> hash_map1;
		unordered_map<int, bool> hash_map2;
		vector<int> hash_values(max(s.size(), t.size()));
		create_substrings(s, mid, hash_map1, hash_map2);
		bool flag = check_substring(t, mid, hash_map1, hash_map2, ans);
		if (flag)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	string s, t;
	while (cin >> s >> t) {
		auto ans = solve(s, t);
		cout << ans.i << " " << ans.j << " " << ans.len << "\n";
	}
}
