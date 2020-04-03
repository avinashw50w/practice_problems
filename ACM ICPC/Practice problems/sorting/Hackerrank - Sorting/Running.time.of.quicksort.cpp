/* In practice, how much faster is Quicksort (in-place) than Insertion Sort? Compare the running time of the two algorithms by counting how many swaps or shifts each one takes to sort an array, and output the difference. You can modify your previous sorting code to keep track of the swaps. The number of swaps required by Quicksort to sort any given input have to be calculated. Keep in mind that the last element of a block is chosen as the pivot, and that the array is sorted in-place as demonstrated in the explanation below.

Any time a number is lower than the partition, it should be "swapped", even if it doesn't actually move to a different location. Also ensure that you count the swap when the pivot is moved into place. The count for Insertion Sort should be the same as the previous challenge, where you just count the number of "shifts".

Note 
Please use Lomuto Partition for this challenge.

Input Format 
There will be two lines of input:

n - the size of the array
ar - n numbers that make up the array
Output Format 
Output one integer D, where D= (insertion sort shifts) - (quicksort swaps)

Constraints 
1≤n≤1000 
−1000≤x≤1000,x∈ar

Sample Input

7
1 3 9 8 2 7 5
Sample Output

1
Explanation 
Insertion Sort will take 9 "shifts" to sort the array. Quicksort will take 8 "swaps" to sort it, as shown in the diagram below. 9−8=1 is the final output. */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int d1=0,d2=0;
int partition(int *a,int s,int e){
    int pivot=a[e];
    int pos=s;
    for(int i=s;i<e;i++){
        if(a[i]<=pivot){
            swap(a[i],a[pos++]); d1++;
        }
    }
    swap(a[pos],a[e]); d1++;
    return pos;
}
void quicksort(int *a,int s,int e){
    if(s<e){
        int p=partition(a,s,e);
        quicksort(a,s,p-1);
        quicksort(a,p+1,e);
    }
}
void insertion_sort(int a[],int n){
    for(int i=1;i<n;i++){
        int j=i-1, key=a[i];
        while(j>=0 && a[j]>key){
            a[j+1]=a[j]; j--;
            d2++;
        }
        a[j+1]=key; 
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;cin>>n;
    int a1[n+2],a2[n+2];
    for(int i=0;i<n;i++){ cin>>a1[i];a2[i]=a1[i];}
    quicksort(a1,0,n-1);
    insertion_sort(a2,n);
    cout<< d2-d1 <<endl;
    return 0;
}
