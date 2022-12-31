#include <iostream>
using namespace std;
const int N = 100010;
int f[N], tmp[N];
int n;
int merge_sort(int l, int r) {
	if (l >= r) return 0;
	int mid = l + r >> 1;
	int all = merge_sort(l, mid) + merge_sort(mid + 1, r);
	int k = 1, i = l, j = mid + 1;
	while (i <= mid && j <= r)
		if (f[i] <= f[j])
			tmp[k++] = f[i++];
		else {
			tmp[k++] = f[j++];
			all++;
		}

}
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> f[i];
	
	cout << merge_sort(1, n);

	return 0;
}