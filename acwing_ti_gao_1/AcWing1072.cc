/*
* 给定一棵树，树中包含 $n$ 个结点（编号$1$~$n$）和 $n-1$ 条无向边，每条边都有一个权值。

现在请你找到树中的一条最长路径。

换句话说，要找到一条路径，使得使得路径两端的点的距离最远。

注意：路径中可以只包含一个点。

#### 输入格式

第一行包含整数 $n$。

接下来 $n-1$ 行，每行包含三个整数 $a\_i,b\_i,c\_i$，表示点 $a\_i$ 和 $b\_i$ 之间存在一条权值为 $c\_i$ 的边。

#### 输出格式

输出一个整数，表示树的最长路径的长度。

#### 数据范围

$1 \\le n \\le 10000$,  
$1 \\le a\_i,b\_i \\le n$,  
$\-10^5 \\le c\_i \\le 10^5$

#### 输入样例：

    6
    5 1 6
    1 4 5
    6 3 9
    2 6 8
    6 1 7
    

#### 输出样例：

    22
*/


#include <iostream>
#include <cstring>
using namespace std;
const int N = 10010;
int h[N], e[N * 2], ne[N * 2], w[N * 2], idx;
int n, ans;
void add(int a, int b, int c) {
    w[idx] = c, e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int dfs(int u, int father) {
    int dist = 0, d1 = 0, d2 = 0;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (j == father) continue;
        int d = dfs(j, u) + w[i];
        dist = max(dist, d);
        
        if (d >= d1) d2 = d1, d1 = d;
        else if (d > d2) d2 = d;
    }
    ans = max(ans, d1 + d2);
    return dist;
}
int main() {
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    dfs(1, -1);
    cout << ans << endl;
	return 0;
}