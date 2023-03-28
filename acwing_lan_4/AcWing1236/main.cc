#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
typedef long long LL;
int arr[3][N];
int main() {
	ios::sync_with_stdio(false);
	int n; cin >> n;
	for (int i = 0; i < 3; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	for (int i = 0; i < 3; i++)
		sort(arr[i] + 1, arr[i] + n + 1);
	LL ans = 0;
	for (int i = 1; i <= n; i++) {
		int key = arr[1][i];
		int pos1 = lower_bound(arr[0] + 1, arr[0] + n + 1, key) - arr[0] - 1;
		int pos2 = upper_bound(arr[2] + 1, arr[2] + n + 1, key) - arr[2];
		if (pos1 >= 1 && pos2 <= n) {
			ans += (LL)pos1 * (LL)(n - pos2 + 1);
		}
	}
	cout << ans << endl;
	return 0;
}