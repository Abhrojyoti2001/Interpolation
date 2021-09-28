/*Program for Newton's Forward Interpolation*/
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
main()
{
    float *x,**y,s,t=1.0,X,h,u;
	int i,j,n,get=1;
	printf("Enter the total number of arguments: ");
	scanf("%d",&n);
	x=(float*)malloc(n*sizeof(float));
	y=(float**)malloc(n*sizeof(float*));
	for(i=0;i<n;i++)
	y[i]=(float*)malloc(n*sizeof(float));
	/*Checking for arguments are equally spaced or not*/
	for (i=0;i<n;i++)
	{printf("Enter X%d: ",i+1);
	scanf("%f",&x[i]);
	if(i==1)
		h=x[1]-x[0];
	if(i>=2)
		if(x[i]-x[i-1]!=h)
			{get=0;
			break;}
	printf("Enter Y%d: ",i+1);
	scanf("%f",&y[i][0]);}
	if (get==1)
		{printf("\nEnter the point of interpolation:");
		scanf("%f",&X);
		/*Generating a Forward Deference table*/
		for(j=1;j<n;j++)
			{for(i=j;i<n;i++)
			y[i][j]=y[i][j-1]-y[i-1][j-1];}
		/*Printing the Forward Deference table*/
		printf("\nThe forward difference table\n");
		for(i=0;i<n;i++)
			{for(j=0;j<=i;j++)
			printf("%.3f\t",y[i][j]);
			printf("\n");}
		/*Calculation of the value of interpolating point*/
		u=(X-x[0])/h;
		s=y[0][0];
		for(i=1;i<n;i++)
			{t=t*(u-i+1)/i;
			s=s+t*y[i][i];}
		/*Printing the value of interpolating point*/
		printf("\nValue of the function at X=%.3f is %.3f",X,s);}
	else
		printf("Newton’s forward interpolation formula is not applicable because the arguments are not equally spaced.");
}
