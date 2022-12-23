#include <iostream>
using namespace std;
const int N = 50000 + 10;
int h[N], e[N], ne[N], idx;
int d1[N], d2[N], sum[N];
int res, n;
void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void dfs(int u) {
	if (d1[u]) return;
	for (int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i];
		dfs(j);
		if (d1[j] + 1 >= d1[u])
		{
			d2[u] = d1[u], d1[u] = d1[j] + 1;
		}
		else if (d1[j] + 1 > d2[u])
		{
			d2[u] = d1[j] + 1;
		}
	}
	res = max(res, d1[u] + d2[u]);
}
int main() {
	cin >> n;
	memset(h, -1, sizeof h);
	for (int i = 1; i <= n; i++)
		for (int j = 2; j <= n / i; j++)
			sum[i * j] += i;
	for (int i = 2; i <= n; i++)
		if (sum[i] < i)
			add(sum[i], i);
	for (int i = 1; i <= n; i++)dfs(i);
	cout << res << endl;
	return 0;
}