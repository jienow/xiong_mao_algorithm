#include <iostream>
using namespace std;
const int N = 1010;
int b[N][N];
int n, m, q;
void add(int i1, int j1, int i2, int j2, int num) {
	b[i1][j1] += num;
	b[i2 + 1][j1] -= num;
	b[i1][j2 + 1] -= num;
	b[i2 + 1][j2 + 1] += num;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			int num; cin >> num;
			add(i, j, i, j, num);
		}
	while (q--) {
		int x1, x2, y1, y2, num;
		cin >> x1 >> y1 >> x2 >> y2 >> num;
		add(x1, y1, x2, y2, num);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
			cout << b[i][j] << " ";
		}
		cout << endl;
	}

	
	return 0;
}