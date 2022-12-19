#include <iostream>
#include <vector>
using namespace std;
vector<int> mult(vector<int>& A, int b) {
	vector<int> C;
	int t = 0;
	for (int i = 0; i < A.size(); i++)
	{
		t += A[i] * b;
		C.push_back(t % 10);
		t /= 10;
	}
	while (t) {
		C.push_back(t % 10);
		t /= 10;
	}
	while (C.size() > 1 && C.back() == 0)
		C.pop_back();
	return C;
}
void print(vector<int>& C) {
	for (int i = C.size() - 1; i >= 0; i--)
		cout << C[i];
}
int main() {
	string a;
	int b;
	vector<int> A, B;	
	cin >> a >> b;
	for (int i = a.size() - 1; i >= 0; i--)
		A.push_back(a[i] - '0');
	auto C = mult(A, b);
	print(C);
	return 0;
}