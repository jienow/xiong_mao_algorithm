#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;
unordered_map<char, int> pr{ {'*',2},{'/',2},{'+',1},{'-',1} };
stack<int> nums;
stack<char> op;
void eval() {
	int b = nums.top(); nums.pop();
	int a = nums.top(); nums.pop();
	char c = op.top(); op.pop();
	int res = 0;
	if (c == '+')
		res = a + b;
	else if (c == '-')
		res = a - b;
	else if (c == '*')
		res = a * b;
	else if (c == '/')
		res = a / b;
	nums.push(res);
}
int main() {
	ios::sync_with_stdio(false);
	string str; cin >> str;
	for (int i = 0; i < str.size(); i++) {
		char c = str[i];
		if (isdigit(c)) {
			int x = 0, j = i;
			while (j < str.size() && isdigit(str[j]))
				x = x * 10 + (str[j++] - '0');
			i = j - 1;
			nums.push(x);
		}
		else if (c == '(')
			op.push(c);
		else if (c == ')') {
			while (op.size() && op.top() != '(')
				eval();
			op.pop();
		}
		else {
			while (op.size() && op.top() != '(' && pr[op.top()] >= pr[c])
				eval();
			op.push(c);
		}
	}
	while (op.size()) eval();
	cout << nums.top();
	return 0;
}