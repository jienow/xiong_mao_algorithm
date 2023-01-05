#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int f[N], n, m;
void up(int num) {
	if (num == 1) return;
	if (f[num / 2] > f[num]) {
		swap(f[num / 2], f[num]);
		up(num / 2);
	}
}
void down(int num) {
	int t = num;
	if (t * 2 <= n && f[num * 2] < f[t]) t = num * 2;
	if (t * 2 + 1 <= n && f[num * 2 + 1] < f[t]) t = num * 2 + 1;
	if (t != num) {
		swap(f[t], f[num]);
		down(t);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin >> m;
	while (m--) {
		string op; cin >> op;
		if (op[0] == 'I') {
			int a; cin >> a;
			f[++n] = a;
		}
		else if (op == "PM") {
			cout << f[1] << endl;
		}
		else if (op == "DM") {
			f[1] = f[n--];
			down(1);
		}
		else if (op == "D") {
			int k; cin >> k;
			f[k + 1] = 
		}
	}

	return 0;
}