#include <iostream>
using namespace std;
const int N = 210, INF = 1e9;
int d[N][N];
int n, m, Q;
void Flody() {
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> Q;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i == j) d[i][j] = 0;
			else d[i][j] = INF;
	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		d[a][b] = min(d[a][b], w);
	}
	Flody();
	while (Q--) {
		int a, b;
		cin >> a >> b;
		if (d[a][b] > INF / 2) cout << "impossible" << endl;
		else cout << d[a][b] << endl;
	}
	return 0;
}