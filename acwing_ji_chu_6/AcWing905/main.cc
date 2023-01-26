#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
struct Range {
	int l, r;
	bool operator<(Range const& W)
	{
		return r < W.r;
	}
}range[N];
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) scanf("%d%d", &range[i].l, &range[i].r);
	sort(range, range + n);

	int cnt = 0, end = -2e9;
	for (int i = 0; i < n; i++)
		if (range[i].l > end) {
			cnt++;
			end = range[i].r;
		}
	cout << cnt << endl;

	return 0;
}