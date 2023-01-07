#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;
pair<int, int> map[]{ {1,0},{0,1},{0,-1},{-1,0} };
int bfs(string start) {
	queue<string> que;
	unordered_map<string, int> hash;

	que.push(start);
	hash[start] = 0;
	string end{ "12345678x" };

	while (!que.empty()) {
		auto t = que.front();
		que.pop();

		int distance = hash[t];
		if (t == end) return distance;

		int k = t.find('x');
		int x = k / 3, y = k % 3;

		for (int i = 0; i < 4; i++)
		{
			int ii = x + map[i].first, jj = y + map[i].second;
			if (ii >= 0 && ii < 3 && jj >= 0 && jj < 3) {
				swap(t[k], t[ii * 3 + jj]);
				if (!hash.count(t)) {
					hash[t] = distance + 1;
					que.push(t);
				}
				swap(t[k], t[ii * 3 + jj]);
			}
		}
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(false);
	char c;
	string start;
	for (int i = 0; i < 9; i++)
	{
		cin >> c;
		start += c;
	}
	cout << bfs(start) << endl;
	return 0;
}