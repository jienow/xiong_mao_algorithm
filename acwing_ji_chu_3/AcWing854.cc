/*
* 给定一个 $n$ 个点 $m$ 条边的有向图，图中可能存在重边和自环，边权可能为负数。

再给定 $k$ 个询问，每个询问包含两个整数 $x$ 和 $y$，表示查询从点 $x$ 到点 $y$ 的最短距离，如果路径不存在，则输出 `impossible`。

数据保证图中不存在负权回路。

#### 输入格式

第一行包含三个整数 $n,m,k$。

接下来 $m$ 行，每行包含三个整数 $x,y,z$，表示存在一条从点 $x$ 到点 $y$ 的有向边，边长为 $z$。

接下来 $k$ 行，每行包含两个整数 $x,y$，表示询问点 $x$ 到点 $y$ 的最短距离。

#### 输出格式

共 $k$ 行，每行输出一个整数，表示询问的结果，若询问两点间不存在路径，则输出 `impossible`。

#### 数据范围

$1 \\le n \\le 200$,  
$1 \\le k \\le n^2$  
$1 \\le m \\le 20000$,  
图中涉及边长绝对值均不超过 $10000$。

#### 输入样例：

    3 3 2
    1 2 1
    2 3 2
    1 3 1
    2 1
    1 3
    

#### 输出样例：

    impossible
    1
*/

#include <iostream>
#include <algorithm>
using namespace std;
const int N = 210, INF = 1e9;
int g[N][N];
int n, m, Q;
void floyd() {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}
int main() {
    scanf("%d%d%d", &n, &m, &Q);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (i == j) g[i][j] = 0;
            else g[i][j] = INF;
        }
    for (int i = 0; i < m; i++) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        g[a][b] = min(g[a][b], w);
    }
    floyd();
    while (Q--) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (g[a][b] > INF / 2)puts("impossible");
        else printf("%d\n", g[a][b]);
    }
    return 0;
}