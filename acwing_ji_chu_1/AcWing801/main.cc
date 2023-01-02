#include <iostream>
using namespace std;
int n;
int func(int num) {
	int res = 0;
	while (num) {
		res += num & 1;
		num >>= 1;
	}
	return res;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n;

	while (n--)
	{
		int num; cin >> num;
		cout << func(num) << " ";
	}

	return 0;
}