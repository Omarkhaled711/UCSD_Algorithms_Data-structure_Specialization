#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

typedef unsigned long long ull;

int const prime1 =  1e9 + 7;
int const prime2 = 1e9 + 9;
int x = 31;

void precompute_hash(string &s, vector<int> &hash_vector1, vector<int> &hash_vector2, int prime1, int prime2)
{
	hash_vector1[0] = 0;
	hash_vector2[0] = 0;
	for (int i = 1; i<hash_vector1.size(); i++)
	{
		hash_vector1[i] = ((((ull)x * hash_vector1[i - 1])%prime1) + s[i - 1])%prime1;
		hash_vector2[i] = ((((ull)x * hash_vector2[i - 1])%prime2) + s[i - 1])%prime2;
	}
}
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
void precompute_pow_len(int length, vector<int> &pow1, vector<int> &pow2)
{
	for (int i = 0; i <= length; i++)
	{
		pow1[i] = power(x, i, prime1);
		pow2[i] = power(x, i, prime2);
	}
}
int get_hash(int prime, int a, int l, vector<int> &hash_vector, vector<int> &pow)
{
	ull x_pow_len = pow[l];

	int hash= (hash_vector[a + l] - ((x_pow_len * hash_vector[a]) % prime) + prime) % prime;
	return hash;
}

void is_matching(int left_text, int left_pattern, string &text, string &pattern,
	int right_text, int right_pattern, vector<int> &hash_vector_text1, vector<int> &hash_vector_text2,
	vector<int> &hash_vector_pattern1,vector<int> &hash_vector_pattern2, int &count, int k,
	vector<int> &pow1, vector<int> &pow2)
{
	if (left_text >= right_text)
		return;

	if (count > k)
		return;

	int hash_text1 = get_hash(prime1, left_text, right_text - left_text, hash_vector_text1, pow1);
	int hash_text2 = get_hash(prime2, left_text, right_text - left_text, hash_vector_text2, pow2);
	int hash_pattern1 = get_hash(prime1, left_pattern, right_pattern - left_pattern, hash_vector_pattern1, pow1);
	int hash_pattern2 = get_hash(prime2, left_pattern, right_pattern - left_pattern, hash_vector_pattern2, pow2);

	if(hash_text1 == hash_pattern1 && hash_text2 == hash_pattern2)
		return;
	else if (left_text == right_text - 1)
	{
		count++;
		return;
	}
	int mid_text = left_text + (right_text - left_text)/2;
	int mid_pattern = left_pattern + (right_pattern - left_pattern)/2;
	is_matching(left_text, left_pattern, text, pattern, mid_text, mid_pattern,
		hash_vector_text1, hash_vector_text2,  hash_vector_pattern1, hash_vector_pattern2, count, k, pow1, pow2);
	is_matching(mid_text, mid_pattern, text, pattern, right_text, right_pattern,
		hash_vector_text1, hash_vector_text2,  hash_vector_pattern1, hash_vector_pattern2,count, k, pow1, pow2);

}
vector<int> solve(int k, string &text, string &pattern) {
	vector<int> pos, hash_vector_text1(text.size() + 1),  hash_vector_text2(text.size() + 1) ,hash_vector_pattern1(pattern.size() + 1), hash_vector_pattern2(pattern.size() + 1);
	int length = pattern.size();
	vector<int> pow1(length + 1), pow2(length + 1);

	precompute_hash(text, hash_vector_text1, hash_vector_text2, prime1, prime2);
	precompute_hash(pattern, hash_vector_pattern1, hash_vector_pattern2, prime1, prime2);
	precompute_pow_len(length, pow1, pow2);

	for (int i = 0; i <= text.size() - length; i++)
	{
		int count = 0;
		is_matching(i, 0, text, pattern, i + length, length, hash_vector_text1, hash_vector_text2,
			hash_vector_pattern1, hash_vector_pattern2, count, k, pow1, pow2);
		if (count <= k)
			pos.push_back(i);

	}
	return pos;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int k;
	string t, p;
	while (cin >> k >> t >> p) {
		auto a = solve(k, t, p);
		cout << a.size();
		for (int x : a)
			cout << " " << x;
		cout << "\n";
	}
}
