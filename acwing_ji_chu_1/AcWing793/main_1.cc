#include <iostream>
#include <vector>
using namespace std;
vector<int> mult(vector<int>& a, int b) {
	vector<int> c;
	int t = 0;
	for (int i = 0; i < a.size(); i++) {
		t += a[i] * b;
		c.push_back(t % 10);
		t /= 10;
	}
	while (t) {
		c.push_back(t % 10);
		t /= 10;
	}
	while (c.back() == 0 && c.size() > 1) c.pop_back();
	return c;
}
int main() {
	ios::sync_with_stdio(false);
	string a;int b; cin >> a >> b;
	vector<int> A;
	for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
	vector<int> c = mult(A, b);
	for (int i = c.size() - 1; i >= 0; i--)
		cout << c[i];
	return 0;
}