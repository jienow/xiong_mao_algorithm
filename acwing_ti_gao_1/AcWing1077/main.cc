/*
*	与战略游戏不同的是
*		战略游戏的目标是求边，就是边得看完，所以这个和没有上司的舞会是一样的
*		这个题目的目标是求点，每个点都得开完，所以这个与上面不一样
*   f[i][0] 代表的是父节点选，sum (f[j][1] + f[j][2])
*   f[i][1] 代表的是子节点必须有一个选，就是选一个总和最小的，然后
			f[j][2]的意思是选这个节点放东西
			f[u][0] - min(f[j][1],f[j][2])的意思是除去当前节点其他节点的和
*			f[j][2] + f[u][0] - min( f[j][1] , f[j][2])
*   f[i][2] 代表了当前节点选，子节点任意，所以求一个最小值就行
			sum (min(min(f[j][0],f[j][1]),f[j][2]))
*/

#include <iostream>
#include <cstring>
using namespace std;
const int N = 1510;
int f[N][3], h[N],w[N], ne[N], e[N], idx;
bool st[N];
int n;
void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void dfs(int u) {
	f[u][0] = 0;
	f[u][1] = 1e9;
	f[u][2] = w[u];
	for (int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i];
		dfs(j);
		f[u][0] += min(f[j][1], f[j][2]);
		f[u][2] += min(min(f[j][0], f[j][1]), f[j][2]);
	}
	for (int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i];
		f[u][1] = min(f[u][1], f[j][2] + f[u][0] - min(f[j][1], f[j][2]));
	}
}
int main() {
	cin >> n;
	memset(h, -1, sizeof h);
	for (int i = 1; i <= n; i++) {
		int idx, cost, cnt;
		cin >> idx >> cost >> cnt;
		w[idx] = cost;
		while (cnt--) {
			int ver; cin >> ver;
			add(idx, ver);
			st[ver] = true;
		}
	}
	int root = 1;
	while (st[root]) root++;
	dfs(root);
	cout << min(f[root][1], f[root][2]) << endl;
	
	return 0;
}