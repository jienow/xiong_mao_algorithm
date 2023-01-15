#include <iostream>
using namespace std;
typedef pair<int, int> PII;
const int N = 1010, M = N * N;
#define x first
#define y second
char g[N][N];
int n, m;
bool st[N][N];
PII q[M];
void dfs(int sx, int sy) {
	int hh = 0, tt = 0;
	q[0] = { sx,sy };
	st[sx][sy] = true;

	while (hh <= tt) {
		PII t = q[hh++];

		for (int i = t.x - 1; i <= t.x + 1; i++)
			for (int j = t.y - 1; j <= t.y + 1; j++) {
				if (i == t.x && j == t.y) continue;
				if (i < 0 || i >= n || j < 0 || j >= m) continue;
				if (g[i][j] == '.' || st[i][j]) continue;
				st[i][j] = true;
				q[++tt] = { i,j };
			}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) scanf("%s", g[i]);

	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (g[i][j] == 'W' && !st[i][j]) {
				dfs(i, j);
				cnt++;
			}
	printf("%d\n", cnt);

	return 0;
}