#include <iostream>
using namespace std;
const int N = 1010;
int arr[N][N], n, m, q;
void add(int x1, int y1, int x2, int y2, int num) {
	arr[x1][y1] += num;
	arr[x1][y2 + 1] -= num;
	arr[x2 + 1][y1] -= num;
	arr[x2 + 1][y2 + 1] += num;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			int num; cin >> num;
			add(i, j, i, j, num);
		}
	while (q--) {
		int x1, y1, x2, y2, num; cin >> x1 >> y1 >> x2 >> y2 >> num;
		add(x1, y1, x2, y2, num);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}