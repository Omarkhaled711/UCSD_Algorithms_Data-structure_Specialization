#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>

using namespace std;
struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);

    std::stack <Bracket> br;
	unordered_map<char, char>m;
	m[')'] = '(';
	m[']'] = '[';
	m['}'] = '{';
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{'){
			br.push(Bracket(next,position));
        }

        if (next == ')' || next == ']' || next == '}') {
			if (br.empty())
			{
				cout<<1+position;
				return (0);
			}
			if (br.top().type != m[next])
			{
				cout<<1+position;
				return (0);
			}
			else
			{
				br.pop();
			}
        }
    }
	if (!br.empty())
	{
		while(br.size() > 1)
		{
			br.pop();
		}
		cout<<br.top().position + 1;
		return (0);
	}
	cout<< "Success";
    return 0;
}
