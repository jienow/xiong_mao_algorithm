#include <iostream>
using namespace std;
const int N = 100010;
int b[N];
int n, m;
void add(int i, int j,int num) {
	b[i] += num;
	b[j + 1] -= num;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int n; cin >> n;
		add(i, i, n);
	}
	while (m--) {
		int l, r, num;
		cin >> l >> r >> num;
		add(l, r, num);
	}
	for (int i = 1; i <= n; i++) {
		b[i] += b[i - 1];
		cout << b[i] << " ";
	}



	return 0;
}