#include <iostream>
#include <cstring>
#include <algorithm>
using std::cout, std::cin, std::max, std::endl, std::min;
const int N = 1e5 + 10, M = N * 2;
int h[N], e[M], ne[M], idx, n;
int ans = N;
// h存的是以当前节点为头节点，所相连的节点的链表的头节点
// e存到的是下一个节点的的值，就是表面上的数字
// ne存的是下一个节点的位置.
bool st[N];

void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int dfs(int u) {
	st[u] = true;// 将来路斩断

	int size = 0, sum = 0;
	for (int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i];
		if (st[j]) continue;// 如果这个是来的路，就跳过

		int s = dfs(j);// 获得当前节点所相连接的节点,的子节点总和
		size = max(size, s);// 求最大值
		sum += s;// 加到本节点综合里面
	}

	size = max(size, n - sum - 1);// 求来路的最大值
	ans = min(ans, size);// 求最小值
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
	dfs(1);// dfs肯定会将所有的节点遍历一遍.
	cout << ans << endl;
	return 0;
}