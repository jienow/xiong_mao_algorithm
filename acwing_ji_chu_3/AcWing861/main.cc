#include <cstring>
#include <iostream>
using namespace std;
const int N = 510, M = 1e5 + 10;
int h[N], e[M], ne[M], idx;
int match[N], n1, n2, m;
bool st[N];
void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
bool find(int u) {
	for (int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i];
		if (!st[j]) {
			st[j] = true;
			if (match[j] == 0 || find(match[j]))
			{
				match[j] = u;
				return true;
			}
		}
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n1 >> n2 >> m;
	memset(h, -1, sizeof h);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		add(a, b);
	}
	int res = 0;
	for (int i = 1; i <= n1; i++) {
		memset(st, false, sizeof st);
		if (find(i)) res++;
	}
	cout << res << endl;
	return 0;
}