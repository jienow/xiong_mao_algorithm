/*
*
* ����һ�� $n$ ���� $m$ ���ߵ�����ͼ��ͼ�п��ܴ����رߺ��Ի������б�Ȩ��Ϊ�Ǹ�ֵ��

������� $1$ �ŵ㵽 $n$ �ŵ����̾��룬����޷��� $1$ �ŵ��ߵ� $n$ �ŵ㣬����� $\-1$��

#### �����ʽ

��һ�а������� $n$ �� $m$��

������ $m$ ��ÿ�а����������� $x,y,z$����ʾ����һ���ӵ� $x$ ���� $y$ ������ߣ��߳�Ϊ $z$��

#### �����ʽ

���һ����������ʾ $1$ �ŵ㵽 $n$ �ŵ����̾��롣

���·�������ڣ������ $\-1$��

#### ���ݷ�Χ

$1 \\le n,m \\le 1.5 \\times 10^5$,
ͼ���漰�߳�����С�� $0$���Ҳ����� $10000$��
���ݱ�֤��������·���ڣ������·�ĳ��Ȳ����� $10^9$��

#### ����������

	3 3
	1 2 2
	2 3 1
	1 3 4


#### ���������

	3
*
*
*/



#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int N = 1e6 + 10;
typedef pair<int, int> PII;
int h[N], e[N], ne[N], w[N], idx;
int n, m, dist[N];
bool st[N];
void add(int a, int b, int c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
void dijkstra() {
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	priority_queue<PII, vector<PII>, greater<PII>>heap;
	heap.push({ 0,1 });

	while (heap.size()) {
		auto t = heap.top();
		heap.pop();
		int ver = t.second, distance = t.first;
		if (st[ver]) continue;
		st[ver] = true;

		for (int i = h[ver]; i != -1; i = ne[i]) {
			int j = e[i];
			if (dist[j] > distance + w[i]) {
				dist[j] = distance + w[i];
				heap.push({ dist[j],j });
			}
		}
	}
	if (dist[n] == 0x3f3f3f3f)puts("-1");
	else printf("%d\n", dist[n]);
}
int main() {
	cin >> n >> m;
	memset(h, -1, sizeof h);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
	}
	dijkstra();
	return 0;
}