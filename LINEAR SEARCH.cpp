#include<stdio.h>
 
int linear_search(int*, int, int);
 
main()
{
   int array[100], search, c, n, position;
 
   printf("Enter the number of elements in array\n");
   scanf("%d",&n);
 
   printf("Enter %d numbers\n", n);
 
   for ( c = 0 ; c < n ; c++ )
      scanf("%d",&array[c]);
 
   printf("Enter the number to search\n");
   scanf("%d",&search);
 
   position = linear_search(array, n, search);
 
   if ( position == -1 )
      printf("%d is not present in array.\n", search);
   else
      printf("%d is present at location %d.\n", search, position+1);
 
   return 0;
} 
 
int linear_search(int *pointer, int n, int find)
{
   int c;
 
   for ( c = 0 ; c < n ; c++ )
   {
      if ( *(pointer+c) == find )
         return c;
   }
 
   return -1;
}
