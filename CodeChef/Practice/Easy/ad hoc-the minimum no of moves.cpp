/*Little chief has his own restaurant in the city. There are N workers there. Each worker has his own salary. The salary of the i-th worker 
equals to Wi (i = 1, 2, ..., N). Once, chief decided to equalize all workers, that is, he wants to make salaries of all workers to be equal. 
But for this goal he can use only one operation: choose some worker and increase by 1 salary of each worker, except the salary of the chosen 
worker. In other words, the chosen worker is the loser, who will be the only worker, whose salary will be not increased during this particular 
operation. But loser-worker can be different for different operations, of course. Chief can use this operation as many times as he wants. 
But he is a busy man. That's why he wants to minimize the total number of operations needed to equalize all workers. Your task is to find this 
number.*/
/*QUICK EXPLANATION:
The answer is just sumW − N * minW, where sumW is the sum of all W[i] and minW is the minimum over all W[i]. See author's solution and tester's 
first solution as a reference.

EXPLANATION:
The operation can be treated as follows: we at first decrease salary of some worker by 1 and then increase salaries of all workers by 1. 
But why do we need to do the second part? Since we want all salaries to be equal the second part of the operation could be simply ignored. 
So we may assume that at each operation we decrease salary of some worker by 1.

Now if we have some salary greater the minimum salary then without applying operation to it we can't achieve the goal in any way - the minimum 
could only decreases during operations so this salary will be always not equal to the minimum one. Hence we need to apply at least W[i] − minW 
operations for the i-th worker. The summation of this over all i is exactly sumW − N * minW. But, clearly, applying exactly W[i] − minW 
operations to the i-th worker (for all i) makes all salaries to be equal to minW, which is our goal. Therefore, this number of operations is 
also sufficient. Hence it is the answer as stated above.*/
#include <stdio.h>

int main() {
	int t,n,a,i,sum,min;
	scanf("%d",&t);
	while(t--){
		sum = 0;
		min = (1<<30);
		scanf("%d",&n);
		for(i=0;i<n;++i){ scanf("%d",&a); sum += a; if(a<min) min = a; }
		printf("%d\n", (sum - n*min));
	}
	return 0;
}
