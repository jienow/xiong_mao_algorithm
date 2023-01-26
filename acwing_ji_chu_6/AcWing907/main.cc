#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
struct Range {
	int l, r;
	bool operator<(const Range& W) {
		return l < W.l;
	}
}range[N];
int main() {
	ios::sync_with_stdio(false);
	int st, ed; cin >> st >> ed;
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> range[i].l >> range[i].r;
	sort(range, range + n);

	bool succ = false;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int j = i, r = -2e9;
		while (j < n && range[j].l <= st) {
			r = max(r, range[j].r);
			j++;
		}
		if (r < st) {
			cnt = -1;
			break;
		}
		cnt++;
		if (r >= ed)
		{
			succ = true;
			break;
		}
		st = r;
		i = j - 1;
	}
	if (!succ) cnt = -1;
	cout << cnt << endl;
	return 0;
}