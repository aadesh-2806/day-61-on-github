#include<stdio.h>

void main()
{
	int n,t,i,k,a[50],r,b;

	printf("hello aadesh agrawal(2019uec1660)\nenter values=");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{	
		printf("enter value%d=",i+1);
		scanf("%d",&a[i]);
	}
	printf("enter value to search=");
	scanf("%d",&k);
	i=0;r=n-1;
	while(i<=n-1)
	{
	    t=(i+r)/2;
		if(a[t]==k)
		{
			b=1;
			break;
		}
		else
	    {
			if(a[t]<k)
			{
				r=t-1;
			}
	    	else
			{
				i=t+1;
			}
		}
	}
	if(b==1)
	{
		printf("present");
	}
	else
	{
		printf("not present");
	}
	getch();
}
