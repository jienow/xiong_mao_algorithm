#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int N = 2010, M = 10010;
int h[N], e[M], ne[M], w[M], idx;
int dist[N], cnt[N];
bool st[N];
int n, m;
void add(int x, int y, int z) {
	e[idx] = y, w[idx] = z, ne[idx] = h[x], h[x] = idx++;
}
bool spfa() {
	queue<int> que;
	for (int i = 1; i <= n; i++) {
		que.push(i);
		st[i] = true;
	}
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		st[u] = false;
		for (int i = h[u]; i != -1; i = ne[i]) {
			int j = e[i];
			if (dist[j] > dist[u] + w[i]) {
				dist[j] = dist[u] + w[i];
				cnt[j] = cnt[u] + 1;
				if (cnt[j] >= n) return true;
				if (!st[j]) {
					que.push(j);
					st[j] = true;
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
	if (spfa()) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}