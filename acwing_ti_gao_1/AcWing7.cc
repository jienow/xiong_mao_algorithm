/*
* 有 $N$ 种物品和一个容量是 $V$ 的背包。

物品一共有三类：

*   第一类物品只能用1次（01背包）；
*   第二类物品可以用无限次（完全背包）；
*   第三类物品最多只能用 $s\_i$ 次（多重背包）；

每种体积是 $v\_i$，价值是 $w\_i$。

求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。
输出最大价值。

#### 输入格式

第一行两个整数，$N，V$，用空格隔开，分别表示物品种数和背包容积。

接下来有 $N$ 行，每行三个整数 $v\_i, w\_i, s\_i$，用空格隔开，分别表示第 $i$ 种物品的体积、价值和数量。

*   $s\_i = -1$ 表示第 $i$ 种物品只能用1次；
*   $s\_i = 0$ 表示第 $i$ 种物品可以用无限次；
*   $s\_i >0$ 表示第 $i$ 种物品可以使用 $s\_i$ 次；

#### 输出格式

输出一个整数，表示最大价值。

#### 数据范围

$0 \\lt N, V \\le 1000$
$0 \\lt v\_i, w\_i \\le 1000$
$\-1 \\le s\_i \\le 1000$

#### 输入样例

	4 5
	1 2 -1
	2 4 1
	3 4 0
	4 5 2


#### 输出样例：

	8
*/

#include <iostream>
using namespace std;
const int N = 1010;
int f[N];
int n, m;
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int v, w, s;
		cin >> v >> w >> s;
		if (!s) {
			for (int j = v; j <= m; j++)
				f[j] = max(f[j], f[j - v] + w);
		}
		else {
			if (s == -1) s = 1;
			for (int k = 1; k <= s; k *= 2) {
				for (int j = m; j >= k * v; j--)
					f[j] = max(f[j], f[j - k * v] + k * w);
				s -= k;
			}
			if (s)
				for (int j = m; j >= s * v; j--)
					f[j] = max(f[j], f[j - s * v] + s * w);
		}
	}
	cout << f[m] << endl;
	return 0;
}