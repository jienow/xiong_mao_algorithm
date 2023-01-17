#include <iostream>
using namespace std;
const int N = 55;
int w[N], up[N], down[N], n;
bool dfs(int depth, int u, int su, int du) {
	if (su + du > depth) return false;
	if (u == n) return true;
	
	bool flag = false;
	for (int i = 1; i <= su; i++)
		if (up[i] < w[u]) {
			int t = up[i];
			up[i] = w[u];
			if (dfs(depth, u + 1, su, du)) return true;
			up[i] = t;
			flag = true;
			break;
		}
	if (!flag) {
		up[su + 1] = w[u];
		if (dfs(depth, u + 1, su + 1, du)) return true;
	}
	flag = false;
	for (int i = 1; i <= du; i++)
		if (down[i] > w[u]) {
			int t = down[i];
			down[i] = w[u];
			if (dfs(depth, u + 1, su, du)) return true;
			down[i] = t;
			flag = true;
			break;
		}
	if (!flag) {
		down[du + 1] = w[u];
		if (dfs(depth, u + 1, su, du + 1)) return true;
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	while (cin >> n, n) {
		for (int i = 0; i < n; i++) cin >> w[i];

		int depth = 0;
		while (!dfs(depth, 0, 0, 0)) depth++;
		cout << depth << endl;
	}
	return 0;
}