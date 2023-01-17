#include <iostream>
using namespace std;
const int N = 55, M = N * N;
typedef pair<int, int> PII;
#define x first
#define y second
int dx[]{ 0,-1,0,1 }, dy[]{ -1,0,1,0 };
int g[N][N], n, m;
PII q[M];
bool st[N][N];
int dfs(int sx, int sy) {
	int hh = 0, tt = 0;
	q[0] = { sx,sy };
	st[sx][sy] = true;
	int area = 0;
	while (hh <= tt) {
		PII t = q[hh++];
		area++;
		for (int i = 0; i < 4; i++) {
			int xx = t.x + dx[i], yy = t.y + dy[i];
			if (xx < 0 || xx >= n || yy < 0 || yy >= m)continue;
			if (st[xx][yy]) continue;
			if (g[t.x][t.y] >> i & 1) continue;
			q[++tt] = { xx,yy };
			st[xx][yy] = true;
		}
	}
	return area;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> g[i][j];

	int area = 0, cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!st[i][j]) {
				area = max(area, dfs(i, j));
				cnt++;
			}
	cout << cnt << endl << area << endl;

	return 0;
}