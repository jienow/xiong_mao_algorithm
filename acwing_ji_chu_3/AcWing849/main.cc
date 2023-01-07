/*
*	这个算法的基本思路是将选到的点放到已选的集合之中，在找到与所求点相连最短的点，把他也放到集合之中
*	更新所求点相连的最短的点，与他相连的点的最短路径
*/
#include <iostream>
#include <cstring>
using namespace std;
const int N = 510;
int n, m;
int g[N][N], dist[N];
bool st[N];
void dijkstrla() {
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;

	for (int i = 1; i <= n; i++) {
		int t = -1;
		for (int j = 1; j <= n; j++)
			if (!st[j] && (t == -1 || dist[t] > dist[j]))
				t = j;
		st[t] = true;
		for (int j = 1; j <= n; j++)
			if (!st[j])
				dist[j] = min(dist[j], dist[t] + g[t][j]);
	}
}
int main() {
	ios::sync_with_stdio(false);
	memset(g, 0x3f, sizeof g);
	cin >> n >> m;
	while (m--) {
		int x, y, z; cin >> x >> y >> z;
		g[x][y] = min(g[x][y], z);
	}
	dijkstrla();
	if (dist[n] == 0x3f3f3f3f)
		cout << "-1" << endl;
	else cout << dist[n] << endl;
	return 0;
}