#include <iostream>
using namespace std;
bool is_prime(int n) {
	if (n == 1) return false;
	for (int i = 2; i <= n / i; i++)
		if (n % i == 0)
			return false;
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int v; cin >> v;
		if (is_prime(v))cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}