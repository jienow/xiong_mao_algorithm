#include <iostream>
using namespace std;
const int N = 10010;
const int INF = 10000000;
int arr[N];
int main() {
	ios::sync_with_stdio(false);
	int n; cin >> n;
	int res = 0;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 1; i <= n; i++) {
		int Max = -INF;
		int Min = INF;
		for (int j = i; j <= n; j++) {
			Max = max(Max, arr[j]);
			Min = min(Min, arr[j]);
			if (Max - Min == j - i) res++;
		}
	}
	cout << res << endl;

	return 0;
}