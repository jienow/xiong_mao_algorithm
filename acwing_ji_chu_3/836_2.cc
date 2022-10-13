#include <iostream>
#include <cstring>
#include <algorithm>
using std::cout, std::cin, std::max, std::endl, std::min;
const int N = 1e5 + 10, M = N * 2;
int h[N], e[M], ne[M], idx, n;
int ans = N;
// h������Ե�ǰ�ڵ�Ϊͷ�ڵ㣬�������Ľڵ�������ͷ�ڵ�
// e�浽������һ���ڵ�ĵ�ֵ�����Ǳ����ϵ�����
// ne�������һ���ڵ��λ��.
bool st[N];

void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int dfs(int u) {
	st[u] = true;// ����·ն��

	int size = 0, sum = 0;
	for (int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i];
		if (st[j]) continue;// ������������·��������

		int s = dfs(j);// ��õ�ǰ�ڵ��������ӵĽڵ�,���ӽڵ��ܺ�
		size = max(size, s);// �����ֵ
		sum += s;// �ӵ����ڵ��ۺ�����
	}

	size = max(size, n - sum - 1);// ����·�����ֵ
	ans = min(ans, size);// ����Сֵ
	return sum + 1;
}
int main() {
	scanf("%d", &n);
	memset(h, -1, sizeof h);
	for (int i = 0;i < n-1;i ++){
		int a, b;
		scanf("%d%d", &a, &b);
		add(a, b), add(b, a);
	}
	dfs(1);// dfs�϶��Ὣ���еĽڵ����һ��.
	cout << ans << endl;
	return 0;
}