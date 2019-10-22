#include<stdio.h>
#include"all.h"
void main()
{
	int m,n,v,e,f,i,j;
	float a1[50][50],a[50][50],b[50][50],x[50][50],l[50][50],u[50][50],d[50][50];
	float s[50][50],d1[50][50],m1[50][50],m2[50][50],m3[50][50],m4[50][50],m5[50][50];
	float x1[50][50],x2[50][50],x3[50][50],tolr,z;
	printf("Enter the no. of variables : ");
	scanf("%d",&v);
	printf("Enter the no. of rows & columns of augmented matrix : ");
	scanf("%d %d",&m,&n);
	read2(a1,m,n);
	printline(60);
	printf("The given augmented matrix is :\n");
	write2(a1,m,n);
	printline(60);
	AB(a1,m,n,a,b);
	printf("The given coefficient matrix is :\n");
	write2(a,v,v);
	printline(60);
	printf("The given matrix b is :\n");
	write2(b,v,1);
	printline(60);
	decom(a,v,v,l,u,d);
	printline(60);
	printf("The lower diagonal matrix is :\n");
	write2(l,v,v);
	printline(60);
	printf("The upper diagonal matrix is :\n");
	write2(u,v,v);
	printline(60);
	printf("The diagonal matrix is :\n");
	write2(d,v,v);
	printline(60);
	add(l,d,v,v,s);
	inv(s,v,d1);
	mul(d1,u,v,v,v,m1);
	sclr(m1,v,v,-1,m2);
	printf("The matrix H is :\n");
	write2(m2,v,v);
	printline(60);
	mul(d1,b,v,v,1,m3);
	printf("The matrix C is :\n");
	write2(m3,v,1);
	printline(60);
	power(m2,v,v);
		printf("Enter the no. of rows & columns of the initial matrix X (To solve the given system) : ");
		scanf("%d %d",&e,&f);
		read2(x,e,f);
		printline(60);
		printf("The given matrix X is :\n");
		write2(x,e,f);
		printline(60);
		printf("Enter the tollerance level (To solve given system) : ");
		scanf("%f",&tolr);
		do
		{
			mul(m2,x,v,v,f,m4);
			add(m4,m3,v,f,x1);
			sclr(x,v,f,-1,x2);
			add(x1,x2,v,f,m5);
				z=0;
				for(i=1;i<=v;i++)
				{
					for(j=1;j<=f;j++)
					{
						if(fabs(m5[i][j])>z)
						{
							z=fabs(m5[i][j]);
						}
					}
				}
			for(i=1;i<=e;i++)
			{
				for(j=1;j<=f;j++)
				{
					x[i][j]=x1[i][j];
				}
			}
			for(i=1;i<=v;i++)
			{
				for(j=1;j<=f;j++)
				{
					m4[i][j]=0;
					m5[i][j]=0;
					x2[i][j]=0;
				}
			}
		}while(z>tolr);
		printline(60);
		printf("The required (approx.) solutions are :\n");
		for(i=1;i<=e;i++)
		{
			for(j=1;j<=f;j++)
			{
				printf("x%d = %f \t",i,x[i][j]);
			}
		}
		printf("\n");
		printline(60);
}

