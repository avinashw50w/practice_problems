/*Alternate Sorting :Given an array of integers, rearrange the array in such a way that the first element is first maximum and second element 
is first minimum.

Example:
Input  : {1, 2, 3, 4, 5, 6, 7}
Output : {7, 1, 6, 2, 5, 3, 4}*/

#include <iostream>
#include <string.h>
 
using namespace std;
#define mfor(i,n) for(int i=0;i<n;i++)
 
int compare (const void * a, const void * b)
{
 
 return *(int*)a-*(int*)b;
}
 
/*-----------------------------------------------*/
 
 
int array[1000];
int n;
 
void with_extra_space()
{
 int ret[1000];
 qsort(array,n,sizeof(int),compare);
 int temp=0;
 mfor(i,n/2)
 {
  ret[temp++]=array[i];
  if(temp<n)
   ret[temp++]=array[n-i-1];
 } 
 mfor(i,n)                   // ofcourse you can also print
  cout<<ret[i]<<endl;      // this just with sorted array :)
}
 
int rem;
int min,max;
int index=0;
 
void inplace()
{
 mfor(i,n)
 {
  rem = index;
 
  if(!(i&1))                     // if even then find minimum
  {
   int min = int_max;
   for( int j=i;j<n;j++)
    if(array[j]<min)
    {
     rem=j;
     min=array[j];
    }
  } 
  else                        // find max
  {
   int max= int_min;
   for( int j=i;j<n;j++)
    if(array[j]>max)
    {
     rem=j;
     max=array[j];
    } 
  }
 
  int temp=array[rem];                 // swap it 
  array[rem]=array[index];
  array[index]=temp;
  ++index; 
 }
 
 mfor(i,n)
  cout<<array[i]<<endl;
 
}
 
int main()
{
 cin>>n;
 mfor(i,n)
  cin>>array[i];
 
 with_extra_space();
 inplace();
 
}