#include <iostream>
#include <cstring>
using namespace std;
const int N = 1010, mod = 1e9 + 7;
int f[N], g[N];
int n, m;
int main() {
	ios::sync_with_stdio(false);
	memset(f, -0x3f, sizeof f);
	g[0] = 1;
	f[0] = 0;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int v, w;
		cin >> v >> w;
		for (int j = m; j >= v; j--)
		{
			int maxv = max(f[j], f[j - v] + w);
			int s = 0;
			if (maxv == f[j]) s = g[j];
			if (maxv == f[j - v] + w) s = (s + g[j - v]) % mod;
			f[j] = maxv;
			g[j] = s;
		}
	}
	int res = 0;
	for (int i = 1; i <= m; i++)
		if (f[i] > f[res])
			res = i;
	int s = 0;
	for (int i = 0; i <= m; i++)
		if (f[i] == f[res])
			s = (s + g[i]) % mod;
	cout << s << endl;
	return 0;
}