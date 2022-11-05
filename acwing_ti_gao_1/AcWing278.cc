/*
* ���� $N$ �������� $A\_1,A\_2,��,A\_N$������ѡ�����ɸ�����ʹ���ǵĺ�Ϊ $M$�����ж�����ѡ�񷽰���

#### �����ʽ

��һ�а����������� $N$ �� $M$��

�ڶ��а��� $N$ ����������ʾ $A\_1,A\_2,��,A\_N$��

#### �����ʽ

����һ����������ʾ��ѡ��������

#### ���ݷ�Χ

$1 \\le N \\le 100$,  
$1 \\le M \\le 10000$,  
$1 \\le A\_i \\le 1000$,  
�𰸱�֤�� int ��Χ�ڡ�

#### ����������

    4 4
    1 1 2 2
    

#### ���������

    3
*/

#include <iostream>
using namespace std;
const int N = 10010;
int f[N];
int n, m;
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    f[0] = 1;
    for (int i = 0; i < n; i++) {
        int v; cin >> v;
        for (int j = m; j >= v; --j)f[j] += f[j - v];
    }
    cout << f[m] << endl;
	return 0;
}