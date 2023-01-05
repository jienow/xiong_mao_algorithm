#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int f[N],sz;
int n, m;
void up(int num) {
	if (num == 1) return ;
	if (f[num / 2] > f[num])
	{
		swap(f[num / 2], f[num]);
		up(num / 2);
	}
}
void down(int num) {
	int t = num;
	if (num * 2 <= sz && f[t * 2] < f[num]) t = t * 2;
	if (num * 2 + 1 <= sz && f[num * 2 + 1] < f[t]) t = num * 2 + 1;
	if (num != t) {
		swap(f[num], f[t]);
		down(t);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (sz = 1; sz <= n; sz++) {
		int a; cin >> a;
		f[sz] = a;
		up(sz);
	}
	sz -= 1;
	while (m--) {
		cout << f[1] << " ";
		f[1] = f[sz];
		sz--;
		down(1);
	}
	return 0;
}