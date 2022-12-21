/*
* ����һ���������а��� $n$ ����㣨���$1$~$n$���� $n-1$ ������ߣ�ÿ���߶���һ��Ȩֵ��

���������ҵ����е�һ���·����

���仰˵��Ҫ�ҵ�һ��·����ʹ��ʹ��·�����˵ĵ�ľ�����Զ��

ע�⣺·���п���ֻ����һ���㡣

#### �����ʽ

��һ�а������� $n$��

������ $n-1$ �У�ÿ�а����������� $a\_i,b\_i,c\_i$����ʾ�� $a\_i$ �� $b\_i$ ֮�����һ��ȨֵΪ $c\_i$ �ıߡ�

#### �����ʽ

���һ����������ʾ�����·���ĳ��ȡ�

#### ���ݷ�Χ

$1 \\le n \\le 10000$,  
$1 \\le a\_i,b\_i \\le n$,  
$\-10^5 \\le c\_i \\le 10^5$

#### ����������

    6
    5 1 6
    1 4 5
    6 3 9
    2 6 8
    6 1 7
    

#### ���������

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