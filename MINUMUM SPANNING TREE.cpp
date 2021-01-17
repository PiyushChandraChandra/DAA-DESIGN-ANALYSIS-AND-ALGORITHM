#include<stdio.h>
#include<conio.h>

int n, cost[10][10];
void prim()
{
	int i,j,k,l,x,nr[10],temp,min_cost=0,tree[10][3];
	/* For first smallest edge */
	temp=cost[0][0];
	for(i=0;i < n;i++)
	{
		for(j=0;j < n;j++)
		{
			if(temp > cost[i][j])
			{
				temp=cost[i][j];
				k=i;
				l=j;
			}
		}
	}
	/* Now we have fist smallest edge in graph */
	tree[0][0]=k;
	tree[0][1]=l;
	tree[0][2]=temp;
	min_cost=temp;
	/* 	Now we have to find min dis of each
		vertex from either k or l
		by initialising nr[] array */
	for(i=0;i< n;i++)
	{
		if(cost[i][k]< cost[i][l])
			nr[i]=k;
		else
			nr[i]=l;
	}
	/* To indicate visited vertex initialise nr[] for them to 100 */
	nr[k]=100;
	nr[l]=100;
	/* Now find out remaining n-2 edges */
	temp=99;
	for(i=1;i< n-1;i++)
	{
		for(j=0;j< n;j++)
		{
		   if(nr[j]!=100 && cost[j][nr[j]] < temp)
		   {
			   temp=cost[j][nr[j]];
			   x=j;
		   }
		}
		/* Now i have got next vertex */
		tree[i][0]=x;
		tree[i][1]=nr[x];
		tree[i][2]=cost[x][nr[x]];
		min_cost=min_cost+cost[x][nr[x]];
		nr[x]=100;
		/* Now find if x is nearest to any vertex
		than its previous near value */
		for(j=0;j< n;j++)
		{
			if(nr[j]!=100 && cost[j][nr[j]] > cost[j][x])
				nr[j]=x;
		}
		temp=99;
	}
	/* Now i have the answer, just going to print it */
	printf("\n The min spanning tree is:- \n");
	for(i=0;i < n-1;i++)
	{
		for(j=0;j < 3;j++)
		   printf("%d\t", tree[i][j]);
		printf("\n");
	}
	printf("\n Min cost:- %d", min_cost);
}

int main()
{
	int i,j;
	printf("\n Enter the no. of vertices:- ");
	scanf("%d", &n);
	printf ("\n Enter the costs of edges in matrix form:- ");
	for(i=0;i< n;i++)
		for(j=0;j< n;j++)
			scanf("%d",&cost[i][j]);
	printf("\n The matrix is:- \n");
	for(i=0;i< n;i++)
	{
		for(j=0;j < n;j++)
			printf("%d\t",cost[i][j]);
		printf("\n");
	}
	prim();
	getch();
}
