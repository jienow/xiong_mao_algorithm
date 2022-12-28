#include <iostream>
#include <ranges>
#include <vector>
using namespace std;
int main() {
	vector<int> v{ 1,2,3,4,5,6 };
	auto res = v | views::filter([](auto& x) {return x % 2 == 0; }
	) | views::transform([](auto& x) {return x * x; }
	);
	for (auto i : res) {
		cout << i << endl;
	}
	return 0;
}