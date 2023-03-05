#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int f[N], g[N];
int n, m;
int main() {
	ios::sync_with_stdio(false);
	cin >> m >> n;
	for (int i = 1; i <= m; i++) cin >> g[i];
	for (int j = 1; j <= n; j++) cin >> f[j];
	int i,j;
	for (i = 1, j = 1; i <= n; i++) {
		if (j <= m && f[i] == g[j]) j++;
	}
	if (j == m + 1) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}