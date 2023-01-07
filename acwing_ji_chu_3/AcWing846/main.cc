#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;
int h[N], e[N * 2], ne[N * 2], idx;
int n,res = 1e9;
void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int dfs(int u, int father) {
	int all = 0, maxv = 0;
	for (int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];
		if (j == father) continue;
		int num = dfs(j,u);
		maxv = max(maxv, num);
		all += num;
	}
	all += 1;
	maxv = max(maxv, n - all);
	res = min(res, maxv);
	return all;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	memset(h, -1, sizeof h);
	for (int i = 1; i < n; i++){
		int a, b; cin >> a >> b;
		add(a, b), add(b, a);
	}
	dfs(1, 0);
	cout << res << endl;
	return 0;
}