#include <iostream>
using namespace std;
const int N = 1010;
int f[N][N], T;
int main() {
	ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		int r, c; cin >> r >> c;
		for (int i = 1; i <= r; i++)
			for (int j = 1; j <= c; j++)
				cin >> f[i][j];
		for (int i = 1; i <= r; i++)
			for (int j = 1; j <= c; j++)
				f[i][j] += max(f[i - 1][j], f[i][j - 1]);
		cout << f[r][c] << endl;
	}


	return 0;
}