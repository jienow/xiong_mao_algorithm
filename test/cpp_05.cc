#include <iostream>
#include <span>
#include <vector>
using namespace std;
int main() {
	vector<int> ve{ 1,2,3,4,5 };
	for (int i : span<int>(ve)) {
		cout << i << endl;
	}
	return 0;
}