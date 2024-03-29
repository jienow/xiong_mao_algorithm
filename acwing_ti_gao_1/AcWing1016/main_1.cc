#include <iostream>
using namespace std;
const int N = 1010;
int f[N], a[N], n;
int main() {
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	int res = 0;
	for (int i = 1; i <= n; i++) {
		f[i] = a[i];
		for (int j = 1; j < i; j++)
			if (a[i] > a[j])
				f[i] = max(f[i], f[j] + a[i]);
		res = max(res, f[i]);
	}
	cout << res << endl;
	return 0;
}