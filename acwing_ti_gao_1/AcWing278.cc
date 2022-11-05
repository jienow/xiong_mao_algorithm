/*
* 给定 $N$ 个正整数 $A\_1,A\_2,…,A\_N$，从中选出若干个数，使它们的和为 $M$，求有多少种选择方案。

#### 输入格式

第一行包含两个整数 $N$ 和 $M$。

第二行包含 $N$ 个整数，表示 $A\_1,A\_2,…,A\_N$。

#### 输出格式

包含一个整数，表示可选方案数。

#### 数据范围

$1 \\le N \\le 100$,  
$1 \\le M \\le 10000$,  
$1 \\le A\_i \\le 1000$,  
答案保证在 int 范围内。

#### 输入样例：

    4 4
    1 1 2 2
    

#### 输出样例：

    3
*/

#include <iostream>
using namespace std;
const int N = 10010;
int f[N];
int n, m;
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    f[0] = 1;
    for (int i = 0; i < n; i++) {
        int v; cin >> v;
        for (int j = m; j >= v; --j)f[j] += f[j - v];
    }
    cout << f[m] << endl;
	return 0;
}