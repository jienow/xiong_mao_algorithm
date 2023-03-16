#include <iostream>
using namespace std;
const int N = 110;
int arr[N];
int main() {
	ios::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int s, v, w; cin >> v >> w >> s;
		for (int j = m; j >= v; j--)
			for (int k = 0; k <= s && k * v <= j; k++)
				arr[j] = max(arr[j], arr[j - k * v] + k * w);
	}
	cout << arr[m] << endl;
	return 0;
}