#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 510, INF = 0x3f3f3f3f;
int g[N][N];
int dist[N];
bool s[N];
int n, m;
int prim() {
	memset(dist, 0x3f, sizeof dist);
	int res = 0;
	for (int i = 0; i < n; i++) {
		int t = -1;
		for (int j = 1; j <= n; j++)
			if (!s[j] && (t == -1 || dist[t] > dist[j]))
				t = j;
		if (i && dist[t] == INF) return INF;
		if (i) res += dist[t];
		for (int j = 1; j <= n; j++)dist[j] = min(dist[j], g[t][j]);
		s[t] = true;
	}
	return res;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	memset(g, 0x3f, sizeof g);
	for (int i = 0; i < m; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		g[a][b] = g[b][a] = min(g[a][b], w);
	}
	int t = prim();
	if (t == INF) cout << "impossible" << endl;
	else cout << t << endl;
	return 0;
}