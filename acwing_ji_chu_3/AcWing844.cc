/*
* ����һ�� $n \\times m$ �Ķ�ά�������飬������ʾһ���Թ���������ֻ���� $0$ �� $1$������ $0$ ��ʾ�����ߵ�·��$1$ ��ʾ����ͨ����ǽ�ڡ�

�������һ����λ�����Ͻ� $(1, 1)$ ������֪����ÿ�ο������ϡ��¡���������һ�������ƶ�һ��λ�á�

���ʣ����˴����Ͻ��ƶ������½� $(n, m)$ ����������Ҫ�ƶ����ٴΡ�

���ݱ�֤ $(1, 1)$ ���� $(n, m)$ ��������Ϊ $0$����һ�����ٴ���һ��ͨ·��

#### �����ʽ

��һ�а����������� $n$ �� $m$��

������ $n$ �У�ÿ�а��� $m$ ��������$0$ �� $1$������ʾ�����Ķ�ά�����Թ���

#### �����ʽ

���һ����������ʾ�����Ͻ��ƶ������½ǵ������ƶ�������

#### ���ݷ�Χ

$1 \\le n, m \\le 100$

#### ����������

	5 5
	0 1 0 0 0
	0 1 0 1 0
	0 0 0 0 0
	0 1 1 1 0
	0 0 0 1 0


#### ���������

	8
*/

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int N = 110;
typedef pair<int, int> PII;
int h[N][N], sd[N][N];
int x_zhou[]{ -1,0,0,1 }, y_zhou[]{ 0,-1,1,0 };
int n, m;
int dfs() {
	queue<PII> que;
	que.push({ 0,0 });
	memset(sd, -1, sizeof sd);
	sd[0][0] = 0;

	while (!que.empty()) {
		PII point = que.front();
		que.pop();

		for (int i = 0; i < 4; i++) {
			int x = point.first + x_zhou[i], y = point.second + y_zhou[i];

			if (x >= 0 && x < n && y >= 0 && y < m && h[x][y] == 0 && sd[x][y] == -1) {
				que.push({ x,y });
				sd[x][y] = sd[point.first][point.second] + 1;
			}
		}

	}
	return sd[n - 1][m - 1];
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> h[i][j];
	cout << dfs() << endl;
	return 0;
}