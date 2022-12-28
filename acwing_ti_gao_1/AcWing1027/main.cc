#include <iostream>
using namespace std;
const int N = 15;
int f[N * 2][N][N];
int w[N][N];
int n;
int main() {
	cin >> n;
	int a, b, c;
	while (cin >> a >> b >> c, a || b || c) w[a][b] = c;
	for (int k = 2; k <= 2 * n; k++)
		for (int i1 = 1; i1 <= n; i1++)
			for (int i2 = 1; i2 <= n; i2++)
			{
				int j1 = k - i1, j2 = k - i2;
				if (j1 >= 1 && j1 <= n && j2 >= 1 && j2 <= n) {
					int& x = f[k][i1][i2];
					int t = w[i1][j1];
					if (i1 != i2) t += w[i2][j2];
					x = max(x, f[k - 1][i1 - 1][i2] + t);
					x = max(x, f[k - 1][i1][i2 - 1] + t);
					x = max(x, f[k - 1][i1 - 1][i2 - 1] + t);
					x = max(x, f[k - 1][i1][i2] + t);
				}
			}
	cout << f[n * 2][n][n] << endl;
	return 0;
}