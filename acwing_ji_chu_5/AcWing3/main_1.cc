#include <iostream>
using namespace std;
const int N = 1010;
int arr[N];
int main() {
	ios::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int v, w; cin >> v >> w;
		for (int j = v; j <= m; j++)
			arr[j] = max(arr[j], arr[j - v] + w);
	}
	cout << arr[m] << endl;
	return 0;
}