/* Given N,O where N=No. of digits that can be displayed on calculator and O=No. of multiplication to be performed. 
The numbers used for the multiplication can be from {2,3,...8,9} 
2<=N<=8 
2<=O<=30 
write function that will return the largest num that can be obtained after O multiplication. 
Eg: N=2, O=3 
the function should return 98, since the maximum no. generated after 3 multiplications 2*7*7. 
function should return -1 for error or invalid. */

long long maxNumberUtil(int O, long long limit, int total) {
	if(O == 0) return total;

	long long res = 0;

	for(int i = 2; i <= 9; ++i) {
		long long maxx = maxNumberUtil(O, limit, total * i);
		if(res < maxx and maxx <= limit)
			res = maxx;
	}

	return res;
}

long long maxNumber(int N, int O) {
	if(N <= 0 or O <= 0) return -1;

	long long limit = pow(10, N) - 1;

	return maxNumberUtil(O, limit, 1);
}