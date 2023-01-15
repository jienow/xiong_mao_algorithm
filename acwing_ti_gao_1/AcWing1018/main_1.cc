#include <iostream>
using namespace std;
const int N = 110;
int f[N][N];
int main() {
	int n; cin >> n;
	memset(f, 0x3f, sizeof f);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> f[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i == 1 && j == 1) continue;
			else f[i][j] += min(f[i - 1][j], f[i][j - 1]);
	cout << f[n][n] << endl;

	return 0;
}