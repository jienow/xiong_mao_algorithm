#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
struct Range {
	int l, r;
	bool operator<(Range const& W) {
		return l < W.l;
	}
}range[N];
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d%d", &range[i].l, &range[i].r);
	sort(range, range + n);

	priority_queue<int, vector<int>, greater<int>> que;

	for (int i = 0; i < n; i++) {
		auto r = range[i];
		if (que.empty() || que.top() >= r.l)que.push(r.r);
		else {
			que.pop();
			que.push(r.r);
		}
	}
	cout << que.size() << endl;


	return 0;
} 