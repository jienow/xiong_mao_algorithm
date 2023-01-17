#include <iostream>
using namespace std;
const int N = 10010;
int f[N], n, m;
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	f[0] = 1;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		for (int j = m; j >= num; j--)
			f[j] += f[j - num];
	}
	cout << f[m] << endl;

	return 0;
}