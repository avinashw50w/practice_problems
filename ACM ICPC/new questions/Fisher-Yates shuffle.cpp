/*Given an array of integers. write a function that shuffles the array inplace such that all permutations of the 
n integers are equally likely. Assume you have random integer generator to generate a random integer in the range [0,i) */

// start with i = 0. pick a random location j in the range [i,N-1] and swap it with a[i]. Keep doing this until i == N-1

void shuffle(int a[], int N) {

	REP(i, 0, N) {

		swap(a[i], a[rand_gen(i, N)]);
	}
}