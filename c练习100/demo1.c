// 有1,2,3,4四个数 能组成多少个不同的数字不重复的三位数？各是多少？
// 思路：个位 百位 十位 能且只能有出现一次
#include<stdio.h>
int main(void)
{
	int i = 1,j = 1, k = 1;
	for(i;i<5;i++) // 百位
	{
		for(j;j<5;j++) // 十位
		{
			for(k;k<5;k++) // 个位
			{
				if( i!=j && i!=k && k!=j ) // 确保三个数不相同
					printf("%d%d%d",i,j,k);
			}
		}
	}

	return 0;
}
