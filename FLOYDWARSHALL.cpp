#include<stdio.h>
#include<stdlib.h>
 
#define infinity 9999
#define MAX 100
 
int n;/*Number of vertices in the graph*/
int adj[MAX][MAX];/*Weighted Adjacency matrix*/
int D[MAX][MAX];/*Shortest Path Matrix*/
int Pred[MAX][MAX];/*Predecessor Matrix*/
 
void create_graph();
void FloydWarshalls( );
void findPath(int s, int d);
void display(int matrix[MAX][MAX], int n);
 
int main()
{
        int s, d;
 
        create_graph();
        FloydWarshalls();
        while(1)
        {
                printf("\nEnter source vertex(-1 to exit)  : ");
                scanf("%d",&s);
                if(s == -1)
                        break;
                printf("\nEnter destination vertex : ");
                scanf("%d",&d);
                if( s < 0 || s>n-1 || d<0 || d>n-1)
                {
                        printf("\nEnter valid vertices \n\n");
                        continue;
                }
                printf("\nShortest path is : ");
                findPath(s,d);
                printf("\nLength of this path is %d\n",D[s][d]);
        }
}/*End of main( )*/
 
void FloydWarshalls()
{
        int i,j,k;
 
        for(i=0; i<n; i++)
                for(j=0; j<n; j++)
                {
                        if(adj[i][j] == 0)
                        {
                                D[i][j] = infinity;
                                Pred[i][j] = -1;
                        }
                        else
                        {
                                D[i][j] = adj[i][j];
                                Pred[i][j] = i;
                        }
                }
 
        for(k=0; k<n; k++)
        {
                for(i=0; i<n; i++)
                  for(j=0; j<n; j++)
                          if( D[i][k] + D[k][j] < D[i][j] )
                          {
                                  D[i][j] = D[i][k] + D[k][j];
                                  Pred[i][j] = Pred[k][j];
                          }
        }
 
        printf("\nShortest path matrix is :\n");
        display(D,n);
 
        printf("\n\nPredecessor matrix is :\n");
        display(Pred,n);
 
        for(i=0;i<n;i++)
                if(D[i][i]<0)
                {
                        printf("\nError :       negative cycle\n");
                        exit(1);
                }
 
}/*End of FloydWarshalls()*/
 
void findPath(int s, int d)
{
        int i, path[MAX], count;
 
        if(D[s][d] == infinity)
        {
                printf("\nNo path \n");
                return;
        }
 
        count = -1;
        do
        {
                path[++count] = d;
                d = Pred[s][d];
        }while(d!=s);
 
        path[++count] = s;
 
        for(i=count; i>=0; i--)
                printf("%d ",path[i]);
        printf("\n");
}/*End of findPath()*/
 
 
void display(int matrix[MAX][MAX],int n )
{
        int i,j;
        for(i=0;i<n;i++)
        {
                for(j=0; j<n; j++)
                        printf("%7d",matrix[i][j]);
                printf("\n");
        }
}/*End of display( )*/
 
void create_graph()
{
        int i,max_edges,origin,destin, wt;
 
        printf("\nEnter number of vertices : ");
        scanf("%d",&n);
        max_edges = n*(n-1);
 
        for(i=1; i<=max_edges; i++)
        {
                printf("\nEnter edge %d( -1 -1 to quit ) : ",i);
                scanf("%d %d",&origin,&destin);
 
                if( (origin == -1) && (destin == -1) )
                        break;
 
                printf("\nEnter weight for this edge : ");
                scanf("%d",&wt);
 
                if( origin >= n || destin >= n || origin<0 || destin<0)
                {
                        printf("\nInvalid edge!\n");
                        i--;
                }
                else
                        adj[origin][destin] = wt;
        }
}
