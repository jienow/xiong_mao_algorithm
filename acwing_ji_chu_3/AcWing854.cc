/*
* ����һ�� $n$ ���� $m$ ���ߵ�����ͼ��ͼ�п��ܴ����رߺ��Ի�����Ȩ����Ϊ������

�ٸ��� $k$ ��ѯ�ʣ�ÿ��ѯ�ʰ����������� $x$ �� $y$����ʾ��ѯ�ӵ� $x$ ���� $y$ ����̾��룬���·�������ڣ������ `impossible`��

���ݱ�֤ͼ�в����ڸ�Ȩ��·��

#### �����ʽ

��һ�а����������� $n,m,k$��

������ $m$ �У�ÿ�а����������� $x,y,z$����ʾ����һ���ӵ� $x$ ���� $y$ ������ߣ��߳�Ϊ $z$��

������ $k$ �У�ÿ�а����������� $x,y$����ʾѯ�ʵ� $x$ ���� $y$ ����̾��롣

#### �����ʽ

�� $k$ �У�ÿ�����һ����������ʾѯ�ʵĽ������ѯ������䲻����·��������� `impossible`��

#### ���ݷ�Χ

$1 \\le n \\le 200$,  
$1 \\le k \\le n^2$  
$1 \\le m \\le 20000$,  
ͼ���漰�߳�����ֵ�������� $10000$��

#### ����������

    3 3 2
    1 2 1
    2 3 2
    1 3 1
    2 1
    1 3
    

#### ���������

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