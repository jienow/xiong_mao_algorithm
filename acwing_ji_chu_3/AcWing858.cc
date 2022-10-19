/*
* ����һ�� $n$ ���� $m$ ���ߵ�����ͼ��ͼ�п��ܴ����رߺ��Ի�����Ȩ����Ϊ������

����С������������Ȩ��֮�ͣ������С����������������� `impossible`��

����һ�űߴ�Ȩ������ͼ $G=(V, E)$������ $V$ ��ʾͼ�е�ļ��ϣ�$E$ ��ʾͼ�бߵļ��ϣ�$n=|V|$��$m=|E|$��

�� $V$ �е�ȫ�� $n$ ������� $E$ �� $n-1$ ���߹��ɵ�������ͨ��ͼ����Ϊ $G$ ��һ�������������бߵ�Ȩֵ֮����С������������Ϊ����ͼ $G$ ����С��������

#### �����ʽ

��һ�а����������� $n$ �� $m$��

������ $m$ �У�ÿ�а����������� $u,v,w$����ʾ�� $u$ �͵� $v$ ֮�����һ��ȨֵΪ $w$ �ıߡ�

#### �����ʽ

��һ�У���������С�������������һ����������ʾ��С������������Ȩ��֮�ͣ������С����������������� `impossible`��

#### ���ݷ�Χ

$1 \\le n \\le 500$,
$1 \\le m \\le 10^5$,
ͼ���漰�ߵı�Ȩ�ľ���ֵ�������� $10000$��

#### ����������

	4 5
	1 2 1
	1 3 2
	1 4 3
	2 3 2
	3 4 4


#### ���������

	6
*
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 510, INF = 0x3f3f3f3f;
int g[N][N], dist[N];
bool st[N];
int n, m;
int prim() {
	memset(dist, 0x3f, sizeof dist);
	int res = 0;
	for (int i = 0; i < n; i++) {
		int t = -1;
		for (int j = 1; j <= n; j++) {
			if (!st[j] && (t == -1 || dist[t] > dist[j]))
				t = j;
		}
		if (i && dist[t] == INF) {
			return INF;
		}
		if (i) res += dist[t];
		for (int j = 1; j <= n; j++)dist[j] = min(dist[j], g[t][j]);
		st[t] = true;
	}
	return res;
}
int main() {
	scanf("%d%d", &n, &m);
	memset(g, 0x3f, sizeof g);
	for (int i = 0; i < m; i++) {
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		g[a][b] = g[b][a] = min(g[a][b], w);
	}
	int t = prim();
	if (t == INF)puts("impossible");
	else printf("%d\n", t);
	return 0;
}