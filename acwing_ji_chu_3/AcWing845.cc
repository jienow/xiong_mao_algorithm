/*
* ��һ�� $3��3$ �������У�$1 \\sim 8$ �� $8$ �����ֺ�һ�� `x` ǡ�ò��ز�©�طֲ����� $3 \\times 3$ �������С�

���磺

	1 2 3
	x 4 6
	7 5 8


����Ϸ�����У����԰� `x` �����ϡ��¡������ĸ�����֮һ�����ֽ�����������ڣ���

���ǵ�Ŀ����ͨ��������ʹ�������Ϊ�������У���Ϊ��ȷ���У���

	1 2 3
	4 5 6
	7 8 x


���磬ʾ����ͼ�ξͿ���ͨ���� `x` �Ⱥ����ҡ��¡���������������ֽ����ɹ��õ���ȷ���С�

�����������£�

	1 2 3   1 2 3   1 2 3   1 2 3
	x 4 6   4 x 6   4 5 6   4 5 6
	7 5 8   7 5 8   7 x 8   7 8 x


���ڣ�����һ����ʼ������������õ���ȷ����������Ҫ���ж��ٴν�����

#### �����ʽ

����ռһ�У��� $3 \\times 3$ �ĳ�ʼ������������

���磬�����ʼ����������ʾ��

	1 2 3
	x 4 6
	7 5 8


������Ϊ��`1 2 3 x 4 6 7 5 8`

#### �����ʽ

���ռһ�У�����һ����������ʾ���ٽ���������

��������ڽ������������� $\-1$��

#### ����������

	2 3 4 1 5 x 7 6 8


#### �������

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