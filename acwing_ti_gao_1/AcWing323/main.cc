#include <iostream>
using namespace std;
const int N = 1510;
int f[N][2], h[N], e[N], ne[N], idx;
int n, m;
bool st[N];
void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void dfs(int u) {
	f[u][0] = 0, f[u][1] = 1;
	for (int i = h[u]; ~i; i = ne[i]) {
		int j = e[i];
		dfs(j);
		f[u][0] += f[j][1];
		f[u][1] += min(f[j][0], f[j][1]);
	}
}
int main() {
	while (cin >> n) {
		memset(h, -1, sizeof h);
		idx = 0;
		memset(st, 0, sizeof st);
		for (int i = 0; i < n; i++) {
			int idx, cnt;
			scanf("%d:(%d)", &idx, &cnt);
			while (cnt--) {
				int ver; cin >> ver;
				add(idx, ver);
				st[ver] = true;
			}
		}
		int root = 0;
		while (st[root]) root++;
		dfs(root);
		cout << min(f[root][1], f[root][0]) << endl;
	}
	return 0;
}