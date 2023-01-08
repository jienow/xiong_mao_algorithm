#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int N = 2010, M = 10010;
int h[N], ne[M], e[M], w[M], idx;
int cnt[N], n, m, dist[N];
bool st[N];
void add(int a, int b, int c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
bool spfa() {
	queue<int> que;
	for (int i = 1; i <= n; i++) {
		que.push(i);
		st[i] = true;
	}
	while (!que.empty()) {
		int u = que.front(); que.pop();
		st[u] = false;
		for (int i = h[u]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > dist[u] + w[i]) {
				dist[j] = dist[u] + w[i];
				cnt[j] = cnt[u] + 1;
				if (cnt[j] >= n) return true;
				if (!st[j]) {
					st[j] = true;
					que.push(j);
				}
			}
		}
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	memset(h, -1, sizeof h);
	for (int i = 0; i < m; i++) {
		int x, y, z; cin >> x >> y >> z;
		add(x, y, z);
	}
	if (spfa())puts("Yes");
	else puts("No");
	return 0;
}
