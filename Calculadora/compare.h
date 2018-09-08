#include <stdio.h>
#include <stdlib.h>

int compare(const int *n1, const int *n2)
{
  if (*n1 == *n2) { return  0; }
  else if (*n1 <  *n2) { return -1; }
  else if (*n1 >  *n2) { return  1; }
  else
  return 0;
}


/*int main( void )
{
  int array[]=  {42,43,44,5,23,992,1231,3133,3,9274};
  int i;

  for (i=0; i<10; i++){
     printf ("%d ",array[i]);
  }
  printf(" not sorted\n");
  qsort(array, 10, sizeof(int), (void *)compare );

 for (i=0; i<10; i++){
     printf ("%d ",array[i]);
  }
  printf(" Sorted with qsort\n");

return 0;
}*/
