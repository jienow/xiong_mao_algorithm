/*
* 给你一个n种面值的货币系统，求组成面值为m的货币有多少种方案。

#### 输入格式

第一行，包含两个整数n和m。

接下来n行，每行包含一个整数，表示一种货币的面值。

#### 输出格式

共一行，包含一个整数，表示方案数。

#### 数据范围

$n \\le 15, m \\le 3000$

#### 输入样例：

    3 10
    1
    2
    5
    

#### 输出样例：

    10
*/

#include <iostream>
using namespace std;
const int N = 3010;
using LL = long long;
LL f[N];
int n, m;
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    f[0] = 1;
    for (int i = 0; i < n; i++) {
        int v; cin >> v;
        for (int j = v; j <= m; j++)
            f[j] += f[j - v];
    }
    cout << f[m] << endl;
	return 0;
} 