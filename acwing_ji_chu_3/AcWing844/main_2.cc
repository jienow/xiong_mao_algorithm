#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> PII;
PII map[5] = { {},{-1,0},{0,1},{1,0},{0,-1} };
const int N = 110;
int arr[N][N];
bool st[N][N];
int n, m;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];
	queue<PII> q;
	q.push({ 1,1 });
	while (!q.empty()) {
		PII val = q.front();
		q.pop();
		for (int i = 1; i <= 4; i++) {
			int xx = map[i].first + val.first, yy = map[i].second + val.second;
			if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && arr[xx][yy] == 0 && !st[xx][yy]) {
				st[xx][yy] = true;
				arr[xx][yy] = arr[val.first][val.second] + 1;
				q.push({ xx,yy });
			}
		}
	}
	cout << arr[n][m] << endl;
	return 0;
}