#include <iostream>
using namespace std;
const int N = 3010;
typedef long long LL;
LL f[N];
int n, m;
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		LL v; cin >> v;
		for (int j = v; j <= m; j++)
			f[j] += f[j - v];
	}
	cout << f[m] << endl;
	return 0;
}