#include <iostream>
#include <vector>
using namespace std;
vector<int> div(vector<int>& A, int b,int &r) {
	vector<int> res;
	int t = 0;
	for (int i = A.size() - 1; i >= 0; i--) {
		t = r * 10 + A[i];
		res.push_back(t / b);
		r = t % b;
	}
	reverse(res.begin(), res.end());
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
	int r = 0;
	vector<int> res = div(A, b,r);
	for (int i = res.size() - 1; i >= 0; i--)
		cout << res[i];
	cout << endl << r << endl;
	return 0;
}