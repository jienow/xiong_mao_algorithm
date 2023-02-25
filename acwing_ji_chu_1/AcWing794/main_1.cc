#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> div(vector<int>& a, int b, int& r) {
	vector<int> c;
	r = 0;
	for (int i = a.size() - 1; i >= 0; i--) {
		r = r * 10 + a[i];
		c.push_back(r / b);
		r %= b;
	}
	reverse(c.begin(), c.end());
	while (c.back() == 0 && c.size() > 1) c.pop_back();
	return c;
}
int main() {
	string a; int b; cin >> a >> b;
	vector<int> A;
	for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
	int r;
	vector<int> c = div(A, b, r);
	for (int i = c.size() - 1; i >= 0; i--) printf("%d", c[i]);
	cout << endl << r << endl;
	return 0;
}