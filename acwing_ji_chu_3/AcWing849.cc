/*
*
* ����һ�� $n$ ���� $m$ ���ߵ�����ͼ��ͼ�п��ܴ����رߺ��Ի������б�Ȩ��Ϊ��ֵ��

������� $1$ �ŵ㵽 $n$ �ŵ����̾��룬����޷��� $1$ �ŵ��ߵ� $n$ �ŵ㣬����� $\-1$��

#### �����ʽ

��һ�а������� $n$ �� $m$��

������ $m$ ��ÿ�а����������� $x,y,z$����ʾ����һ���ӵ� $x$ ���� $y$ ������ߣ��߳�Ϊ $z$��

#### �����ʽ

���һ����������ʾ $1$ �ŵ㵽 $n$ �ŵ����̾��롣

���·�������ڣ������ $\-1$��

#### ���ݷ�Χ

$1 \\le n \\le 500$,  
$1 \\le m \\le 10^5$,  
ͼ���漰�߳���������10000��

#### ����������

    3 3
    1 2 2
    2 3 1
    1 3 4
    

#### ���������

    3
*/




#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 510;
int g[N][N], dist[N];
bool st[N];
int n, m;
void dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        for (int j = 1; j <= n; j++)
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        st[t] = true;
    }
    if (dist[n] == 0x3f3f3f3f)puts("-1");
    else printf("%d", dist[n]);
}
int main() {
    scanf("%d%d", &n, &m);
    memset(g, 0x3f, sizeof g);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = min(g[a][b], c);
    }
    dijkstra();

    return 0;
}