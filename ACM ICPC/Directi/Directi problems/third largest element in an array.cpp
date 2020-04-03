/*Method 1 (Simple) Simplest way to solve this question is to first iterate through the array and find first maximum. 
Store this first maximum as well as its index. Now traverse the whole array finding the second max with the changed condition. 
Finally traverse the array third time and find the third largest element.*/

// C program to find third Largest element in an array
// of distinct elements
 
void thirdLargest(int arr[], int arr_size)
{
    /* There should be atleast three elements */
    if (arr_size < 3)
    {
        printf(" Invalid Input ");
        return;
    }
 
    // Find first largest element
    int first = arr[0];
    for (int i = 1; i < arr_size ; i++)
        if (arr[i] > first)
            first = arr[i];
 
    // Find second largest element
    int second = INT_MIN;
    for (int i = 0; i < arr_size ; i++)
        if (second < arr[i] && arr[i] < first)
            second = arr[i];
 
    // Find third largest element
    int third = INT_MIN;
    for (int i = 0; i < arr_size ; i++)
        if (third < arr[i] && arr[i] < second)
            third = arr[i];
 
    printf("The third Largest element is %d\n", third);
}
 
/* Driver program to test above function */
int main()
{
    int arr[] = {12, 13, 1, 10, 34, 16};
    int n = sizeof(arr)/sizeof(arr[0]);
    thirdLargest(arr, n);
    return 0;
}
/*
Method 2 In this method, we need not to iterate array three times. We can find third largest in one traversal only.

Initialize first = a[0] and second = -INF, third = -INF
Iterate the array and compare each element with first.
If a[i] is greater than first then update all first, second and third:
third = second
second = first
first = arr[i]
Else compare arr[i] with second, if its greater than second, then update:
third = second
second = arr[i]
Else compare arr[i] with third, if its greater than third, then update:
third = arr[i]
Return third */
// C program to find third Largest element in an array
#include <bits/stdc++.h>
 
void thirdLargest(int arr[], int arr_size)
{
    /* There should be atleast three elements */
    if (arr_size < 3)
    {
        printf(" Invalid Input ");
        return;
    }
 
    // Initialize first, second and third Largest element
    int first = arr[0], second = INT_MIN, third = INT_MIN;
 
    // Traverse array elements to find the third Largest
    for (int i = 1; i < arr_size ; i ++)
    {
        /* If current element is greater than first,
           then update first, second and third */
        if (arr[i] > first)
        {
            third  = second;
            second = first;
            first  = arr[i];
        }
 
        /* If arr[i] is in between first and second */
        else if (arr[i] > second)
        {
            third = second;
            second = arr[i];
        }
 
        /* If arr[i] is in between second and third */
        else if (arr[i] > third)
            third = arr[i];
    }
 
    printf("The third Largest element is %d\n", third);
}


 