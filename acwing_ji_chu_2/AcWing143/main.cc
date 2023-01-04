#include <iostream>
using namespace std;
const int N = 1e5 + 10, M = 3.1e6 + 10;
int son[M][2], idx;
int arr[N];
int n;
void insert(int num) {
	int p = 0;
	for (int i = 30; ~i; i--) {
		int& s = son[p][num >> i & 1];
		if (!s) s = ++idx;
		p = s;
	}
}
int query(int num) {
	int p = 0, res = 0;
	for (int i = 30; ~i; i--) {
		int s = num >> i & 1;
		if (son[p][!s]) {
			p = son[p][!s];
			res += 1 << i;
		}
		else p = son[p][s];
	}
	return res;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		insert(arr[i]);
	}
	int res = 0;
	for (int i = 0; i < n; i++) res = max(res, query(arr[i]));
	cout << res << endl;
	return 0;
}
