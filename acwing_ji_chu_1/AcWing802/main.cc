#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 3e5 + 10;
typedef pair<int,int> PII;
int n, m;
int a[N];
vector<int> alls;
vector<PII> add;
vector<PII> query;
int find(int x) {
	int l = 0, r = alls.size() - 1;
	while (l < r) {
		int mid = l + r >> 1;
		if (alls[mid] >= x) r = mid;
		else l = mid + 1;
	}
	return r + 1;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	while (n--) {
		int x, c; cin >> x >> c;
		alls.push_back(x);
		add.push_back({ x,c });
	}
	while (m--) {
		int l, r; cin >> l >> r;
		alls.push_back(l);
		alls.push_back(r);
		query.push_back({ l,r });
	}

	sort(alls.begin(), alls.end());
	alls.erase(unique(alls.begin(), alls.end()), alls.end());

	for (auto& const item : add) {
		int x = find(item.first);
		a[x] += item.second;
	}

	for (int i = 1; i <= alls.size(); i++)
		a[i] += a[i - 1];
	for (auto& const item : query) {
		int l = find(item.first), r = find(item.second);
		cout << a[r] - a[l - 1] << endl;
	}

	return 0;
}