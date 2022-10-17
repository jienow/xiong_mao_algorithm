/*
* ����һ�� $n$ ���� $m$ ���ߵ�����ͼ��ͼ�п��ܴ����رߺ��Ի��� **��Ȩ����Ϊ����**��

�����ж�ͼ���Ƿ���ڸ�Ȩ��·��

#### �����ʽ

��һ�а������� $n$ �� $m$��

������ $m$ ��ÿ�а����������� $x,y,z$����ʾ����һ���ӵ� $x$ ���� $y$ ������ߣ��߳�Ϊ $z$��

#### �����ʽ

���ͼ��**����**��Ȩ��·������� `Yes`��������� `No`��

#### ���ݷ�Χ

$1 \\le n \\le 2000$,
$1 \\le m \\le 10000$,
ͼ���漰�߳�����ֵ�������� $10000$��

#### ����������

	3 3
	1 2 -1
	2 3 4
	3 1 -4


#### ���������

	Yes
*/

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int N = 10010;
int h[N], e[N], ne[N], w[N], idx;
int n, m;
int dist[N], cnt[N];
bool st[N];
void add(int a, int b, int c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
bool spfa() {
	queue<int> que;
	for (int i = 1; i <= n; i++) {
		st[i] = true;
		que.push(i);
	}
	while (que.size()) {
		int t = que.front();
		que.pop();
		st[t] = false;
		for (int i = h[t]; i != -1; i = ne[i]) {
			int j = e[i];
			if (dist[j] > dist[t] + w[i]) {
				dist[j] = dist[t] + w[i];
				cnt[j] = cnt[t] + 1;
				if (cnt[j] >= n) return true;
				if (!st[j]) {
					st[j] = true;
					que.push(j);
				}
			}
		}
	}
	return false;
}
int main() {
	scanf("%d%d", &n, &m);
	memset(h, -1, sizeof h);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
	}
	if (spfa())puts("Yes");
	else printf("No");
	return 0;
}