/*
*    spfa算法其实是另一种的dijkstra算法，只不过是实时更新没有集合的概念，拿到一个新的点就会去更新
*/

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;
int h[N], w[N], e[N], ne[N], idx;
int dist[N], n, m;
bool st[N];
void add(int a, int b, int c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
void spfa() {
	queue<int> que;
	que.push(1);
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	st[1] = true;

	while (!que.empty()) {
		int u = que.front(); que.pop();
		st[u] = false;
		for (int i = h[u]; i != -1; i = ne[i]) {
			int j = e[i];
			if (dist[j] > dist[u] + w[i]) {
				dist[j] = dist[u] + w[i];
				if (!st[j]) {
					que.push(j);
					st[j] = true;
				}
			}
		}
	}
	if (dist[n] == 0x3f3f3f3f) cout << "impossible" << endl;
	else cout << dist[n] << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	memset(h, -1, sizeof h);
	for (int i = 0; i < m; i++) {
		int x, y, z; cin >> x >> y >> z;
		add(x, y, z);
	}
	spfa();
	return 0;
}
