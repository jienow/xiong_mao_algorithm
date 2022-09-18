/*
给定一颗树，树中包含 $n$ 个结点（编号 $1 \\sim n$）和 $n-1$ 条无向边。

请你找到树的重心，并输出将重心删除后，剩余各个连通块中点数的最大值。

重心定义：重心是指树中的一个结点，如果将这个点删除后，剩余各个连通块中点数的最大值最小，那么这个节点被称为树的重心。

#### 输入格式

第一行包含整数 $n$，表示树的结点数。

接下来 $n-1$ 行，每行包含两个整数 $a$ 和 $b$，表示点 $a$ 和点 $b$ 之间存在一条边。

#### 输出格式

输出一个整数 $m$，表示将重心删除后，剩余各个连通块中点数的最大值。

#### 数据范围

$1 \\le n \\le 10^5$

#### 输入样例

    9
    1 2
    1 7
    1 4
    2 8
    2 5
    4 3
    3 9
    4 6


#### 输出样例：

    4
*/

// 无论是深度优先搜索还是宽度优先搜索，他们的时间复杂度都是 f(n+m)

#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int n, e[N], ne[N], h[N], idx, ans = N;
bool st[N];
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u)
{
    st[u] = true;

    int sum = 1, res = 0;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j]){
            int a = dfs(j);
            res = max(res, a);
            sum += res;
        }
        
    }
    res = max(n - sum, res);
    ans = min(res, ans);
    return res;
}

int main()
{
    int n;
    scanf("%d", &n);

    memset(h, -1, sizeof h);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }


    dfs(1);

    cout << ans << endl;

    return 0;
}