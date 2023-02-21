#include <iostream>
#include <cstring>
using namespace std;
const int N = 510, INF = 0x3f3f3f3f;
int g[N][N], dist[N];
bool st[N];
int n, m;
int prim() {
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	int res = 0;
	for (int i = 0; i < n; i++) {
		int t = 0;
		for (int j = 1; j <= n; j++)
			if (!st[j] && (t == 0 || dist[j] < dist[t]))
				t = j;
		if (dist[t] == INF) return INF;
		res += dist[t];
		for (int j = 1; j <= n; j++) dist[j] = min(dist[j], g[t][j]);
		st[t] = true;
	}
	return res;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	memset(g, 0x3f, sizeof g);
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		g[u][v] = g[v][u] = min(g[u][v], w);
	}
	int t = prim();
	if (t == INF)cout << "impossible" << endl;
	else cout << t << endl;

	return 0;
}