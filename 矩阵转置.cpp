#include<stdio.h>
int main()
{
	int n,i,j,a[101][101],t;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	}                                //ÊäÈë¾ØÕó 
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			t=a[i][j];
			a[i][j]=a[j][i];
			a[j][i]=t;
		}                           //a[i][j]Óëa[j][i]»¥»» 
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j==n-1)
			printf("%d\n",a[j][i]);
		    else
			printf("%d ",a[j][i]);
		}
	}
}

