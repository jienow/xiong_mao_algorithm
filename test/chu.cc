#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int main()
{
	int year, xueyuan, ban, liushui, xuehao;
	printf("����ѧ�ţ�");
	scanf("%d", &xuehao);
	char str[][11] = { "�����ѧԺ","����ѧԺ" };
	liushui = xuehao % 100;
	year = xuehao / 1000000;
	ban = (xuehao / 1000) % 10;
	xueyuan = (xuehao / 10000) % 100;
	printf("ѧ����%d����ѧ��", year);
	printf("%s", str[xueyuan - 7]);
	printf("%d���ѧ��,", ban); 
	printf("��ˮ����%.3d.", liushui);

	return 0;
}