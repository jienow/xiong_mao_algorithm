#include <iostream>
using namespace std;
const int N = 20020;
int f[N];
int n, m;
int main() {
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		int v; cin >> v;
		for (int j = m; j >= v; j--)
			f[j] = max(f[j], f[j - v] + v);
	}
	cout << m - f[m] << endl;
	return 0;
}