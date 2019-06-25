
/*The problem is:

You are given a lucky number n. Lucky numbers are the positive integers whose decimal representations contain only the 
lucky digits 4 and 7. 
For example, numbers 47, 744, 4 are lucky and 5, 17, 467 are not.

If we sort all lucky numbers in increasing order, what's the 1-based index of n? 
Input
The first and only line of input contains a lucky number n (1 ≤ n ≤ 109).

Output
Print the index of n among all lucky numbers.
Examples
input
4
output
1
input
7
output
2
input
77
output
6  */

n,c,i;main(){scanf("%d",&n);for(;n;){c+=(n%10==7)<<i;n/=10;c+=1<<i++;}printf("%d",c);}

