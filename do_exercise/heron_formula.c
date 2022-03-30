#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
//判断三点能否构成三角形，并求其面积
//思路：找出三条边，两边之和大于第三边；海伦公式求面积
int main()
{
	double x1, x2, x3, y1, y2, y3;//定义三点各自坐标
	scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);//记录3点数据
	double s1, s2, s3;//定义三边
	s1 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	s2 = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
	s3 = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
	if (s1 + s2 > s3 && s1 + s3 > s2 && s2 + s3 > s1)
	{
		double primeter = s1 + s2 + s3;
		double p = primeter / 2;
		double area = sqrt(p * (p - s1) * (p - s2) * (p - s3));
		printf("%.2lf", area);
	}
	else
	{
		printf("impossible");
	}
	return 0;
}