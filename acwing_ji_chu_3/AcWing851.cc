/*
* 给定一个 $n$ 个点 $m$ 条边的有向图，图中可能存在重边和自环， **边权可能为负数**。

请你求出 $1$ 号点到 $n$ 号点的最短距离，如果无法从 $1$ 号点走到 $n$ 号点，则输出 `impossible`。

数据保证不存在负权回路。

#### 输入格式

第一行包含整数 $n$ 和 $m$。

接下来 $m$ 行每行包含三个整数 $x,y,z$，表示存在一条从点 $x$ 到点 $y$ 的有向边，边长为 $z$。

#### 输出格式

输出一个整数，表示 $1$ 号点到 $n$ 号点的最短距离。

如果路径不存在，则输出 `impossible`。

#### 数据范围

$1 \\le n,m \\le 10^5$,
图中涉及边长绝对值均不超过 $10000$。

#### 输入样例：

	3 3
	1 2 5
	2 3 -3
	1 3 4


#### 输出样例：

	2
*/

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;
int h[N], e[N], ne[N], w[N], idx;
int n, m, dist[N];
int st[N];
void add(int a, int b, int c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
int spfa() {
	memset(dist, 0x3f, sizeof dist);
	queue<int> que;
	que.push(1);
	dist[1] = 0;
	st[1] = true;

	while (que.size()) {
		int t = que.front();
		que.pop();
		st[t] = false;

		for (int i = h[t]; i != -1; i = ne[i]) {
			int j = e[i];
			if (dist[j] > dist[t] + w[i]) { // w的意思是当前节点与下一个相连的节点的权重.
				dist[j] = dist[t] + w[i];
				if (!st[j]) 
					que.push(j);
				st[j] = true;
				//当存在多条边指向同一个节点的时候，push一次那个节点就够了.
			}
		}
	}
	return dist[n];
}
int main() {
	scanf("%d%d", &n, &m);
	memset(h, -1, sizeof h);
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		add(x, y, z);
	}
	int t = spfa();
	if (t == 0x3f3f3f3f)puts("impossible");
	else printf("%d\n", t);
	return 0;
}