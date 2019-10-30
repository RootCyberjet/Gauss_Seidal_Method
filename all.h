#include<math.h>
void printline(int k)
{
	int i;
	for(i=1;i<=k;i++)
	{
		printf("_");
	}
	//gfghfghfhgfhgfhg
	printf("\n");
}
float read2(float x[][50],int a,int b)
{
	int i,j;
	printf("Enter %d entries = ",a*b);
	for(i=1;i<=a;i++)
	{
		for(j=1;j<=b;j++)
		{
			scanf("%f",&x[i][j]);
		}
	}
}
float write2(float x[][50],int a,int b)
{
	int i,j;
	for(i=1;i<=a;i++)
	{
		for(j=1;j<=b;j++)
		{
			printf("%f\t",x[i][j]);
		}
		printf("\n");
	}
}
float AB(float a[][50],int m,int n,float b[][50],float c[][50])
{
	int i,j;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(j<=m)
			{
				b[i][j]=a[i][j];
			}
			else
			{
				c[i][j-m]=a[i][n];
			}
		}
	}
}
float mul(float x[][50],float y[][50],int m,int n,int l,float s[][50])
{
	int i,j,k;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=l;j++)
		{
			s[i][j]=0;
			for(k=1;k<=n;k++)
			{
				s[i][j]=s[i][j]+x[i][k]*y[k][j];
			}
		}
	}
}
float add(float x[][50],float y[][50],int m,int n,float s[][50])
{
	int i,j;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			s[i][j]=x[i][j]+y[i][j];
		}
	}
}
float decom(float x[][50],int m,int n,float p[][50],float q[][50],float r[][50])
{
	int i,j;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i>j)
			{
				p[i][j]=x[i][j];
			}
			else
			{
				p[i][j]=0;
			}
		}
	}
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i<j)
			{
				q[i][j]=x[i][j];
			}
			else
			{
				q[i][j]=0;
			}
		}
	}
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i=j)
			{
				r[i][j]=x[i][j];
			}
			else
			{
				r[i][j]=0;
			}
		}
	}
}
float det(float x[][50],int y)
{
	int i,j,k,m,n,s=1;
	float d=0,p[50][50];
	if(y==1)
	{
		return x[1][1];
	}
	else
	{
		for(i=1;i<=y;i++)
		{
			m=1;
			n=1;
			for(j=1;j<=y;j++)
			{
				for(k=1;k<=y;k++)
				{
					if(j!=1 && k!=i)
					{
						p[m][n]=x[j][k];
						if(n<y-1)
						{
							n++;
						}
						else
						{
							n=1;
							m++;
						}	
					}
				}
			}
			d=d+s*(x[1][i]*det(p,y-1));
			s=s*(-1);
		}
	}
	return d;
}
float inv(float x[][50],int y,float z[][50])
{
	int i,j,k,m,n,s,t;
	float d,p[50][50];
	d=det(x,y);
	for(s=1;s<=y;s++)
	{
		for(t=1;t<=y;t++)
		{
			m=1;
			n=1;
			for(j=1;j<=y;j++)
			{
				for(k=1;k<=y;k++)
				{
					if(j!=s && k!=t)
					{
						p[m][n]=x[j][k];
						if(n<y-1)
						{
							n++;
						}
						else
						{
							n=1;
							m++;
						}	
					}
				}
			}
			z[t][s]=(pow(-1,t+s)*det(p,y-1))/d;
		}
	}
}
float sclr(float x[][50],int a,int b,int c,float y[][50])
{
	int i,j;
	for(i=1;i<=a;i++)
	{
		for(j=1;j<=b;j++)
		{
			y[i][j]=x[i][j]*c;
		}
	}
}
float big(float x[][50],int a,int b)
{
	int i,j;
	float B1=0,B;
	for(i=1;i<=a;i++)
	{
		for(j=1;j<=b;j++)
		{
			if(fabs(x[i][j])>B1)
			{
				B1=fabs(x[i][j]);
				B=x[i][j];
			}
		}
	}
	return B;
}
float yv(float x[][50],float y[][50],int a,int b,float z[][50])
{
	int i,j;
	for(i=1;i<=a;i++)
	{
		for(j=1;j<=b;j++)
		{
			z[i][j]=x[i][j]/y[i][j];
		}
	}
}
float power(float a[][50],int m,int n)
{
	int p,q,j,k,s1;
	float b[50][50],c[50][50],e,s,r[50][50],u,t,V;
	printf("Enter the no. of rows and columns of initial vector (To apply power method) : ");
	scanf("%d %d",&p,&q);
	read2(b,p,q);
	printline(60);
	printf("The initial vector (To apply power method) is :\n");
	write2(b,p,q);
	printline(60);
	printf("Enter the allowed error (For power method) : ");
	scanf("%f",&e);
	printline(60);
	do
	{
		mul(a,b,m,n,q,c);
		yv(c,b,m,q,r);
		s=big(c,m,q);
		for(j=1;j<=m;j++)
		{
			for(k=1;k<=q;k++)
			{
				b[j][k]=c[j][k]/s;
			}
		}
		u=0;
		for(s1=1;s1<p;s1++)
		{
			t=fabs(r[s1][1]-r[s1+1][1]);
			if(t>=u)
			{
				u=t;
			}
		}
	}while(u>e);
	V=big(r,m,q);
	printf("The Biggest (in magnitude) approximate eigen value of H is = %0.3f.\n",V);
	if(fabs(V)<1)
	{
		printf("\nThat is, the spectral radius of iteration matrix H is = %0.3f < 1.",fabs(V));
		printf("\nTherefore the Method converges for any initial guess.\n");
		printline(60);
	}
	else
	{
		printf("\nThat is, the spectral radius of iteration matrix H is = %0.3f > 1.",fabs(V));
		printf("\nTherefore the Method may not converges for any initial guess.\n");
		printline(60);
	}
}

