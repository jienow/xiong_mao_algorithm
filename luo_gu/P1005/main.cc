#include <iostream>
using namespace std;
const int N = 100;
int f[N][N];
int w[N][N];
int n, m;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			cin >> w[i][j];
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{

		}
	return 0;
}

// f[i][j] 第i行，第j次取数总分最大