#include <iostream>
#include <cstring>
using namespace std;
const int N = 510, M = 10010;
struct edge {
	int a, b, w;
}edges[M];
int dist[N], backup[N], n, m, k;
void bellman_ford() {
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	for (int i = 0; i < k; i++) {
		memcpy(backup, dist, sizeof dist);
		for (int j = 0; j < m; j++) {
			int x = edges[j].a, y = edges[j].b, w = edges[j].w;
			dist[y] = min(dist[y], backup[x] + w);
		}
	}
	if (dist[n] > 0x3f3f3f3f / 2) cout << "impossible" << endl;
	else cout << dist[n] << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int a, b, w; cin >> a >> b >> w;
		edges[i] = { a,b,w };
	}
	bellman_ford();
	return 0;
}