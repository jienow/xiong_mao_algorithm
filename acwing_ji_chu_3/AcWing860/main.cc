#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;
int h[N], e[N * 2], ne[N * 2], idx;
int color[N], n, m;
void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
bool dfs(int u, int c) {
	color[u] = c;
	for (int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i];
		if (!color[j]) {
			if (!dfs(j, 3 - c)) return false;
		}
		else if (color[j] == c) return false;
	}
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	memset(h, -1, sizeof h);
	for (int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		add(u, v), add(v, u);
	}
	bool flag = true;
	for (int i = 1; i <= n; i++)
		if (!color[i]) {
			if (!dfs(i, 1)) {
				flag = false;
				break;
			}
		}
	if (flag) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}