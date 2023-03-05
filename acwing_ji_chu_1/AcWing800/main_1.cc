#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int f[N], g[N];
int n, m, x;
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> x;
	for (int i = 1; i <= n; i++) cin >> f[i];
	for (int i = 1; i <= m; i++) cin >> g[i];
	
	for (int i = 1,j = m; i <= n; i++) {
		while (j >= 1 && f[i] + g[j] >= x) {
			if (f[i] + g[j] == x) {
				cout << i - 1 << " " << j - 1 << endl;
				return 0;
			}
			j--;
		}
	}

	return 0;
}