#include <stdio.h>
 
int BinarySearching(int arr[], int max, int element)
{
      int low = 0, high = max - 1, middle;
      while(low <= high)
      {
            middle = (low + high) / 2;
            if(element > arr[middle])
                  low = middle + 1; 
            else if(element < arr[middle])
                  high = middle - 1; 
            else
                  return middle;
      }
      return -1;
}
 
int main()
{
      int count, element, limit, arr[50], position;
      printf("Enter the Limit of Elements in Array:\t");
      scanf("%d", &limit);
      printf("Enter %d Elements in Array: \n", limit);
      for(count = 0; count < limit; count++)
      {
            scanf("%d", &arr[count]);
      }
      printf("Enter Element To Search:\t");
      scanf("%d", &element);
      position = BinarySearching(arr, limit, element);
      if(position == -1) 
      {
            printf("Element %d Not Found\n", element);
      }
      else
      {
            printf("Element %d Found at Position %d\n", element, position + 1);
      }
      return 0;
}
