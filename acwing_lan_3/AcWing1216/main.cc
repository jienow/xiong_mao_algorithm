#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	int n; cin >> n;
	int sum = n;
	while (n >= 3) {
		sum +=  n / 3;
		n = n / 3 + n % 3;
	}
	cout << sum << endl;
	return 0;
}