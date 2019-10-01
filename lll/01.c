//RT1290 ÍêÊı
/*#include <stdio.h>
#include <string.h>

int main()
{
	int x,i;
	int j=0;
	int a[10]={0};
	int sum=0;
	
	for(x=3;x<=1000;x++)
	{
		
		
			for(i=1;i<x;i++)
		{
			if(x%i == 0)
			{
				a[j++] = i;
				sum = sum + i;
			}	
		}
		
		
		if(x == sum)
		{
			//printf("%d,%d",x,sum);
			printf("%d is a wanshu:",x);
			for(i=1;i<j;i++)
				printf("%d,",a[i]); 
				printf("\n");
			
		
		} 
		}
		
	
			return 0;
 } 
 */
#include<stdio.h>

int main()

{ 

	int i,j,sum=1;

	int b[100];
	int a;

	for(i=3;i<=1000;i++)

	{ 	

		sum=1;

		int k=0;

		for(j=2;j<i;j++)

		if( i%j==0) 
		{
			sum+=j;
			b[k++]=j;}

		if(i==sum)

		{

			printf("%d is a wanshu:1,%d,",i,b[0]);

			for(a=1;a<k; a++)

					printf("%d,",b[a]);

					printf("\n");

		}

		}
		return 0;

} 


