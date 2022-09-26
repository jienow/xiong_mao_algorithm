/*
给定一个字符串 $S$，以及一个模式串 $P$，所有字符串中只包含大小写英文字母以及阿拉伯数字。

模式串 $P$ 在字符串 $S$ 中多次作为子串出现。

求出模式串 $P$ 在字符串 $S$ 中所有出现的位置的起始下标。

#### 输入格式

第一行输入整数 $N$，表示字符串 $P$ 的长度。

第二行输入字符串 $P$。

第三行输入整数 $M$，表示字符串 $S$ 的长度。

第四行输入字符串 $S$。

#### 输出格式

共一行，输出所有出现位置的起始下标（下标从 $0$ 开始计数），整数之间用空格隔开。

#### 数据范围

$1 \\le N \\le 10^5$
$1 \\le M \\le 10^6$

#### 输入样例：

    3
    aba
    5
    ababa


#### 输出样例：

    0 2
*/

#include <iostream>
using namespace std;
const int N = 1e5 + 10, M = 1e6 + 10;
int n, m, ne[N];
char q[N], s[M];
int main()
{
    cin >> n >> q + 1 >> m >> s + 1;
    for (int i = 2, j = 0; i <= n; i++)
    {
        while (j && q[i] != q[j + 1])
            j = ne[j];
        if (q[i] == q[j + 1])
            j++;
        ne[i] = j;
    }
    for (int i = 1, j = 0; i <= m; i ++)
    {
        while (j && s[i] != q[j + 1])
            j = ne[j];
        if (s[i] == q[j + 1])
            j++;
        if (j == n){
            cout << i - n << " ";
            j = ne[j];
        }
    }
    return 0;
}