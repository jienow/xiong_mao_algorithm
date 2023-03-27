#include <iostream>
using namespace std;
const int N = 1010;
int f[N];
int main() {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int v, w; cin >> v >> w;
		for (int j = m; j >= v; j--)
			f[j] = max(f[j], f[j - v] + w);
	}
	cout << f[m] << endl;
	return 0;
}