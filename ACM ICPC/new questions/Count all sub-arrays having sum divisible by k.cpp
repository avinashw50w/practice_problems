/*Count all sub-arrays having sum divisible by k
You are given an array of positive and/or negative integers and a value K . 
The task is to find count of all sub-arrays whose sum is divisible by K?

Examples:

Input  : arr[] = {4, 5, 0, -2, -3, 1}, 
         K = 5
Output : 7
// there are 7 sub-arrays whose is divisible by K
// {4, 5, 0, -2, -3, 1}
// {5}
// {5, 0}
// {5, 0, -2, -3}
// {0}
// {0, -2, -3}
// {-2, -3}
We strongly recommend you to minimize your browser and try this yourself first.

A simple solution for this problem is to one by one calculate sum of all sub-arrays possible and check divisible by K. 
The time complexity for this approach will be O(n^2).

An efficient solution for this problem is to use little bit mathematics. Since , if any sub-array sum from index i’th to j’th is divisible by k 
then we can write this (arr[i]+arr[i+1]+….+arr[j]) % k = (arr[0]+arr[1]+arr[2]+…+arr[j]) % k + (arr[0]+arr[1]+…..+arr[i-1]) % k . 
So we need to find such a pair of indices (i, j) that they satisfy the above condition. Here is the algorithm :

Make an auxiliary array of size k as Mod[k] . This array holds the count of each remainder
 we are getting after dividing cumulative sum till any index in arr[].
Now start calculating cumulative sum and simultaneously take it’s mod with K , whichever remainder we get increment count by 1 
for remainder as index in Mod[] auxiliary array. Sub-array by each pair of positions with same value of ( cumSum % k) 
constitute a continuous range whose sum is divisible by K.
Now traverse Mod[] auxiliary array , for any Mod[i] > 1 we can choose any to pair of indices for sub-array by 
(Mod[i]*(Mod[i] – 1))/2 number of ways . Do the same for all remainders < k and sum up the result that will be 
the number all possible sub-arrays divisible by K.*/

// function to find all sub-arrays divisible by k
int subCount(int arr[], int n, int k)
{
    // create auxiliary hash array to count frequency
    // of remainders
    int mod[k];
    memset(mod, 0, sizeof(mod));
 
    // Traverse original array and compute cumulative
    // sum take remainder of this current cumulative
    // sum and increase count by 1 for this remainder
    // in mod[] array
    int cumSum = 0;
    for (int i=0; i<n; i++)
    {
        cumSum += arr[i];
        mod[cumSum%k]++;
    }
 
    int result = 0;  // Initialize result
 
    // If there is a prefix subarray divisible by k
    if (mod[0] == 1)
        result = 1;
 
    // Traverse mod[]
    for (int i=0; i<k ; i++)
 
        // If there are more than one prefix subarrays
        // with a particular mod value.
        if (mod[i] > 1)
            result += (mod[i]*(mod[i]-1))/2;
 
    return result;
}
 
// Driver program to run the case
int main()
{
    int arr[] = {4, 5, 0, -2, -3, 1};
    int k = 5;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << subCount(arr, n, k);
    return 0;
}