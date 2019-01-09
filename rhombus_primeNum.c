#include<stdio.h>
void zhishu(void)
{
	int i,j;
	printf("this is zhishu range form 10-50:");
	for(i=10;i<=50;i++)
	{
		j=2;
		do{
			if(i%j==0) break;
			j++;
		}while(j<i);
		if(j==i)printf("%3d",i);
	}
	printf("\n");
}
void display_lingxing(void)
{
	int col,row,arverge;
	int input;
	do{
		printf("please insert even!\n");
		scanf("%d",&input);
	}while(input%2==0);
	arverge=input/2;
	for(row=0;row<input;row++)
	{
		for(col=0;col<input;col++)
		{
			if(((col-row<=arverge && col-row>=0) || (row-col<=arverge && row-col>=0))
			&&((col+row>=arverge)&&(col+row<arverge+input)))
				printf(" # ");
			else printf("   ");
		}
		printf("\n");
	}
}
void homework(void)
{
	char chose;
	printf("please select 1 or 2!\n");
	printf("1:zhishu range form 10-50;  2:display lingxing!\n");
	scanf("%c",&chose);
	switch(chose)
	{
	case '1':
		zhishu();
		//printf("%c\n",chose);
		break;
	case '2':
		display_lingxing();
		//printf("%c\n",chose);
		break;
	default:
		printf("input error! quit");
		break;	
	}
}
void main(void)
{	
	printf("this is xxx's homework!\n");
//	while(1)
//	{
		homework();
//	}
//while(1);
}
