/*
* Ural ��ѧ�� $N$ ��ְԱ�����Ϊ $1 \\sim N$��

���ǵĹ�ϵ����һ����У��Ϊ�����������ڵ�����ӽڵ��ֱ����˾��

ÿ��ְԱ��һ������ָ���������� $H\_i$ ���������� $1 \\le i \\le N$��

����Ҫ�ٿ�һ����������ᣬ������û��ְԱԸ���ֱ����˾һ��λᡣ

���������������ǰ���£����췽ϣ������һ����ְԱ�λᣬʹ�����вλ�ְԱ�Ŀ���ָ���ܺ������������ֵ��

#### �����ʽ

��һ��һ������ $N$��

������ $N$ �У��� $i$ �б�ʾ $i$ ��ְԱ�Ŀ���ָ�� $H\_i$��

������ $N-1$ �У�ÿ������һ������ $L, K$����ʾ $K$ �� $L$ ��ֱ����˾��

#### �����ʽ

������Ŀ���ָ����

#### ���ݷ�Χ

$1 \\le N \\le 6000$,
$\-128 \\le H\_i \\le 127$

#### ����������

	7
	1
	1
	1
	1
	1
	1
	1
	1 3
	2 3
	6 4
	7 4
	4 5
	3 5


#### ���������

	5
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 6010;
int f[N][2];
int h[N], e[N], ne[N], idx;
int happy[N];
bool has_fa[N];
int n;
void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void dfs(int u) {
	f[u][1] = happy[u];

	for (int i = h[u]; ~i; i = ne[i]) {
		/*
		* ��һ�������������������κγ�����h,e,ne��������ĵط�����value
		* ֵ���д���Ҳ����e[i]�õ��Ľ��
		* ���������������棬ֻ��e[i]�õ�����value��������������i����h[i],ne[i]
		* ���������±�
		*/
		int j = e[i];
		dfs(j);
		f[u][1] += f[j][0];
		f[u][0] += max(f[j][0], f[j][1]);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> happy[i];

	memset(h, -1, sizeof h);
	for (int i = 0; i < n - 1; i++) {
		int l, k;
		cin >> l >> k;
		has_fa[l] = true;
		add(k, l);
	}
	int root = 1;
	while (has_fa[root]) root++;

	dfs(root);
	cout << max(f[root][0], f[root][1]) << endl;

	return 0;
}