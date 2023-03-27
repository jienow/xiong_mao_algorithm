#include <iostream>
using namespace std;
const int N = 1010;
int arr[N];
int f[N];
int main() {
	ios::sync_with_stdio(false);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		f[i] = 1;
		for (int j = 1; j <= i; j++)
			if (arr[i] > arr[j])
				f[i] = max(f[i], f[j] + 1);
		ans = max(ans, f[i]);
	}
	cout << ans << endl;
	return 0;
}