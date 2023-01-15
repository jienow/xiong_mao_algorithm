#include <iostream>
using namespace std;
const int N = 110;
int w[N], n;
int f[N];
int main() {
	ios::sync_with_stdio(false);

	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++)cin >> w[i];

		int res = 0;
		for (int i = 1; i <= n; i++) {
			f[i] = 1;
			for (int j = 1; j < i; j++) {
				if (w[i] > w[j])
					f[i] = max(f[i], f[j] + 1);
			}
			res = max(res, f[i]);
		}
		for (int i = n; i >= 1; i--) {
			f[i] = 1;
			for (int j = n; j > i; j--)
				if (w[i] > w[j])
					f[i] = max(f[i], f[j] + 1);
			res = max(res, f[i]);
		}
		cout << res << endl;


	}



	return 0;
}