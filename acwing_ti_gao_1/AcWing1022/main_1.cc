#include <iostream>
using namespace std;
const int N = 1010;
int f[N][N], n, m, K;
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> K;

	for (int i = 0; i < K; i++) {
		int num, hp; cin >> num >> hp;
		for (int j = n; j >= num; j--)
			for (int k = m; k >= hp; k--)
				f[j][k] = max(f[j][k], f[j - num][k - hp] + 1);
	}
	cout << f[n][m - 1] << " ";

	int hert = m - 1;
	for (int i = hert; i >= 0; i--) {
		if (f[n][i] == f[n][hert]) hert = i;
	}
	cout << m - hert << endl;

	return 0;
}