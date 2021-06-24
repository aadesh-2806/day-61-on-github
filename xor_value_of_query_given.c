#include<stdio.h>

void main()
{
	
	int i,b[100],a[50][50],s,q,z,c[100],m,n,j,l;
	
	printf("hello\nenter number of values=");
	scanf("%d",&n);
	
	for(j=0;j<n;j++)
	{
		printf("enter %d=",j+1);
		scanf("%d",&b[j]);
	}
	
	printf("enter number of query=");
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("enter %d,%d=",i+1,j+1);
			scanf("%d",&a[i][j]);
		}					
	}
	
	for(i=0;i<m;i++)
	{
		s=b[a[i][0]];
		for(j=a[i][0]+1;j<=a[i][1];j++)
		{
			s=s^b[j];
		}
		printf("%d ",s); 
	}
	getch();
	
}
