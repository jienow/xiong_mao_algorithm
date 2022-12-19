/*
* �� Mars �����ϣ�ÿ�� Mars �˶����������һ���������������������� $N$ �������顣

��������һ����ͷ�����β��ǵ����ӣ���Щ��Ƕ�Ӧ��ĳ����������

���ң��������ڵ��������ӣ�ǰһ�����ӵ�β���һ�����ں�һ�����ӵ�ͷ��ǡ�

��Ϊֻ��������ͨ�����̣������� Mars ������������һ�����٣������ã����������Ӳ��ܾۺϳ�һ�����ӣ�ͬʱ�ͷų����Ա��������յ�������

���ǰһ���������ͷ���Ϊ $m$��β���Ϊ $r$����һ���������ͷ���Ϊ $r$��β���Ϊ $n$����ۺϺ��ͷŵ�����Ϊ $m \\times r \\times n$��Mars ��λ�����²��������ӵ�ͷ���Ϊ $m$��β���Ϊ $n$��

��Ҫʱ��Mars �˾������̼�ס���ڵ��������ӣ�ͨ���ۺϵõ�������ֱ��������ֻʣ��һ������Ϊֹ��

��Ȼ����ͬ�ľۺ�˳��õ����������ǲ�ͬ�ģ��������һ���ۺ�˳��ʹһ�������ͷų������������

���磺�� $N=4$��$4$ �����ӵ�ͷ�����β�������Ϊ $(2��3) (3��5) (5��10) (10��2)$��

�����üǺ� $��$ ��ʾ�������ӵľۺϲ�����$(j��k)$ ��ʾ�� $j$��$k$ �������ӾۺϺ����ͷŵ���������

�� $4��1$ �������ӾۺϺ��ͷŵ�����Ϊ��$(4��1)=10 \\times 2 \\times 3=60$��

��һ���������Եõ�����ֵ��һ���ۺ�˳�����ͷŵ�������Ϊ $((4 \\oplus 1) \\oplus 2) \\oplus 3) = 10 \\times 2 \\times 3+10 \\times 3 \\times 5+10 \\times 5 \\times 10=710$��

#### �����ʽ

����ĵ�һ����һ�������� $N$����ʾ���������ӵĸ�����

�ڶ����� $N$ ���ÿո�����������������е����������� $1000$���� $i$ ����Ϊ�� $i$ �����ӵ�ͷ��ǣ��� $i<N$ ʱ���� $i$ �����ӵ�β���Ӧ�õ��ڵ� $i+1$ �����ӵ�ͷ��ǣ��� $N$ �����ӵ�β���Ӧ�õ��ڵ� $1$ �����ӵ�ͷ��ǡ�

�������ӵ�˳�����������ȷ�����������ŵ������ϣ���Ҫ���ֽ��棬����ָ����һ�����ӣ�Ȼ��˳ʱ�뷽��ȷ���������ӵ�˳��

#### �����ʽ

���ֻ��һ�У���һ�������� $E$��Ϊһ�����žۺ�˳�����ͷŵ���������

#### ���ݷ�Χ

$4 \\le N \\le 100$,  
$1 \\le E \\le 2.1 \\times 10^9$

#### ����������

    4
    2 3 5 10
    

#### ���������

    710
*/

#include <iostream>
using namespace std;
const int N = 210;
int f[N][N];
int n;
int w[N];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) // ��������
    {
        cin >> w[i];
        w[i + n] = w[i];
    }
    for (int len = 3; len <= n + 1; len++)   // ���ȴ�����ʼ��n+1����
        for (int l = 1; l + len - 1 <= 2 * n; l++) // �ұ߽絽2 * n����
        {
            int r = l + len - 1;
            for (int k = l + 1; k < r; k++)
                f[l][r] = max(f[l][r], f[l][k] + f[k][r] + w[l] * w[k] * w[r]); // ת�Ʒ���
        }
    int res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, f[i][i + n]); // �ҵ�����
    cout << res << endl;

	return 0;
}