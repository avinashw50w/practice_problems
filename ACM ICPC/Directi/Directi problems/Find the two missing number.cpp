/*Method 2 – O(n) time complexity and O(1) Extra Space

The idea is based on this popular solution for finding one missing numbers. We extend the solution so that two missing elements are printed.
Let’s find out the sum of 2 missing numbers:

arrSum => Sum of all elements in the array

sum (Sum of 2 missing numbers) = (Sum of integers from 1 to n) - arrSum
                               = ((n)*(n+1))/2 – arrSum 

avg (Average of 2 missing numbers) = sum / 2;
One of the numbers will be less than or equal to avg while the other one will be strictly greater then avg. Two numbers can never be equal since all the given numbers are distinct.
We can find the first missing number as sum of natural numbers from 1 to avg, i.e., avg*(avg+1)/2 minus the sum of array elements smaller than avg
We can find the second missing number as sum of natural numbers from avg+1 to n minus the sum of array elements greater than than avg
Consider an example for better clarification

Input : 1 3 5 6, n = 6
Sum of missing integers = n*(n+1)/2 - (1+3+5+6) = 6.
Average of missing integers = 6/2 = 3.
Sum of array elements less than or equal to average = 1 + 3 = 4
Sum of natural numbers from 1 to avg = avg*(avg + 1)/2
                                     = 3*4/2 = 6
First missing number = 6 - 4 = 2

Sum of natural numbers from avg+1 to n
                                =  n*(n+1)/2 - avg*(avg+1)/2
                                =  6*7/2 - 3*4/2
                                =  15
Sum of array elements greater than average = 5 + 6 = 11
Second missing number = 15 - 11 = 4
Below is C++ implementation of above idea.
*/
// C++ Program to find 2 Missing Numbers using O(1)
 
// Returns the sum of the array
int getSum(int arr[],int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return sum;
}
 
void findTwoMissingNumbers(int arr[],int n)
{
    // Sum of 2 Missing Numbers
    int sum = (n*(n + 1)) /2 - getSum(arr, n-2);
 
    // Find average of two elements
    int avg = (sum / 2);
 
    // Find sum of elements smaller than average (avg)
    // and sum of elements greater than average (avg)
    int sumSmallerHalf = 0, sumGreaterHalf = 0;
    for (int i = 0; i < n-2; i++)
    {
        if (arr[i] <= avg)
            sumSmallerHalf += arr[i];
        else
            sumGreaterHalf += arr[i];
    }
 
    cout << "Two Missing Numbers are\n";
 
    // The first (smaller) element = (sum of natural
    // numbers upto avg) - (sum of array elements
    // smaller than or equal to avg)
    int totalSmallerHalf = (avg*(avg + 1)) / 2;
    cout << (totalSmallerHalf - sumSmallerHalf) << " ";
 
    // The first (smaller) element = (sum of natural
    // numbers from avg+1 to n) - (sum of array elements
    // greater than avg)
    cout << (((n*(n+1))/2 - totalSmallerHalf) -
             sumGreaterHalf);
}
 
// Driver program to test above function
int main()
{
    int arr[] = {1, 3, 5, 6};
  
    // Range of numbers is 2 plus size of array
    int n = 2 + sizeof(arr)/sizeof(arr[0]);
  
    findTwoMissingNumbers(arr, n);
  
    return 0;
}