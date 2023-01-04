#include <iostream>
#include <stack>
using namespace std;
const int N = 1e5 + 10;
stack<int> stk;
int n;
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	while (n--) {
		int num; cin >> num;
		while (!stk.empty() && stk.top() >= num) stk.pop();
		if (stk.empty()) cout << "-1" << " ";
		else cout << stk.top() << " ";
		stk.push(num);
	}

	return 0;
}