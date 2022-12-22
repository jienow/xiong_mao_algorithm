/*
* ����һ���������а��� $n$ ����㣨���$1$~$n$���� $n-1$ ������ߣ�ÿ���߶���һ��Ȩֵ��

�����������ҵ�һ���㣬ʹ�øõ㵽��������������Զ���������

#### �����ʽ

��һ�а������� $n$��

������ $n-1$ �У�ÿ�а����������� $a\_i,b\_i,c\_i$����ʾ�� $a\_i$ �� $b\_i$ ֮�����һ��ȨֵΪ $c\_i$ �ıߡ�

#### �����ʽ

���һ����������ʾ����㵽��������������Զ���롣

#### ���ݷ�Χ

$1 \\le n \\le 10000$,  
$1 \\le a\_i,b\_i \\le n$,  
$1 \\le c\_i \\le 10^5$

#### ����������

    5 
    2 1 1 
    3 2 1 
    4 3 1 
    5 1 1
    

#### ���������

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
