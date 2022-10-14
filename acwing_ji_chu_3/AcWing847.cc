/*
* ����һ�� $n$ ���� $m$ ���ߵ�����ͼ��ͼ�п��ܴ����رߺ��Ի���

���бߵĳ��ȶ��� $1$����ı��Ϊ $1 \\sim n$��

������� $1$ �ŵ㵽 $n$ �ŵ����̾��룬����� $1$ �ŵ��޷��ߵ� $n$ �ŵ㣬��� $\-1$��

#### �����ʽ

��һ�а����������� $n$ �� $m$��

������ $m$ �У�ÿ�а����������� $a$ �� $b$����ʾ����һ���� $a$ �ߵ� $b$ �ĳ���Ϊ $1$ �ıߡ�

#### �����ʽ

���һ����������ʾ $1$ �ŵ㵽 $n$ �ŵ����̾��롣

#### ���ݷ�Χ

$1 \\le n,m \\le 10^5$

#### ����������

    4 5
    1 2
    2 3
    3 4
    1 3
    1 4
    

#### ���������

    1
*/

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;
int h[N], e[N], ne[N], idx;
int n, m, d[N];
void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int bfs() {
    queue<int> que;
    que.push(1);
    memset(d, -1, sizeof d);
    d[1] = 0;

    while (!que.empty()) { // que��value����,d��value����
        int a = que.front();
        que.pop();
        
        for (int i = h[a]; i != -1; i = ne[i]) {
            // e��ne��ڵ����
            int j = e[i];

            if (d[j] == -1) {
                d[j] = d[a] + 1;
                que.push(j);
            }
        }
    }
    return d[n];
}
int main() {
    cin >> n >> m;

    memset(h, -1, sizeof h);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    cout << bfs() << endl;
    return 0;
}