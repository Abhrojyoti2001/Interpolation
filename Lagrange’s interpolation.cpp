/*Lagrange's Interpolation*/
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
main()
{
int n,i,j;
float *X,*Y,x,s=0.0,t;
printf("Using Lagrange’s  interpolation formula we can get the values of interpolating point.\n\nEnter the total number of arguments: ");
scanf("%d",&n);
X=(float*)malloc(n*sizeof(float));
Y=(float*)malloc(n*sizeof(float));
for (i=0;i<n;i++)
	{printf("Enter X%d: ",i+1);
	scanf("%f",&X[i]);
	printf("Enter Y%d: ",i+1);
	scanf("%f",&Y[i]);}
printf("\nEnter the interpolating point: ");
scanf("%f",&x);
/*Calculation of the value of interpolating point*/
for (i=0;i<n;i++)
	{t=1.0;
	for (j=0;j<n;j++)
		{if(i!=j)
			t=t*(x-X[j])/(X[i]-X[j]);}
	s=s+(t*Y[i]);}
/*Printing the value of interpolating point*/
printf("Value of interpolating point is %.3f",s);
}
