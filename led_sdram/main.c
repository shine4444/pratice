#define GPFCON *((unsigned long*)0x56000050)
#define GPFDAT *((unsigned long*)0x56000054)

int main(void)
{
	GPFCON=0X00005555;
	GPFDAT=0X00000000;
	while(1);
}
