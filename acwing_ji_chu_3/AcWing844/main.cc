#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> PII;
PII map[]{ {1,0},{0,-1},{-1,0},{0,1} };
const int N = 110;
int f[N][N], n, m;
bool st[N][N];
void bfs() {
	queue<PII> que;
	que.push({ 1,1 });

	while (!que.empty()) {
		int i = que.front().first, j = que.front().second;
		que.pop();
		for (int k = 0; k < 4; k++) {
			int ii = i + map[k].first, jj = j + map[k].second;
			if (ii >= 1 && ii <= n && jj >= 1 && jj <= m && !st[ii][jj]) {
				f[ii][jj] = f[i][j] + 1;
				st[ii][jj] = true;
				que.push({ ii,jj });
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> st[i][j];
	bfs();
	cout << f[n][m] << endl;
	return 0;
}