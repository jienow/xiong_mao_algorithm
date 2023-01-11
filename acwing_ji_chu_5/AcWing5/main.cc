#include <iostream>
#include <vector>
using namespace std;
const int N = 2020;
struct E {
	int v, w;
};
int f[N], n, m;
int main() {
	ios::sync_with_stdio(false);
	vector<E> vec;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int v, w, s; cin >> v >> w >> s;
		for (int k = 1; k <= s; k *= 2) {
			s -= k;
			vec.push_back({ k * v, k * w });
		}
		if (s != 0)	vec.push_back({ s * v,s * w });
	}
	for (auto& i : vec)
		for (int j = m; j >= i.v; j--)
			f[j] = max(f[j], f[j - i.v] + i.w);
	cout << f[m] << endl;

	return 0;
}