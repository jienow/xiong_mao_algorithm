#include <iostream>
#include <cstring>
using namespace std;
const int N = 110, M = N << 1;
int f[N][N], h[N], e[M], ne[M], w[M], idx;
int n, m;
void add(int a, int b, int c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
void dfs(int u, int father) {
	for (int i = h[u]; ~i; i = ne[i]) {
		int ver = e[i];
		if (ver == father)continue;
		dfs(ver, u);
		for (int j = m; j >= 0; j--)
			for (int k = 0; k < j; k++)
				f[u][j] = max(f[u][j], f[u][j - k - 1] + f[ver][k] + w[i]);
	}
}
int main() {
	cin >> n >> m;
	memset(h, -1, sizeof h);
	for (int i = 1; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
		add(b, a, c);
	}
	dfs(1, -1);
	cout << f[1][m] << endl;
	return 0;
}