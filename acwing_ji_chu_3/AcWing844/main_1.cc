#include <iostream>
#include <queue>
using namespace std;
const int N = 110;
typedef pair<int, int> PII;
PII d[4]{ {0,-1},{-1,0},{0,1},{1,0} };
int f[N][N];
bool st[N][N];
int n, m;
void bfs() {
	queue<PII> que;
	que.push({ 1,1 });
	st[1][1] = true;

	while (!que.empty())
	{
		auto t = que.front();
		que.pop();
		st[t.first][t.second] = true;
		for (int i = 0; i < 4; i++) {
			int xx = d[i].first + t.first, yy = d[i].second + t.second;
			if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && f[xx][yy] == 0 && st[xx][yy] == false) {
				f[xx][yy] = f[t.first][t.second] + 1;
				que.push({ xx,yy });
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> f[i][j];
	bfs();
	cout << f[n][m] << endl;
	return 0;
}