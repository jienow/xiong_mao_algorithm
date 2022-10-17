/*
* 给定一个 $n$ 个点 $m$ 条边的有向图，图中可能存在重边和自环， **边权可能为负数**。

请你判断图中是否存在负权回路。

#### 输入格式

第一行包含整数 $n$ 和 $m$。

接下来 $m$ 行每行包含三个整数 $x,y,z$，表示存在一条从点 $x$ 到点 $y$ 的有向边，边长为 $z$。

#### 输出格式

如果图中**存在**负权回路，则输出 `Yes`，否则输出 `No`。

#### 数据范围

$1 \\le n \\le 2000$,
$1 \\le m \\le 10000$,
图中涉及边长绝对值均不超过 $10000$。

#### 输入样例：

	3 3
	1 2 -1
	2 3 4
	3 1 -4


#### 输出样例：

	Yes
*/

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int N = 10010;
int h[N], e[N], ne[N], w[N], idx;
int n, m;
int dist[N], cnt[N];
bool st[N];
void add(int a, int b, int c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
bool spfa() {
	queue<int> que;
	for (int i = 1; i <= n; i++) {
		st[i] = true;
		que.push(i);
	}
	while (que.size()) {
		int t = que.front();
		que.pop();
		st[t] = false;
		for (int i = h[t]; i != -1; i = ne[i]) {
			int j = e[i];
			if (dist[j] > dist[t] + w[i]) {
				dist[j] = dist[t] + w[i];
				cnt[j] = cnt[t] + 1;
				if (cnt[j] >= n) return true;
				if (!st[j]) {
					st[j] = true;
					que.push(j);
				}
			}
		}
	}
	return false;
}
int main() {
	scanf("%d%d", &n, &m);
	memset(h, -1, sizeof h);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
	}
	if (spfa())puts("Yes");
	else printf("No");
	return 0;
}