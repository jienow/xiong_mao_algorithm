/*
* 一个数的序列 $b\_i$，当 $b\_1<b\_2<…<b\_S$ 的时候，我们称这个序列是上升的。

对于给定的一个序列($a\_1,a\_2,…,a\_N$)，我们可以得到一些上升的子序列($a\_{i\_1},a\_{i\_2},…,a\_{i\_K}$)，这里$1≤i\_1<i\_2<…<i\_K≤N$。

比如，对于序列(1,7,3,5,9,4,8)，有它的一些上升子序列，如(1,7),(3,4,8)等等。

这些子序列中和最大为18，为子序列(1,3,5,9)的和。

你的任务，就是对于给定的序列，求出最大上升子序列和。

注意，最长的上升子序列的和不一定是最大的，比如序列(100,1,2,3)的最大上升子序列和为100，而最长上升子序列为(1,2,3)。

#### 输入格式

输入的第一行是序列的长度N。

第二行给出序列中的N个整数，这些整数的取值范围都在0到10000(可能重复)。

#### 输出格式

输出一个整数，表示最大上升子序列和。

#### 数据范围

$1 \\le N \\le 1000$

#### 输入样例：

    7
    1 7 3 5 9 4 8
    

#### 输出样例：

    18
*/

#include <iostream>
using namespace std;
const int N = 1010;
int f[N], a[N], n;
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        f[i] = a[i];
        for (int j = 1; j < i; ++j)
            if (a[j] < a[i])
                f[i] = max(f[i], f[j] + a[i]);
        res = max(res, f[i]);
    }
    cout << res << endl;

	return 0;
}