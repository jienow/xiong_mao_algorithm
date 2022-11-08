/*
* 有 $N$ 种物品和一个容量是 $V$ 的背包。

第 $i$ 种物品最多有 $s\_i$ 件，每件体积是 $v\_i$，价值是 $w\_i$。

求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。  
输出最大价值。

#### 输入格式

第一行两个整数，$N，V$ $(0 \\lt N \\le 1000$, $0 \\lt V \\le 20000)$，用空格隔开，分别表示物品种数和背包容积。

接下来有 $N$ 行，每行三个整数 $v\_i, w\_i, s\_i$，用空格隔开，分别表示第 $i$ 种物品的体积、价值和数量。

#### 输出格式

输出一个整数，表示最大价值。

#### 数据范围

$0 \\lt N \\le 1000$  
$0 \\lt V \\le 20000$  
$0 \\lt v\_i, w\_i, s\_i \\le 20000$

##### 提示

本题考查多重背包的单调队列优化方法。

#### 输入样例

    4 5
    1 2 3
    2 4 1
    3 4 3
    4 5 2
    

#### 输出样例：

    10
*/

#include <iostream>
#include <cstring>
const int N = 21010;
using namespace std;
int dp[N], pre[N], q[N];
int n, m;
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		memcpy(pre, dp, sizeof dp);
		int v, w, s;
		cin >> v >> w >> s;
		for (int j = 0; j < v; j++) {
			int head = 0, tail = -1;
			for (int k = j; k <= m; k += v) {
				if (head <= tail && k - s * v > q[head])
					++head;
				while (head <= tail && pre[q[tail]] - (q[tail] - j) / v * w <= pre[k] - (k - j) / v * w)
					--tail;

				if (head <= tail)
					dp[k] = max(dp[k], pre[q[head]] + (k - q[head]) / v * w);

				q[++tail] = k;
			}
		}
	}
	cout << dp[m] << endl;
	return 0;
}