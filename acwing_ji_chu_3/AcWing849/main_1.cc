#include <iostream>
using namespace std;
const int N = 510;
int g[N][N], n, m;
int dist[N];
bool st[N];
int djsgra() {
	dist[1] = 0;
	for (int i = 0; i < n; i++) {
		int t = -1;
		for (int j = 1; j <= n; j++)
			if (!st[j] && (t == -1 || dist[j] < dist[t]))
				t = j;
		st[t] = true;
		if (dist[t] == 0x3f3f3f3f)	return -1;
		for (int j = 1; j <= n; j++)
			dist[j] = min(dist[j], dist[t] + g[t][j]);
	}
	if (dist[n] == 0x3f3f3f3f) return -1;
	else return dist[n];
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;

	memset(dist, 0x3f, sizeof dist);
	memset(g, 0x3f, sizeof g);
	while (m--) {
		int x, y, z; cin >> x >> y >> z;
		g[x][y] = min(g[x][y], z);
	}
	cout << djsgra() << endl;

	return 0;
}