#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int a = 0, b = 1, t;
	for (int i = 1; i <= n; i++) {
		cout << a << " ";
		t = b;
		b = a + b;
		a = t;
	}
	return 0;
}