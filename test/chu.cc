#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int main()
{
	int year, xueyuan, ban, liushui, xuehao;
	printf("输入学号：");
	scanf("%d", &xuehao);
	char str[][11] = { "计算机学院","体育学院" };
	liushui = xuehao % 100;
	year = xuehao / 1000000;
	ban = (xuehao / 1000) % 10;
	xueyuan = (xuehao / 10000) % 100;
	printf("学生是%d年入学的", year);
	printf("%s", str[xueyuan - 7]);
	printf("%d班的学生,", ban); 
	printf("流水号是%.3d.", liushui);

	return 0;
}