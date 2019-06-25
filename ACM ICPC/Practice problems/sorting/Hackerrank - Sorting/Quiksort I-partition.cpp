/* The previous challenges covered Insertion Sort, which is a simple and intuitive sorting algorithm. Insertion Sort has a running time of O(N2) which isn't fast enough for most purposes. Instead, sorting in the real world is done with faster algorithms like Quicksort, which will be covered in the challenges that follow.

The first step of Quicksort is to partition an array into two smaller arrays.

Challenge 
You're given an array ar and a number p. Partition the array, so that all elements greater than p are to its right, and all elements smaller than p are to its left. p is called the pivot of the partition.

Guideline - In this challenge, you do not need to move around the numbers 'in-place'. This means you can create two lists and combine them at the end.

Input Format 
You will be given an array of integers. The number p is the first element in ar.

There are two lines of input:

n - the number of elements in the array ar
the n elements of ar (including p at the beginning)
Output Format 
Print out the numbers of the partitioned array on one line.

Constraints

1≤n≤1000
−1000≤x≤1000,x∈ar
All elements will be unique.
Multiple answer can exists for the given test case. Print any one of them.
Sample Input

5
4 5 3 7 2
Sample Output

3 2 4 5 7 */
#inlcude <bits/stdc++.h>
using namespace std;
void partition(vector <int>  ar) {
    int n=ar.size();
    int p=ar[0];
    int indx=n-1;
    for(int i=n-1;i>0;i--){
        if(ar[i]>p){
           swap(ar[i],ar[indx]);
            indx--;
        }
    }
    swap(ar[indx],ar[0]);
    for(int i=0;i<n;i++) cout<<ar[i]<<" ";

}
int main(void) {
   vector <int>  _ar;
   int _ar_size;
cin >> _ar_size;
for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
   int _ar_tmp;
   cin >> _ar_tmp;
   _ar.push_back(_ar_tmp); 
}

partition(_ar);
   
   return 0;
}


// here's another way but is slower than the above method  //
void partition(vector <int>  ar) {
    int n=ar.size();
    vector<int> left,right;
    int pivot=ar[0];
    for(int i=1;i<n;i++){
        if(ar[i]<=pivot) left.push_back(ar[i]);
        else right.push_back(ar[i]);
    }
    left.push_back(pivot);
    for(int i=0;i<right.size();i++)
        left.push_back(right[i]);
    
    for(int i=0;i<left.size();i++) cout<<left[i]<<" ";   

}
