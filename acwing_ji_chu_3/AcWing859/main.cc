/*
*	整体思路是将所有的边进行排序，拿到最短的边，将两个集合合并
*	最后看边的个数是否为点的个数-1
*/
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10, M = 2e5 + 10;
struct Edge {
	int a, b, w;
	bool operator<(const Edge& W)const {
		return w < W.w;
	}
}edge[M];
int n, m, p[N];
int find(int x) {
	if (p[x] != x) p[x] = find(p[x]);
	return p[x];
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, w; cin >> a >> b >> w;
		edge[i] = { a,b,w };
	}
	sort(edge, edge + m);
	for (int i = 1; i <= n; i++) p[i] = i;

	int cnt = 0;
	int res = 0;
	for (int i = 0; i < m; i++)
	{
		int a = edge[i].a, b = edge[i].b, w = edge[i].w;
		int pa = find(a), pb = find(b);
		if (pa != pb) {
			p[pa] = pb;
			cnt++;
			res += w;
		}
	}
	if (cnt != n - 1)
		cout << "impossible" << endl;
	else cout << res << endl;

	return 0;
}