#include <iostream>
using namespace std;
const int N = 13;
char g[N][N];
bool col[N], dg[N * 2], udg[N * 2];
int n;
void dfs(int u) {
	if (u == n) {
		for (int i = 0; i < n; i++)
			printf("%s\n", g[i]);
		puts("");
		return;
	}
	for (int i = 0; i < n; i++)
		if (!col[i] && !dg[u + i] && !udg[u - i + n] && g[u][i] == '.')
		{
			g[u][i] = 'Q';
			col[i] = dg[u + i] = udg[u - i + n] = true;
			dfs(u + 1);
			g[u][i] = '.';
			col[i] = dg[u + i] = udg[u - i + n] = false;
		}
}
int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			g[i][j] = '.';
	dfs(0);

	return 0;
}