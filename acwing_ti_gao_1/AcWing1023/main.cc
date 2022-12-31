#include <iostream>
using namespace std;
const int N = 1010;
int f[N];
int w[]{ 10,20,50,100 };
int n=4,m;
int main() {
	cin >> m;

	f[0] = 1;
	for (int i = 0; i < 4; i++) 
		for (int j = w[i]; j <= m; j++)
			f[j] += f[j - w[i]];
	cout << f[m] << endl;
	return 0;
}