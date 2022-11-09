/*
* 有 $N$ 件物品和一个容量是 $V$ 的背包，背包能承受的最大重量是 $M$。

每件物品只能用一次。体积是 $v\_i$，重量是 $m\_i$，价值是 $w\_i$。

求解将哪些物品装入背包，可使物品总体积不超过背包容量，总重量不超过背包可承受的最大重量，且价值总和最大。  
输出最大价值。

#### 输入格式

第一行三个整数，$N,V, M$，用空格隔开，分别表示物品件数、背包容积和背包可承受的最大重量。

接下来有 $N$ 行，每行三个整数 $v\_i, m\_i, w\_i$，用空格隔开，分别表示第 $i$ 件物品的体积、重量和价值。

#### 输出格式

输出一个整数，表示最大价值。

#### 数据范围

$0 \\lt N \\le 1000$  
$0 \\lt V, M \\le 100$  
$0 \\lt v\_i, m\_i \\le 100$  
$0 \\lt w\_i \\le 1000$

#### 输入样例

    4 5 6
    1 2 3
    2 4 4
    3 4 5
    4 5 6
    

#### 输出样例：

    8
*/

#include <iostream>
using namespace std;
const int N = 110;
int f[N][N];
int n, v, m;
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> v >> m;
    for (int i = 0; i < n; i++) {
        int vv, mm, ww;
        cin >> vv >> mm >> ww;
        for (int j = v; j >= vv; j--)
            for (int k = m; k >= mm; k--)
                f[j][k] = max(f[j][k], f[j - vv][k - mm] + ww);
    }
    cout << f[v][m];
	return 0;
}