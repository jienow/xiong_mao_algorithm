#include <iostream>
using namespace std;
const int N = 14;
char f[N][N];
bool col[N], dg[N], udg[N*2];
int n;
void dfs(int u) {
	if (u == n + 1)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				cout << f[i][j];
			cout << endl;
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!col[i] && !dg[u + i] && !udg[i - u + n])
		{
			f[u][i] = 'Q';
			col[i] = dg[u + i] = udg[i - u + n] = true;
			dfs(u + 1);
			col[i] = dg[u + i] = udg[i - u + n] = false;
			f[u][i] = '.';
		}
	}
}
void init() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			f[i][j] = '.';
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	init();
	dfs(1);
	return 0;
}