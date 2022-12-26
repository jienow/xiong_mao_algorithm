/*
*	��ս����Ϸ��ͬ����
*		ս����Ϸ��Ŀ������ߣ����Ǳߵÿ��꣬���������û����˾�������һ����
*		�����Ŀ��Ŀ������㣬ÿ���㶼�ÿ��꣬������������治һ��
*   f[i][0] ������Ǹ��ڵ�ѡ��sum (f[j][1] + f[j][2])
*   f[i][1] ��������ӽڵ������һ��ѡ������ѡһ���ܺ���С�ģ�Ȼ��
			f[j][2]����˼��ѡ����ڵ�Ŷ���
			f[u][0] - min(f[j][1],f[j][2])����˼�ǳ�ȥ��ǰ�ڵ������ڵ�ĺ�
*			f[j][2] + f[u][0] - min( f[j][1] , f[j][2])
*   f[i][2] �����˵�ǰ�ڵ�ѡ���ӽڵ����⣬������һ����Сֵ����
			sum (min(min(f[j][0],f[j][1]),f[j][2]))
*/

#include <iostream>
#include <cstring>
using namespace std;
const int N = 1510;
int f[N][3], h[N],w[N], ne[N], e[N], idx;
bool st[N];
int n;
void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void dfs(int u) {
	f[u][0] = 0;
	f[u][1] = 1e9;
	f[u][2] = w[u];
	for (int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i];
		dfs(j);
		f[u][0] += min(f[j][1], f[j][2]);
		f[u][2] += min(min(f[j][0], f[j][1]), f[j][2]);
	}
	for (int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i];
		f[u][1] = min(f[u][1], f[j][2] + f[u][0] - min(f[j][1], f[j][2]));
	}
}
int main() {
	cin >> n;
	memset(h, -1, sizeof h);
	for (int i = 1; i <= n; i++) {
		int idx, cost, cnt;
		cin >> idx >> cost >> cnt;
		w[idx] = cost;
		while (cnt--) {
			int ver; cin >> ver;
			add(idx, ver);
			st[ver] = true;
		}
	}
	int root = 1;
	while (st[root]) root++;
	dfs(root);
	cout << min(f[root][1], f[root][2]) << endl;
	
	return 0;
}