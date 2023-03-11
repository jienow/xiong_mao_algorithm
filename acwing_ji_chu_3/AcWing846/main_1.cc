#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int h[N], e[2 * N], ne[2 * N], idx;
int n;
int res = N;
void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int dfs(int u, int father) {
	int sum = 0, ret = 0;
	for (int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i];
		if (j == father) continue;
		int num = dfs(j, u);
		ret = max(num, ret);
		sum += num;
	}
	ret = max(ret, n - sum - 1);
	res = min(ret, res);
	return sum + 1;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	memset(h, -1, sizeof h);
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		add(a, b);
		add(b, a);
	}
	dfs(1, -1);
	cout << res;
	return 0;
}