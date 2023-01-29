#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int N = 1e5 + 10;
int h[N], e[N], ne[N], idx;
int d[N];
int n, m;
void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int bfs() {
	d[1] = 0;
	queue<int> que;
	que.push(1);

	while (!que.empty()) {
		int u = que.front();
		que.pop();
		for (int i = h[u]; i != -1; i = ne[i]) {
			int j = e[i];
			if (d[j] == -1) {
				d[j] = d[u] + 1;
				que.push(j);
			}
		}
	}
	return d[n];
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	memset(h, -1, sizeof h);
	memset(d, -1, sizeof d);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		add(a, b);
	}
	cout << bfs();
	return 0;
}