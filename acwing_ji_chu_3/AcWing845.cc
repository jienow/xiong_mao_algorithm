/*
* 在一个 $3×3$ 的网格中，$1 \\sim 8$ 这 $8$ 个数字和一个 `x` 恰好不重不漏地分布在这 $3 \\times 3$ 的网格中。

例如：

	1 2 3
	x 4 6
	7 5 8


在游戏过程中，可以把 `x` 与其上、下、左、右四个方向之一的数字交换（如果存在）。

我们的目的是通过交换，使得网格变为如下排列（称为正确排列）：

	1 2 3
	4 5 6
	7 8 x


例如，示例中图形就可以通过让 `x` 先后与右、下、右三个方向的数字交换成功得到正确排列。

交换过程如下：

	1 2 3   1 2 3   1 2 3   1 2 3
	x 4 6   4 x 6   4 5 6   4 5 6
	7 5 8   7 5 8   7 x 8   7 8 x


现在，给你一个初始网格，请你求出得到正确排列至少需要进行多少次交换。

#### 输入格式

输入占一行，将 $3 \\times 3$ 的初始网格描绘出来。

例如，如果初始网格如下所示：

	1 2 3
	x 4 6
	7 5 8


则输入为：`1 2 3 x 4 6 7 5 8`

#### 输出格式

输出占一行，包含一个整数，表示最少交换次数。

如果不存在解决方案，则输出 $\-1$。

#### 输入样例：

	2 3 4 1 5 x 7 6 8


#### 输出样例

	19
*/

#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
int dx[]{ 1,0,-1,0 }, dy[]{ 0,1,0,-1 };
int bfs(string& start) {
	queue<string> que;
	unordered_map<string, int> hash;
	
	que.push(start);
	string end{ "12345678x" };
	hash[start] = 0;

	while (que.size()) {
		auto s = que.front();
		que.pop();

		int distance = hash[s];
		if (s == end) return distance;

		int k = s.find('x');
		int xx = k / 3, yy = k % 3;

		for (int i = 0; i < 4; i++) {
			int x = xx + dx[i], y = yy + dy[i];
			if (x >= 0 && x < 3 && y >= 0 && y < 3) {
				swap(s[k], s[x * 3 + y]);
				if (!hash.count(s)) {
					que.push(s);
					hash[s] = distance + 1;
				}
				swap(s[k], s[x * 3 + y]);
			}
		}
	}
	return -1;
}
int main() {
	string s, start;
	while (cin >> s) start += s;
	cout << bfs(start) << endl;
	return 0;
}