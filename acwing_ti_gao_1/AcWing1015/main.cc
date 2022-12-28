#include <iostream>
using namespace std;
const int N = 110;
int f[N][N];
int n;
int row, col;
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	while (n--) {
		cin >> row >> col;
		for (int i = 1; i <= row; i++)
			for (int j = 1; j <= col; j++)
				cin >> f[i][j];
		for (int i = 1; i <= row; i++)
			for (int j = 1; j <= col; j++)
				f[i][j] += max(f[i - 1][j], f[i][j - 1]);
		cout << f[row][col] << endl;
	}
	return 0;
}