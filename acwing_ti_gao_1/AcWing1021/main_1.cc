#include <iostream>
using namespace std;
const int N = 3010;
long long f[N], n, m;
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	f[0] = 1;
	for (int i = 0; i < n; i++) {
		int v; cin >> v;
		for (int j = v; j <= m; j++)
			f[j] += f[j - v];
	}
	cout << f[m] << endl;
	return 0;
}