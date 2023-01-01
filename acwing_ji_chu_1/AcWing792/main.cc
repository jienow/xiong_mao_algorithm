#include <iostream>
#include <vector>
using namespace std;
bool cmp(vector<int>& A, vector<int>& B) {
	if (A.size() != B.size()) return A.size() < B.size();
	for (int i = A.size() - 1; i >= 0; i--)
	{
		if (A[i] > B[i]) return false;
		else if (A[i] < B[i]) return true;
	}
	return false;
}
vector<int> sub(vector<int>& A, vector<int>& B) {
	if (cmp(A,B)) return sub(B, A);
	vector<int> res;
	int t = 0;
	for (int i = 0; i < A.size(); i++) {
		int ans = A[i] + t;
		if (i < B.size()) ans -= B[i];
		if (ans < 0) {
			ans += 10;
			t = -1;
		}
		else t = 0;
		res.push_back(ans);
	}
	while (res.size() > 1 && res.back() == 0) res.pop_back();
	return res;
}
int main() {
	ios::sync_with_stdio(false);
	string a, b;
	vector<int> A, B;
	cin >> a >> b;
	for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
	for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');

	vector<int> res = sub(A, B);
	if (cmp(A, B)) cout << "-";
	for (int i = res.size() - 1; i >= 0; i--) cout << res[i];

	return 0;
}