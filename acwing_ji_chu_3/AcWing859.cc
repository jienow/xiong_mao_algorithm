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

$1 \\le n \\le 10^5$,
$1 \\le m \\le 2\*10^5$,
ͼ���漰�ߵı�Ȩ�ľ���ֵ�������� $1000$��

#### ����������

	4 5
	1 2 1
	1 3 2
	1 4 3
	2 3 2
	3 4 4


#### ���������

	6
*/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 2e5 + 10, INF = 0x3f3f3f3f;
struct edge {
	int a, b, w;
	bool operator<(edge& W) {
		return w < W.w;
	}
}edges[N];
int n, m, p[N];
int find(int x) {
	if (x != p[x]) p[x] = find(p[x]);
	return p[x];
}
int krustrl() {
	sort(edges, edges + n);
	for (int i = 1; i <= n; ++i)p[i] = i;
	int res = 0, cnt = 0;
	for (int i = 0; i < m; ++i) {
		int a1 = edges[i].a, b1 = edges[i].b, w = edges[i].w;
		int a = find(a1), b = find(b1);
		if (a != b) {
			p[a] = b;
			res += w;
			cnt++;
		}
	}
	if (cnt < n - 1)return INF;//n���ڵ�Ӧ����n-1����
	else return res;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		edges[i] = { a,b,w };
	}
	int res = krustrl();
	if (res == INF)puts("impossible");
	else printf("%d\n", res);
	return 0;
}