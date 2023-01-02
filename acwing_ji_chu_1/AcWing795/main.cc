#include <iostream>
using namespace std;
const int N = 100010;
int f[N];
int n, m;
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		f[i] = f[i-1] + a;
	}
	while (m--) {
		int l, r; cin >> l >> r;
		cout << f[r] - f[l - 1] << endl;
	}


	return 0;
}