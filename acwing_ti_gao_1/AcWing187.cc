#include <iostream>
using namespace std;
const int N = 55;
int h[N], up[N], down[N];
int n, ans;

void dfs(int u, int su, int du) {

	if (su + du >= ans) return;
	if (u == n) {
		ans = min(ans, su + du);
		return;
	}

	int k = 0;
	while (k < su && up[k] >= h[u])k++;
	if (k < su) {
		int t = up[k];
		up[k] = h[u];
		dfs(u + 1, su, du);
		up[k] = t;
	}
	else {
		up[k] = h[u];
		dfs(u + 1, su + 1, du);
	}

	k = 0;
	while (k < du && down[k] <= h[u])k++;
	if (k < du) {
		int t = down[k];
		down[k] = h[u];
		dfs(u + 1, su, du);
		down[k] = t;
	}
	else {
		down[k] = h[u];
		dfs(u + 1, su, du + 1);
	}
}

int main() {
	while (cin >> n, n) {
		for (int i = 0; i < n; i++)cin >> h[i];

		ans = n;
		dfs(0, 0, 0);
		cout << ans << endl;
	}

	return 0;
}