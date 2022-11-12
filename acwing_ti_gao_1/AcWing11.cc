/*
* 有 $N$ 件物品和一个容量是 $V$ 的背包。每件物品只能使用一次。

第 $i$ 件物品的体积是 $v\_i$，价值是 $w\_i$。

求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。

输出 **最优选法的方案数**。注意答案可能很大，请输出答案模 $10^9 + 7$ 的结果。

#### 输入格式

第一行两个整数，$N，V$，用空格隔开，分别表示物品数量和背包容积。

接下来有 $N$ 行，每行两个整数 $v\_i, w\_i$，用空格隔开，分别表示第 $i$ 件物品的体积和价值。

#### 输出格式

输出一个整数，表示 **方案数** 模 $10^9 + 7$ 的结果。

#### 数据范围

$0 \\lt N, V \\le 1000$  
$0\\lt v\_i, w\_i \\le 1000$

#### 输入样例

    4 5
    1 2
    2 4
    3 4
    4 6
    

#### 输出样例：

    2
*/

#include <cstring>
#include <iostream>
using namespace std;
const int N = 1010, mod = 1e9 + 7;
int f[N], g[N];
int n, m;
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    memset(f, -0x3f, sizeof f);
    f[0] = 0;
    g[0] = 1;

    for (int i = 0; i < n; i++)
    {
        int v, w;
        cin >> v >> w;
        for (int j = m; j >= v; j--)
        {
            int maxv = max(f[j], f[j - v] + w);
            int s = 0;
            if (maxv == f[j]) s = g[j];
            if (maxv == f[j - v] + w) s = (s + g[j - v]) % mod;
            f[j] = maxv, g[j] = s;
        }
    }
    int res = 0;
    for (int i = 1; i <= m; i++)
        if (f[i] > f[res])
            res = i;
    int sum = 0;
    for (int i = 0; i <= m; i++)
        if (f[i] == f[res])
            sum = (sum + g[i]) % mod;
    cout << sum << endl;

	return 0;
}