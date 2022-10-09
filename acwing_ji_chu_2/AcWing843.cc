/*
$n-$皇后问题是指将 $n$ 个皇后放在 $n \\times n$ 的国际象棋棋盘上，使得皇后不能相互攻击到，即任意两个皇后都不能处于同一行、同一列或同一斜线上。

![1_597ec77c49-8-queens.png](https://cdn.acwing.com/media/article/image/2019/06/08/19_860e00c489-1_597ec77c49-8-queens.png)

现在给定整数 $n$，请你输出所有的满足条件的棋子摆法。

#### 输入格式

共一行，包含整数 $n$。

#### 输出格式

每个解决方案占 $n$ 行，每行输出一个长度为 $n$ 的字符串，用来表示完整的棋盘状态。

其中 `.` 表示某一个位置的方格状态为空，`Q` 表示某一个位置的方格上摆着皇后。

每个方案输出完成后，输出一个空行。

**注意：行末不能有多余空格。**

输出方案的顺序任意，只要不重复且没有遗漏即可。

#### 数据范围

$1 \\le n \\le 9$

#### 输入样例：

	4


#### 输出样例：

	.Q..
	...Q
	Q...
	..Q.

	..Q.
	Q...
	...Q
	.Q..
*/

#include <iostream>
using std::cout, std::endl, std::cin;
const int N = 20;
bool cow[N], dg[N], udg[N];
char g[N][N];
int n;
void dfs(int u) {
	if (u == n) {
		for (int i = 0; i < n; i++)puts(g[i]);
		puts("");
	}
	else {
		for (int i = 0; i < n; i++) {
			if (!cow[i] && !dg[i + u] && !udg[u - i + n]) {
				g[u][i] = 'Q';
				cow[i] = dg[i + u] = udg[u - i + n] = true;
				dfs(u + 1);
				cow[i] = dg[i + u] = udg[u - i + n] = false;
				g[u][i] = '.';
			}
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			g[i][j] = '.';
	dfs(0);
	return 0;
}