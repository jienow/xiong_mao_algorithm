#include <iostream>
#include <vector>
using namespace std;
vector<int> mult(vector<int>& A, int b) {
	vector<int> res;
	int t = 0;
	for (int i = 0; i < A.size(); i++) {
		t += A[i] * b;
		res.push_back(t % 10);
		t /= 10;
	}
	while (t) {
		res.push_back(t % 10);
		t /= 10;
	}
	while (res.size() > 1 && res.back() == 0) res.pop_back();
	return res;
}
int main() {
	ios::sync_with_stdio(false);
	string a;
	vector<int> A;
	int b;
	cin >> a >> b;
	for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
	auto res = mult(A, b);
	for (int i = res.size() - 1; i >= 0; i--)
		cout << res[i];

	return 0;
}