#include <iostream>
using namespace std;
const int N = 100010;
int h[N], e[N * 2], ne[N * 2], idx;
int n;
void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n;

	while (n--) {
		string a; cin >> a;
		if (a == "H") {
			int num; cin >> num;
			add(0, num);
		}
	}


	return 0;
}