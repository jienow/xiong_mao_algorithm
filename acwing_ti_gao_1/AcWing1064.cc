/*
* �� $n \\times n$ �������Ϸ� $k$ �������������ɹ������ڵ� $8$ �����ӣ���ʹ�����޷����๥���ķ���������

#### �����ʽ

��һ�У������������� $n$ �� $k$��

#### �����ʽ

��һ�У���ʾ���������������ܹ����������$0$��

#### ���ݷ�Χ

$1 \\le n \\le 10$,  
$0 \\le k \\le n^2$

#### ����������

    3 2
    

#### ���������

    16
*/


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;// ���ֻ�������ͽ����еĶ��ĳ�LL

const int N = 12; // ��ǰ����
const int M = 1 << 10, K = 110; // k�ǹ�������
int n, m; // m��ʾ������������Ϊ����ϰ��ʹ��n����ʾһ������m����ʾһ��ֵ
vector<int> state; // ��ʾ���еĺϷ�״̬
int id[M]; // id������ʾÿ��״̬�������±�֮��ĺϷ���ϵ
vector<int> head[M]; // ��ʾÿһ��״̬������ת���Ϊ����״̬
int cnt[M]; // cnt��ʾÿ��״̬����1�ĸ�����

LL f[N][K][M]; // ״̬��ʾ

bool check(int state) // ���һ�������Ƿ�����������ڵ�1
{ 
    for (int i = 0; i < n; i++)
        if ((state >> i & 1) && (state >> i + 1 & 1))
            return false;
    return true;
}

int count(int state) // �������ֶ����Ʊ�ʾ��1�ĸ���
{
    int res = 0;
    for (int i = 0; i < n; i++) res += state >> i & 1;
    return res;
}
int main() {
    cin >> n >> m;
    // �����еĺϷ�״̬�ҳ�������ǰԤ��������
    for (int i = 0; i < 1 << n; i++)
        if (check(i)) 
        {
            state.push_back(i);
            id[i] = state.size() - 1;
            cnt[i] = count(i);
        }

    for (int i = 0; i < state.size(); i++)
        for (int j = 0; j < state.size(); j++)
        {
            int a = state[i], b = state[j];
            if ((a & b) == 0 && check(a | b)) 
            {
                head[i].push_back(j);
            }
        }

    f[0][0][0] = 1;

    for (int i = 1; i <= n + 1; i++)
        for (int j = 0; j <= m; j++)
            for (int a = 0;a < state.size();a ++)
                for (int b : head[a]) 
                {
                    int c = cnt[state[a]];
                    if (j >= c) {
                        f[i][j][a] += f[i - 1][j - c][b];
                    }
                }
    cout << f[n + 1][m][0] << endl;

    return 0;
}