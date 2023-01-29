#include <iostream>
#include <queue>
using namespace std;
const int N = 1e5 + 10;
int h[N], e[N], ne[N], w[N], idx;
int dist[N];
bool st[N];
int n, m;
void add(int a, int b, int c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
int spfa() {
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	queue<int> que;
	que.push(1);
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		st[u] = true;
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
	return dist[n];
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;

	memset(h, -1, sizeof h);
	for (int i = 0; i < m; i++) {
		int x, y, z; cin >> x >> y >> z;
		add(x, y, z);
	}
	int t = spfa();
	if (t == 0x3f3f3f3f) cout << "impossible" << endl;
	else cout << t << endl;

	return 0;
}