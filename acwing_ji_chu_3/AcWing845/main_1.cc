#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;
int h[N], e[N * 2], ne[N * 2], idx;
int n;
int res = 1e8;
void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int dfs(int u,int father) {
	int maxn = 0, cnt = 0;
	for (int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i];
		if (j == father)continue;
		int res = dfs(j,u);
		maxn = max(maxn, res);
		cnt += res;
	}
	maxn = max(maxn, n - cnt - 1);
	res = min(res, maxn);
	return cnt + 1;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	memset(h, -1, sizeof h);
	for (int i = 0; i < n-1; i++) {
		int a, b; cin >> a >> b;
		add(a, b), add(b, a);
	}
	dfs(1,-1);
	cout << res << endl;

	return 0;
}