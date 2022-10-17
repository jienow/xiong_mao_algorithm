/*
*
* ����һ�� $n$ ���� $m$ ���ߵ�����ͼ��ͼ�п��ܴ����رߺ��Ի��� **��Ȩ����Ϊ����**��

��������� $1$ �ŵ㵽 $n$ �ŵ����ྭ�� $k$ ���ߵ���̾��룬����޷��� $1$ �ŵ��ߵ� $n$ �ŵ㣬��� `impossible`��

ע�⣺ͼ�п��� **���ڸ�Ȩ��·** ��

#### �����ʽ

��һ�а����������� $n,m,k$��

������ $m$ �У�ÿ�а����������� $x,y,z$����ʾ����һ���ӵ� $x$ ���� $y$ ������ߣ��߳�Ϊ $z$��

��ı��Ϊ $1 \\sim n$��

#### �����ʽ

���һ����������ʾ�� $1$ �ŵ㵽 $n$ �ŵ����ྭ�� $k$ ���ߵ���̾��롣

�������������������·��������� `impossible`��

#### ���ݷ�Χ

$1 \\le n,k \\le 500$,
$1 \\le m \\le 10000$,
$1 \\le x,y \\le n$��
����߳��ľ���ֵ������ $10000$��

#### ����������

	3 3 1
	1 2 1
	2 3 1
	1 3 3


#### ���������

	3
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 510, M = 100010;
struct edge {
	int a, b, w;
}edges[M];
int dist[N], backup[N];
int n, m, k;
void bellen_force() {
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	for (int i = 0; i < k; i++) {
		memcpy(backup, dist, sizeof dist);
		for (int j = 0; j < m; j++) {
			int a = edges[j].a, b = edges[j].b, w = edges[j].w;
			dist[b] = min(dist[b], backup[a] + w);
		}
	}
	if (dist[n] > 0x3f3f3f3f / 2)puts("impossible");
	else printf("%d", dist[n]);
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		edges[i] = { a,b,w };
	}
	bellen_force();
	return 0;
}