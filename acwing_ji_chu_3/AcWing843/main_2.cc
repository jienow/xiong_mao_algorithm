#include <iostream>
using namespace std;
const int N = 13;
char str[N][N];
int n;
bool col[N], dg[2 * N], udg[2 * N];
void dfs(int u) {
	if (u > n) {
		for (int i = 1; i <= n; i++)
			printf("%s\n", &str[i][1]);
		puts("");
		return;
	}
	for (int i = 1; i <= n; i++)
		if (!col[i] && !dg[i + u] && !udg[u - i + n] && str[u][i] == '.') {
			col[i] = dg[i + u] = udg[u - i + n] = true;
			str[u][i] = 'Q';
			dfs(u + 1);
			col[i] = dg[i + u] = udg[u - i + n] = false;
			str[u][i] = '.';
		}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			str[i][j] = '.';
	dfs(1);
	return 0;
}