#include <iostream>
#include <vector>
using namespace std;
bool bigger(vector<int>& a, vector<int>& b) {
	if (a.size() == b.size()) {
		for (int i = a.size() - 1; i >= 0; i--)
			if (a[i] > b[i])return true;
			else if (a[i] < b[i]) return false;
	}
	if (a.size() > b.size()) return true;
	else return false;
}
vector<int> sub(vector<int>& a, vector<int>& b) {
	if (bigger(b,a)) return sub(b, a);
	vector<int> c;
	int t = 0;
	int i;
	for (i = 0; i < b.size(); i++) {
		t += a[i] - b[i];
		if (t >= 0) {
			c.push_back(t);
			t = 0;
		}
		else {
			t += 10;
			c.push_back(t);
			t = -1;
		}
	}
	while (i < a.size()) {
		t += a[i];
		if (t >= 0) {
			c.push_back(t);
			t = 0;
		}
		else {
			t += 10;
			c.push_back(t);
			t = -1;
		}
		i++;
	}
	while (c.back() == 0 && c.size() > 1) c.pop_back();
	return c;
}
int main() {
	ios::sync_with_stdio(false);
	string a, b; cin >> a >> b;
	vector<int> A, B;
	for (int i = a.size() - 1; i >= 0; i--)A.push_back(a[i] - '0');
	for (int i = b.size() - 1; i >= 0; i--)B.push_back(b[i] - '0');
	vector<int> C = sub(A, B);
	if (bigger(B,A))
		cout << "-";
	for (int i = C.size() - 1; i >= 0; i--)
		cout << C[i];
	return 0;
}