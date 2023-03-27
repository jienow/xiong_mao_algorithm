#include <iostream>
using namespace std;
const int N = 110;
int f[N][N];
int main() {
	ios::sync_with_stdio(false);
	int n; cin >> n;
	while (n--) {
		int n, m; cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> f[i][j];
				f[i][j] += max(f[i][j - 1], f[i - 1][j]);
			}
		}
		cout << f[n][m] << endl;
	}
	return 0;
}