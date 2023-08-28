#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef unsigned long long ull;

int const prime1 =  1e9 + 7;
int const prime2 = 1e9 + 9;
int x = 31;

class Solver {
	string s;
	vector<int>hash_vector1, hash_vector2;
public:
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
 
	void precompute_hash(string &s, vector<int> &hash_vector, int prime)
	{
		hash_vector[0] = 0;
		for (int i = 1; i<hash_vector.size(); i++)
		{
			hash_vector[i] = ((((ull)x * hash_vector[i - 1])%prime) + s[i - 1])%prime;
		}
	}
	Solver(string s) : s(s), hash_vector1(s.size() + 1), hash_vector2(s.size() + 1)
	{
		precompute_hash(s, hash_vector1, prime1);
		precompute_hash(s, hash_vector2, prime2);
	}
	bool ask(int a, int b, int l) {
		ull x_pow_len_1 = power(x, l, prime1);
		ull x_pow_len_2 = power(x, l, prime2);

		int hash1_a = (hash_vector1[a + l] - ((x_pow_len_1 * hash_vector1[a]) % prime1) + prime1) % prime1;
		int hash2_a = (hash_vector2[a + l] - ((x_pow_len_2 * hash_vector2[a]) % prime2) + prime2) % prime2;
		int hash1_b = (hash_vector1[b + l] - ((x_pow_len_1 * hash_vector1[b]) % prime1) + prime1) % prime1;
		int hash2_b = (hash_vector2[b + l] - ((x_pow_len_2 * hash_vector2[b]) % prime2) + prime2) % prime2;
		return ((hash1_a == hash1_b) && (hash2_a == hash2_b));
	}
};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	string s;
	int q;
	cin >> s >> q;
	Solver solver(s);
	for (int i = 0; i < q; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		cout << (solver.ask(a, b, l) ? "Yes\n" : "No\n");
	}
}
