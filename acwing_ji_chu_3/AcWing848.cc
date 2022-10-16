/*
����һ�� $n$ ���� $m$ ���ߵ�����ͼ����ı���� $1$ �� $n$��ͼ�п��ܴ����رߺ��Ի���

���������һ��������ͼ���������У�����������в����ڣ������ $\-1$��

��һ����ͼ�����е㹹�ɵ����� $A$ ���㣺����ͼ�е�ÿ���� $(x, y)$��$x$ �� $A$ �ж������� $y$ ֮ǰ����� $A$ �Ǹ�ͼ��һ���������С�

#### �����ʽ

��һ�а����������� $n$ �� $m$��

������ $m$ �У�ÿ�а����������� $x$ �� $y$����ʾ����һ���ӵ� $x$ ���� $y$ ������� $(x, y)$��

#### �����ʽ

��һ�У���������������У����������һ���Ϸ����������м��ɡ�

������� $\-1$��

#### ���ݷ�Χ

$1 \\le n,m \\le 10^5$

#### ����������

	3 3
	1 2
	2 3
	1 3


#### ���������

	1 2 3
*/


#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;
int h[N], e[N], ne[N], idx;
int q[N], d[N], hh, tt = -1;
int n, m;
void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
	d[b]++;
}
bool get_sort() {

	for (int i = 1; i <= n; i++) {
		if (d[i] == 0)
			q[++tt] = i;
	}

	while (hh <= tt) {
		int t = q[hh++];
		for (int i = h[t]; i != -1; i = ne[i]) {
			int j = e[i];
			d[j]--;
			if (d[j] == 0)q[++tt] = j;
		}
	}
	return tt == n - 1;
}
int main() {
	cin >> n >> m;
	memset(h, -1, sizeof h);
	while (m--) {
		int a, b;
		cin >> a >> b;
		add(a, b);
	}
	if (get_sort()) {
		for (int i = 0; i < n; i++)printf("%d ", q[i]);
	}
	else puts("-1");
	return 0;
}