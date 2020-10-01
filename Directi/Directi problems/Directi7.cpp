/*directi-interview-questions1
of 1 vote
22 
Answers
Given an array of N positive integers, N being even, and a number K, find out if it is possible 
to form pairs of the numbers present in the array such that the sum of numbers in each pair is 
divisible by K. *


time complexity O(n) and space complexity O(n)

ex: 4 11 7 6 3 9 8 12 and K=5, N=8 (array size)

get the remainder of all elements by dividing with K, so the array becomes
4 1 2 1 3 4 3 2

for remainder array verify below conditions:

1. there should be even number of 0's
2. for every element a[i] in remainder array there should be K-a[i] exists in array. to verify this hash all elements 
and and keep the count of each element and check whether a[i] and K-a[i] exists in hash table and the count should be also equal for both


any two numbers sum should be divisible by K means sum of remainders of two numbers should be K or 0

lets K=5, and data is 8 & 9, here sum of these numbers to be divisible by 5 (K) for below cases
1. both numbers should be divisible by 5 means remainders will be 0 & 0
2. sum of the remainders should be divisible by 5, here remainders are 3 & 4 sum of these is not divisible by 5... 
lets take 8 & 12, sum of remainders is 3+2, which is divisible by 5.

here we don't know which two numbers remainders sum is divisible by 5, each pair should be equal to K and there 
should be N/2 such pairs...each pair is a[i] & K-a[i] 

lets take another example: 
9 15 21 4 5 6 and K=10, and N=6
here remainders are 9 5 1 4 5 6*/