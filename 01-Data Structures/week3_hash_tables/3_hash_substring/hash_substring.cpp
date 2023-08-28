#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
typedef unsigned long long ull;

int const prime = 1e9 + 7;
int x = 31;

struct Data {
    string pattern, text;
};
int poly_hash(string &s)
{
    ull hash = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        hash = (((hash * x) % prime) + s[i]) % prime;
    }
    return hash;
}
void precompute_hash(string &t, int length, vector<int> &hash_vector)
{
    int i = t.size() - length;
    string t_sub_str = t.substr(i, t.size());
    hash_vector[i] = poly_hash(t_sub_str);
    ull x_pow_len = 1;
    for (i = 0; i < length; i++)
    {
        x_pow_len = (x_pow_len * x) % prime;
    }
    for (i = t.size() - length - 1; i >= 0; i--)
    {
        hash_vector[i] = ((((x * (ull)hash_vector[i + 1]) % prime) + t[i] - ((x_pow_len * t[i + length]) % prime)) + prime)%prime;
    }
}
Data read_input() {
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}
bool is_equal_str(string const &t, string &s, int start)
{
    for (int j = 0; j < s.size(); j++)
    {
        if(t[j + start] != s[j])
            return 0;
    }
    return 1;
}
void print_occurrences(const std::vector<int>& output) {
    for (size_t i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}

std::vector<int> get_occurrences(Data& input) {
    string& s = input.pattern, t = input.text;
    std::vector<int> ans;
    int pattern_hash = poly_hash(s);
    vector<int> hash_vector(t.size() - s.size() + 1);
    precompute_hash(t, s.size(), hash_vector);
    for (size_t i = 0; i + s.size() <= t.size(); ++i)
    {
        if (hash_vector[i] == pattern_hash)
        {
            if(is_equal_str(t, s, i))
                ans.push_back(i);
        }
    }
    return ans;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    Data input = read_input();
    print_occurrences(get_occurrences(input));
    return 0;
}
