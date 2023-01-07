/*
*	我们可以把他看作一个动态规划
*	我们的状态数组就是f[i][j]，在最多经过i条边，到达j节点的大小是多少
*   由于我们只用到了两层f,所以用两个数组进行模拟就可以了
**/
#include <iostream>
#include <cstring>
using namespace std;
const int N = 510, M = 10010;
struct E {
	int a, b, w;
}edges[M];
int n, m, k, dist[N], backup[N];
void bellman_ford() {
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	for (int i = 0; i < k; i++) {
		memcpy(backup, dist, sizeof dist);
		for (int j = 0; j < m; j++) {
			int x = edges[j].a, y = edges[j].b, w = edges[j].w;
			dist[y] = min(dist[y], backup[x] + w);
		}
	}
	if (dist[n] > 0x3f3f3f3f / 2) cout << "impossible";
	else cout << dist[n];
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
	{
		int a, b, w; cin >> a >> b >> w;
		edges[i] = { a,b,w };
	}
	bellman_ford();
	return 0;
}