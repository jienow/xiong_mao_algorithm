/*
*
* 给定一个 $n$ 个点 $m$ 条边的有向图，图中可能存在重边和自环， **边权可能为负数**。

请你求出从 $1$ 号点到 $n$ 号点的最多经过 $k$ 条边的最短距离，如果无法从 $1$ 号点走到 $n$ 号点，输出 `impossible`。

注意：图中可能 **存在负权回路** 。

#### 输入格式

第一行包含三个整数 $n,m,k$。

接下来 $m$ 行，每行包含三个整数 $x,y,z$，表示存在一条从点 $x$ 到点 $y$ 的有向边，边长为 $z$。

点的编号为 $1 \\sim n$。

#### 输出格式

输出一个整数，表示从 $1$ 号点到 $n$ 号点的最多经过 $k$ 条边的最短距离。

如果不存在满足条件的路径，则输出 `impossible`。

#### 数据范围

$1 \\le n,k \\le 500$,
$1 \\le m \\le 10000$,
$1 \\le x,y \\le n$，
任意边长的绝对值不超过 $10000$。

#### 输入样例：

	3 3 1
	1 2 1
	2 3 1
	1 3 3


#### 输出样例：

	3
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 510, M = 100010;
struct edge {
	int a, b, w;
}edges[M];
int dist[N], backup[N];
int n, m, k;
void bellen_force() {
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	for (int i = 0; i < k; i++) {
		memcpy(backup, dist, sizeof dist);
		for (int j = 0; j < m; j++) {
			int a = edges[j].a, b = edges[j].b, w = edges[j].w;
			dist[b] = min(dist[b], backup[a] + w);
		}
	}
	if (dist[n] > 0x3f3f3f3f / 2)puts("impossible");
	else printf("%d", dist[n]);
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		edges[i] = { a,b,w };
	}
	bellen_force();
	return 0;
}