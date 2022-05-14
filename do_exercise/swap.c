#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//写一个宏，可以将一个整数的二进制位的奇数位和偶数位交换。


//以15为例
//00000000000000000000000000001111
//                                                        0101
//														   1010
//要拿到a的奇数位，就 & 0x55555555
//此时得到的数a1保留了a的奇数位，偶数位全部置0

//要拿到a的偶数位，就 & 0xaaaaaaaa
//此时得到的数a2保留了a的偶数位，奇数位全部置0

//a1<<= 1
//a2>>= 1
//再把2个数相加就是正确结果

#define SWAP(a) ((((a)&0x55555555)<<1) + ( ((a)&0xaaaaaaaa)>>1)) 
int main()
{
	int a = 0;
	scanf("%d", &a);
	int c = SWAP(a);
	printf("%d", c);
	return 0;
}