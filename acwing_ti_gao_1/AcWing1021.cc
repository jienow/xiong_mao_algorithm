/*
* ����һ��n����ֵ�Ļ���ϵͳ���������ֵΪm�Ļ����ж����ַ�����

#### �����ʽ

��һ�У�������������n��m��

������n�У�ÿ�а���һ����������ʾһ�ֻ��ҵ���ֵ��

#### �����ʽ

��һ�У�����һ����������ʾ��������

#### ���ݷ�Χ

$n \\le 15, m \\le 3000$

#### ����������

    3 10
    1
    2
    5
    

#### ���������

    10
*/

#include <iostream>
using namespace std;
const int N = 3010;
using LL = long long;
LL f[N];
int n, m;
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    f[0] = 1;
    for (int i = 0; i < n; i++) {
        int v; cin >> v;
        for (int j = v; j <= m; j++)
            f[j] += f[j - v];
    }
    cout << f[m] << endl;
	return 0;
} 