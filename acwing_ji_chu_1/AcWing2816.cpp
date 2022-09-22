/*
给定一个长度为 $n$ 的整数序列 $a\_1,a\_2,…,a\_n$ 以及一个长度为 $m$ 的整数序列 $b\_1,b\_2,…,b\_m$。

请你判断 $a$ 序列是否为 $b$ 序列的子序列。

子序列指序列的一部分项按**原有次序排列**而得的序列，例如序列 $\\{a\_1,a\_3,a\_5\\}$ 是序列 $\\{a\_1,a\_2,a\_3,a\_4,a\_5\\}$ 的一个子序列。

#### 输入格式

第一行包含两个整数 $n,m$。

第二行包含 $n$ 个整数，表示 $a\_1,a\_2,…,a\_n$。

第三行包含 $m$ 个整数，表示 $b\_1,b\_2,…,b\_m$。

#### 输出格式

如果 $a$ 序列是 $b$ 序列的子序列，输出一行 `Yes`。

否则，输出 `No`。

#### 数据范围

$1 \\le n \\le m \\le 10^5$,
$\-10^9 \\le a\_i,b\_i \\le 10^9$

#### 输入样例：

    3 5
    1 3 5
    1 2 3 4 5


#### 输出样例：

    Yes
*/

#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int a[N], b[N], n, m;
int main()
{
    cin >> m >> n;
    for (int i = 0; i < m; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0, j = 0; i < n; i++)
    {
        while (j < m && a[i] == b[j]){
            i++, j++;
        }
        if (j == m)
        {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}