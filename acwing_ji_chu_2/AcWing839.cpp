/*
维护一个集合，初始时集合为空，支持如下几种操作：

1.  `I x`，插入一个数 $x$；
2.  `PM`，输出当前集合中的最小值；
3.  `DM`，删除当前集合中的最小值（数据保证此时的最小值唯一）；
4.  `D k`，删除第 $k$ 个插入的数；
5.  `C k x`，修改第 $k$ 个插入的数，将其变为 $x$；

现在要进行 $N$ 次操作，对于所有第 $2$ 个操作，输出当前集合的最小值。

#### 输入格式

第一行包含整数 $N$。

接下来 $N$ 行，每行包含一个操作指令，操作指令为 `I x`，`PM`，`DM`，`D k` 或 `C k x` 中的一种。

#### 输出格式

对于每个输出指令 `PM`，输出一个结果，表示当前集合中的最小值。

每个结果占一行。

#### 数据范围

$1 \\le N \\le 10^5$
$\-10^9 \\le x \\le 10^9$
数据保证合法。

#### 输入样例：

    8
    I -10
    PM
    I -10
    D 1
    C 2 8
    I 6
    PM
    DM


#### 输出样例：

    -10
    6
*/

#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int h[N], hp[N], ph[N], cnt, m;
void heap_swap(int a, int b)
{
    swap(h[a], h[b]);
    swap(hp[a], hp[b]);
    swap(ph[hp[a]], ph[hp[b]]);
}
void down(int u)
{
    int t = u;
    if (u * 2 <= cnt && h[t] > h[u * 2])
        t = u * 2;
    if (u * 2 + 1 <= cnt && h[t] > h[u * 2 + 1])
        t = u * 2 + 1;
    if (u != t){
        heap_swap(u, t);
        down(t);
    }
}
void up(int u)
{
    while (u / 2 && h[u / 2] > h[u]){
        heap_swap(u, u / 2);
        u >>= 1;
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        char op[5];
        scanf("%s", op);
        if (!strcmp(op, "I"))
        {
            int x;
            scanf("%d", &x);
            cnt++;
            m++;
            h[cnt] = x;
            hp[cnt] = m;
            ph[m] = cnt;
            up(cnt);
        }
        else if (!strcmp(op, "PM"))
            printf("%d\n", h[1]);
        else if (!strcmp(op, "DM"))
        {
            heap_swap(1, cnt);
            cnt--;
            down(1);
        }
        else if (!strcmp(op, "D"))
        {
            int k;
            scanf("%d", &k);
            k = ph[k];
            heap_swap(k, cnt);
            cnt--;
            up(k), down(k);
        }
        else if (!strcmp(op, "C"))
        {
            int k, x;
            scanf("%d%d", &k, &x);
            h[ph[k]] = x;
            down(ph[k]), up(ph[k]);
        }
    }

    return 0;
}