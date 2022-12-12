/*
* ˾��Ľ����Ǵ����� $N \\times M$ �������ͼ�ϲ������ǵ��ڱ����ӡ�

һ�� $N \\times M$ �ĵ�ͼ�� $N$ �� $M$ ����ɣ���ͼ��ÿһ�������ɽ�أ��� `H` ��ʾ����Ҳ������ƽԭ���� `P` ��ʾ��������ͼ��

��ÿһ��ƽԭ�����������Բ���һ֧�ڱ����ӣ�ɽ���ϲ��ܹ������ڱ����ӣ���һ֧�ڱ������ڵ�ͼ�ϵĹ�����Χ��ͼ�к�ɫ������ʾ��

![1185_1.jpg](/media/article/image/2019/02/16/19_d512cdba31-1185_1.jpg)

����ڵ�ͼ�еĻ�ɫ����ʶ��ƽԭ�ϲ���һ֧�ڱ����ӣ���ͼ�еĺ�ɫ�������ʾ���ܹ��������������غ������Ҹ��������������¸�����

ͼ��������ɫ���������������

��ͼ�Ͽɼ��ڱ��Ĺ�����Χ���ܵ��ε�Ӱ�졣

���ڣ������ǹ滮��β����ڱ����ӣ��ڷ�ֹ���˵�ǰ���£���֤�κ���֧�ڱ�����֮�䲻�ܻ��๥�������κ�һ֧�ڱ����Ӷ���������֧�ڱ����ӵĹ�����Χ�ڣ�����������ͼ����������ܹ��ڷŶ����Ҿ����ڱ����ӡ�

#### �����ʽ

��һ�а��������ɿո�ָ�����������ֱ��ʾ $N$ �� $M$��

�������� $N$ �У�ÿһ�к��������� $M$ ���ַ�(`P` ���� `H`)���м�û�пո񡣰�˳���ʾ��ͼ��ÿһ�е����ݡ�

#### �����ʽ

��һ�У�����һ������ $K$����ʾ����ܰڷŵ��ڱ����ӵ�������

#### ���ݷ�Χ

$N \\le 100,M \\le 10$

#### ����������

    5 4
    PHPP
    PPHH
    PPPP
    PHPP
    PHHP
    

#### ���������

    6
*/

#include <iostream>
#include <vector>
using namespace std;
const int N = 10, M = 1 << N;
int f[2][M][M];
int g[1010];
vector<int> state;
int cnt[M];
int n, m;
bool check(int state) { // ���һ��״̬�����Ƿ�����
    for (int i = 0; i < m; i++)
        if ((state >> i & 1) && ((state >> i + 1 & 1) || (state >> i + 2) & 1))
            return false;
    return true;
}
int count(int state) // ����һ��״̬�ж��ٸ�1
{
    int res = 0;
    for (int i = 0; i < m; i++)
        if (state >> i & 1)
            res++;
    return res;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) // ��������
        for (int j = 0; j < m; j++)
        {
            char c; cin >> c;
            g[i] += (c == 'H') << j;
        }
    for (int i = 0; i < 1 << m; i++) // �������е�ײ��i
        if (check(i)) { // ���״̬�ĺϷ���
            state.push_back(i);
            cnt[i] = count(i);
        }
    for (int i = 1; i <= n; i++) // ����n��
        for (int j = 0; j < state.size(); j++)
            for (int k = 0; k < state.size(); k++)
                for (int u = 0; u < state.size(); u++) // ����״̬����
                {
                    int a = state[j], b = state[k], c = state[u]; // �õ�״̬
                    if (a & b | b & c | a & c) continue; // ���򲻿���
                    if (g[i] & b) continue; // ɽ�ؼ��
                    f[i & 1][j][k] = max(f[i & 1][j][k], f[i - 1 & 1][u][j] + cnt[b]); 
                    // ������еĵط� j -> k ���Դ� u -> j ��״̬ + ��ǰ״̬������
                }
    int res = 0;
    for (int i = 0; i < state.size(); i++) // �������еĵط������ֵ
        for (int j = 0; j < state.size(); j++)
            res = max(res, f[n & 1][i][j]);
    cout << res << endl;
    return 0;
}
