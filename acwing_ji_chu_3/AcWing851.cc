/*
* ����һ�� $n$ ���� $m$ ���ߵ�����ͼ��ͼ�п��ܴ����رߺ��Ի��� **��Ȩ����Ϊ����**��

������� $1$ �ŵ㵽 $n$ �ŵ����̾��룬����޷��� $1$ �ŵ��ߵ� $n$ �ŵ㣬����� `impossible`��

���ݱ�֤�����ڸ�Ȩ��·��

#### �����ʽ

��һ�а������� $n$ �� $m$��

������ $m$ ��ÿ�а����������� $x,y,z$����ʾ����һ���ӵ� $x$ ���� $y$ ������ߣ��߳�Ϊ $z$��

#### �����ʽ

���һ����������ʾ $1$ �ŵ㵽 $n$ �ŵ����̾��롣

���·�������ڣ������ `impossible`��

#### ���ݷ�Χ

$1 \\le n,m \\le 10^5$,
ͼ���漰�߳�����ֵ�������� $10000$��

#### ����������

	3 3
	1 2 5
	2 3 -3
	1 3 4


#### ���������

	2
*/

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;
int h[N], e[N], ne[N], w[N], idx;
int n, m, dist[N];
int st[N];
void add(int a, int b, int c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
int spfa() {
	memset(dist, 0x3f, sizeof dist);
	queue<int> que;
	que.push(1);
	dist[1] = 0;
	st[1] = true;

	while (que.size()) {
		int t = que.front();
		que.pop();
		st[t] = false;

		for (int i = h[t]; i != -1; i = ne[i]) {
			int j = e[i];
			if (dist[j] > dist[t] + w[i]) { // w����˼�ǵ�ǰ�ڵ�����һ�������Ľڵ��Ȩ��.
				dist[j] = dist[t] + w[i];
				if (!st[j]) 
					que.push(j);
				st[j] = true;
				//�����ڶ�����ָ��ͬһ���ڵ��ʱ��pushһ���Ǹ��ڵ�͹���.
			}
		}
	}
	return dist[n];
}
int main() {
	scanf("%d%d", &n, &m);
	memset(h, -1, sizeof h);
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		add(x, y, z);
	}
	int t = spfa();
	if (t == 0x3f3f3f3f)puts("impossible");
	else printf("%d\n", t);
	return 0;
}