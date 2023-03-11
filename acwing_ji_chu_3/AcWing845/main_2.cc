#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;
pair<int, int> map[]{ {-1,0},{0,1},{1,0},{0,-1} };
int bfs(string& start) {
	queue<string> q;
	unordered_map<string, int> hash;
	hash[start] = 0;
	string end{ "12345678x" };
	q.push(start);

	while (!q.empty()) {
		string str = q.front();
		q.pop();

		int distance = hash[str];
		if (str == end) return distance;

		int k = str.find('x');
		int xx = k / 3, yy = k % 3;

		for (int i = 0; i < 4; i++) {
			int x = xx + map[i].first, y = yy + map[i].second;
			if (x >= 0 && x <= 2 && y >= 0 && y <= 2) {
				swap(str[k], str[x * 3 + y]);
				if (!hash.count(str)) {
					q.push(str);
					hash[str] = distance + 1;
				}
				swap(str[k], str[x * 3 + y]);
			}
		}
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(false);
	string s, start;
	while (cin >> s) start += s;
	cout << bfs(start);
	return 0;
}