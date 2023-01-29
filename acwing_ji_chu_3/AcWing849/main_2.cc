#include <iostream>
#include <cstring>
using namespace std;
const int N = 510, M = 1e5 + 10;
int g[N][N], d[N];
bool st[N];
int n, m;
int dijkstra() {
	memset(d, 0x3f, sizeof d);
	d[1] = 0;
	for (int i = 1; i <= n; i++) {
		int t = -1;
		for (int j = 1; j <= n; j++)
			if (!st[j] && (t == -1 || d[j] < d[t]))
				t = j;
		st[t] = true;
		for (int j = 1; j <= n; j++)
			d[j] = min(d[j], d[t] + g[t][j]);
	}
	if (d[n] == 0x3f3f3f3f) return -1;
	else return d[n];
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	memset(g, 0x3f, sizeof g);
	for (int i = 0; i < m; i++) {
		int x, y, z; cin >> x >> y >> z;
		g[x][y] = min(g[x][y], z);
	}
	cout << dijkstra();

	return 0;
}