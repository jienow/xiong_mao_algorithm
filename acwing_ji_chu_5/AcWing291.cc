/*
*��� $N \\times M$ �����̷ָ�����ɸ� $1 \\times 2$ �ĳ����Σ��ж����ַ�����

���統 $N=2��M=4$ ʱ������ $5$ �ַ������� $N=2��M=3$ ʱ������ $3$ �ַ�����

����ͼ��ʾ��

![2411_1.jpg](/media/article/image/2019/01/26/19_4dd1644c20-2411_1.jpg)

#### �����ʽ

��������������������

ÿ���������ռһ�У������������� $N$ �� $M$��

���������� $N=0��M=0$ ʱ����ʾ������ֹ���Ҹ��������账��

#### �����ʽ

ÿ�������������һ�������ÿ�����ռһ�С�

#### ���ݷ�Χ

$1 \\le N,M \\le 11$

#### ����������

    1 2
    1 3
    1 4
    2 2
    2 3
    2 4
    2 11
    4 11
    0 0
    

#### ���������

    1
    0
    1
    2
    3
    5
    144
    51205 
*/


#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int N = 12, M = 1 << N;
int n, m;
long long f[N][M];
vector<int> state[M];
bool st[M];

int main() {
    
    while (cin >> n >> m, n || m) {
        for (int i = 0; i < (1 << n); i++) {
            int cnt = 0;
            bool is_vaild = true;
            for (int j = 0; j < n; j++)
            {
                if ((i >> j) & 1) {
                    if (cnt & 1) {
                        is_vaild = false; break;
                    }
                    cnt = 0;
                }
                else cnt++;
            }
            if (cnt & 1) is_vaild = false;
            st[i] = is_vaild;
        }


        for (int i = 0; i < (1 << n); i++) {
            state[i].clear();
            for (int j = 0; j < (1 << n); j++)
                if ((i & j) == 0 && st[i | j])
                    state[i].push_back(j);
        }

        memset(f, 0, sizeof f);
        f[0][0] = 1;

        for (int i = 1; i <= m; i++)
            for (int j = 0; j < (1 << n); j++)
                for (int k : state[j])
                    f[i][j] += f[i - 1][k];
        cout << f[m][0] << endl;

    }

    return 0;
}