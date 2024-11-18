#include<stdio.h>
union A
{
	int x;
	float y;
	double z;
	int arr[2];
}a1;
union B
{
	int x;
	short int y;
	char ch;
	char carr[4];
} b1;
int main()
{
	a1.y=6.25f;
	printf("x=%x\n", a1.x);
	a1.z=0.15625;;
	printf("%x%x\n",a1.arr[1],a1.arr[0]);
	printf("x=%u\n", &a1.x);
	printf("x=%u\n", &a1.y);
	printf("x=%u\n", &a1.z);
	printf("****************************************\n");
	b1.x=0x41424344;
	printf("x=%x\n", b1.x);
	printf("%x%x%x%x\n",b1.carr[0], b1.carr[1], b1.carr[2], b1.carr[3]);
	printf("x=%u\n", &b1.x);
	printf("x=%u\n", &b1.y);
	printf("x=%u\n", &b1.ch);
	


}
