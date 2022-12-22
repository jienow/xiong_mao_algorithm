/*
* 给定一棵树，树中包含 $n$ 个结点（编号$1$~$n$）和 $n-1$ 条无向边，每条边都有一个权值。

请你在树中找到一个点，使得该点到树中其他结点的最远距离最近。

#### 输入格式

第一行包含整数 $n$。

接下来 $n-1$ 行，每行包含三个整数 $a\_i,b\_i,c\_i$，表示点 $a\_i$ 和 $b\_i$ 之间存在一条权值为 $c\_i$ 的边。

#### 输出格式

输出一个整数，表示所求点到树中其他结点的最远距离。

#### 数据范围

$1 \\le n \\le 10000$,  
$1 \\le a\_i,b\_i \\le n$,  
$1 \\le c\_i \\le 10^5$

#### 输入样例：

    5 
    2 1 1 
    3 2 1 
    4 3 1 
    5 1 1
    

#### 输出样例：

    2
*/




#include <iostream>
#include <cstring>  
using namespace std;
const int N = 10000 + 10, INF = 0x3f3f3f3f;
int h[N], e[N * 2], ne[N * 2], w[N * 2], idx;
int p1[N], p2[N], d1[N], d2[N], up[N];
int n;
void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
int dfs_down(int u, int father) {
    d1[u] = d2[u] = -INF;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (j == father) continue;
        int dist = dfs_down(j, u) + w[i];
        if (dist >= d1[u]) {
            d2[u] = d1[u], d1[u] = dist;
            p2[u] = p1[u], p1[u] = j;
        }
        else if (dist > d2[u]) {
            d2[u] = dist, p2[u] = j;
        }
    }
    if (d1[u] == -INF) d1[u] = d2[u] = 0;
    return d1[u];
}
void dfs_up(int u, int father) {
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (j == father)continue;
        if (j == p1[u]) {
            up[j] = max(up[u], d2[u]) + w[i];
        }
        else up[j] = max(up[u], d1[u]) + w[i];
        dfs_up(j, u);
    }
}
int main() {
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 1; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    dfs_down(1, -1);
    dfs_up(1, -1);
    int res = INF;
    for (int i = 1; i <= n; i++) res = min(res, max(up[i], d1[i]));
    cout << res << endl;
    return 0;
}
