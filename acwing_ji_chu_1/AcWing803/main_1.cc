#include <algorithm>
#include <iostream>
using namespace std;
const int N = 100000 + 10;
typedef pair<int, int> PII;
PII arr[N];
int main() {
	ios::sync_with_stdio(false);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int l, r; cin >> l >> r;
		arr[i] = { l,r };
	}
	sort(arr, arr + n);
	int r = -2e9, res = 0;
	for (int i = 0; i < n; i++) {
		PII item = arr[i];
		if (r < item.first) {
			r = item.second;
			res++;
		}
		else if (r <= item.second) {
			r = item.second;
		}
	}
	cout << res << endl;
	return 0;
}