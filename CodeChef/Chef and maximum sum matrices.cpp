/* Dreaming to manipulate the dimensions of spacetime one day, Chef satisfies himself with manipulating dimensions of abstract mathematical entities for now. Today, Chef has N lists consisting of integers. The ith list is represented as Li, and has size Si.
Chef has transformed the given lists of integers to form an N dimensional matrix M of size S1 × S2 × S3 × … × SN such that an entry 
j1, j2, j3, … , jN in the matrix M is obtained by taking product of given N integers L1[j1], L2[j2], L3[j3], ..., LN[jN], where Li[ji] denotes the jth integer in the ith list (1-based indexing).
To explore the mathematics of the matrix M deeply, Chef wants to compute the maximum submatrix sum in this matrix; but he is afraid of its 
high dimensionality. So, he asked you to help him. He asked you to compute two quantities, the maximum sub-matrix sum in the matrix M, 
and the number of submatrices having this maximum sum.
Since the second answer to this problem can be very large, output it modulo 109+7.
Input

First line of input contains a single integer T denoting the number of test cases.
First line of each test case contains a single integer N denoting the number of lists of integers.
Next N lines of each test case contains some space separated integers where integers in the ith line make up the ith list. Each list 
description has the following format.
First integer Si in the ith line denotes the size of the ith list, and
the next Si space separated integers are the elements in the list.
Output

For each test case, output 2 space separated integers (second integer modulo 109 + 7) where the first integer denotes the maximum 
submatrix sum and the second denotes the number of such submatrices.
Constraints

1 ≤ T ≤ 100

1 ≤ N ≤ 9

1 ≤ Si ≤ 9

-9 ≤ Li[j] ≤ 9

DIFFICULTY:
Easy-Medium

PREREQUISITES:
Ad Hoc, Greedy

PROBLEM:
Given are NN arrays L1L1, L2L2, ..., LNLN containing integers. An NN dimensional matrix MM is constructed out of these arrays in the manner: M[i1][i2][i3]...[iN]=L1[i1]∗L2[i2]∗...∗LN[iN]M[i1][i2][i3]...[iN]=L1[i1]∗L2[i2]∗...∗LN[iN]. Find the maximum-sum submatrix of this matrix and also the number of submatrices having the maximum-sum.

EXPLANATION:
Let's go step wise in approaching this question. The first thing to consider is that we need to consider submatrices of an NN dimensional matrix. In most ad hoc problems, the way to approach is to first find out how to approach the given data. We must introduce some ordering in which the input needs to be worked upon. In this problem, we first need to figure out how to tell whether certain elements form a submatrix or not. A submatrix is a contiguous part of the matrix. This implies that we need to somehow find a way to determine whether two elements M[a1][b1][c1]...[]M[a1][b1][c1]...[] and M[a2][b2][c2]...[]M[a2][b2][c2]...[] are adjacent or not. Observation tells us that they will be adjacent if and only if ∣a1−a2∣∣a1−a2∣ + ∣b1−b2∣∣b1−b2∣ + ∣c1−c2∣+...∣c1−c2∣+... ≤1≤1. In words, this means that the the points are adjacent if and only if they differ in one coordinate by 1 unit.

There is a very crucial observation to make here. What does the above observation regarding adjacent elements tell us about identifying a submatrix from the given input? It tells us that a submatrix will be a set of elements such that their coordinates along the first dimension form a contiguous range in the array L1L1. To be more clear, let's say M[a1]...[]M[a1]...[], M[a2]...[]M[a2]...[], M[a3]...[]M[a3]...[], ..., M[ap]...[]M[ap]...[] for p≤Np≤N are elements forming a submatrix, then the elements L1[a1]L1[a1], L1[a2]L1[a2], L1[a3]L1[a3], ..., L1[ap]L1[ap] for a subarray of array L1L1. Similarly, the coordinates along second dimension form a subarray in array L2L2, and so on. This is a very important observation. It introduces some order in this ad hoc problem. It tells us that we only need to consider elements forming subarrays in the given LL arrays.

Now, can we find a mathematical formula for calculating the sum of numbers in a submatrix? Let's resort to taking an example and trying to figure out a formula. Let us say we have N=3N=3. Also, let L1=a,b,xL1=a,b,x, L2=c,d,yL2=c,d,y and L3=e,f,zL3=e,f,z. Now, what is the sum of elements in the subarray bounded by elements M[1][1][1]M[1][1][1], M[2][2][2]M[2][2][2]? It is S=(ace+acf+ade+adf+bce+bcf+bde+bdf)S=(ace+acf+ade+adf+bce+bcf+bde+bdf). Let's simplify this further:
S=a(ce+cf+de+df)+b(ce+cf+de+df)S=a(ce+cf+de+df)+b(ce+cf+de+df)
⇒S=a(c+d)(e+f)+b(c+d)(e+f)⇒S=a(c+d)(e+f)+b(c+d)(e+f)
⇒S=(a+b)(c+d)(e+f)⇒S=(a+b)(c+d)(e+f)

The last line now hints towards the formal algorithm. Since, these elements belong to a submatrix, that reiterates the fact that aa, bb forms a subarray of L1L1, cc, dd forms a subarray of L2L2 and so on. Therefore, (a+b)(a+b) is subarray sum. So are (c+d)(c+d) and (e+f)(e+f). To maximise SS over all submatrices of MM, we need to maximise the subarray sums we take from each of the LL arrays. There can be another way by which we can maximise SS. By minimising the subarray sums. Why? Because LL arrays can contain negative numbers and if the overall subarray sum that we take is negative, then it can be multiplied with another negative sum from some other LL subarray to give positive overall. Why do we need to worry about only the maximum subarray sum and minimum subarray sum. The answer lies in greedy algorithm and exchange argument. If we have to take a positive sum from a subarray, the exchange argument says that we can always maximise SS by taking the maximum subarray sum rather than any other positive sum. Similarly, if we have to take a negative number, we can take the minimum subarray sum.

This gives us the formal algorithm:

For each of the LL arrays, i.e., L1L1, L2L2, L3L3, ..., LNLN, calculate the maximum sum subarray and the minimum sum subarray and the number of subarrays having the the maximum sum and the minimum sum. Let's denote maximum sum by low_high[i][1]low_high[i][1], minimum sum by low_high[i][0]low_high[i][0], and number of subarrays with maximum and minimum sum with cntsum[i][1]cntsum[i][1] and cntsum[i][0]cntsum[i][0] respectively (ii denotes data for LiLi). Since LiLi can have at most 9 elements, we can calculate all of this using naive O(N2)O(N2) algorithm, i.e., iterating over all subarrays.

For each of the LiLi, we store two more quantities. We store the number of subarrays which have sum 00 in z_nz[0]z_nz[0] and the number of subarrays which have non-zero sum in z_nz[1]z_nz[1]. We will see later in this editorial why we need these two quantities.

For a particular LiLi, how can we decide which one of the two options low_cost[i][1]low_cost[i][1] and low_cost[i][0]low_cost[i][0] to take in the product SS in order to maximise SS? Well, we can simply try all the 2N2N possible products and take the maximum over them as the answer. Since NN can be 9 at maximum, this algorithm is perfect. While calculating SS for a particular way out of the 2N2N ways, we can use the cnt_sumcnt_sum array to calculate the number of submatrices which have the same SS. If two different ways achieve the maximum SS, we can simply add the number of submatrices we calculated from cnt_sumcnt_sum.

Here is the pseudocode of the algorithm:

//Precomputation part:
low_high[i][1] = maximum subarray sum for the array L_i;
low_high[i][0] = minimum subarray sum for the array L_i;

cnt_sum[i][1] = number of subarrays of L_i having the maximum sum low_high[i][1];
cnt_sum[i][0] = number of subarrays of L_i having the minimum sum low_high[i][0];

z_nz[i][1] = number of subarrays of L_i having non-zero sum;
z_nz[i][0] = number of subarrays of L_i having sum 0;


//Main algorithm
Int_64 S = Negative Infinity; //the variable to be maximised.
int number_of_submatrices = 0; //Number of submatrices having sum S;

for(bitmask = 0 to 2^N-1)
{
    long long temp_S = 1;
    long long temp_cnt = 1;

    for(j = 0 to N-1)
    {
        if(jth bit in bitmask == true)
            temp_S *= low_high[j][1],
            temp_cnt *= cnt_sum[j][1];
        else
            temp_S *= low_high[j][0],
            temp_cnt *= cnt_sum[j][0];
    }

    if(temp_S > S)
        S = temp_S, number_of_submatrices = temp_cnt;
    else if(temp_S == S)
        number_of_submatrices += temp_cnt;
}

output (S and number_of_submatrices);
An important logical detail to note in the algorithm is what happens if for a particular array LiLi, low_high[i][1]low_high[i][1] and low_high[i][0]low_high[i][0] are equal. If we simply run the pseudocode above, we will end up double counting the number of submatrices having the maximum sum. Thus, if low_cost[i][1]==low_cost[i][0]low_cost[i][1]==low_cost[i][0] for some LiLi, then we set cnt_sum[i][0]=0cnt_sum[i][0]=0 (note, we could have set cnt_sum[i][1]cnt_sum[i][1] to 0. It doesn't matter as long as one is set to 0 to eliminate double counting).

One last part is left. What if SS comes out to be 0. In that case, There are many more subarrays having sum 0 than the above algorithm counts. Why? Because we can take any zero sum subarray of a particular LiLi and the non-zero subarrays of the other LL arrays and the eventual SS would be 0. We can take zero sum for xx out of the NN LL arrays and non-zero sums for the remaining N−xN−x. So many more ways than what our previous algorithm counted. Thus, in case of S=0S=0, we have to recount the number of submatrices in the following manner:

number_of_submatrices = 0; //reset the count to 0

for(bitmask = 1 to 2^N-1)
{
    long long temp_cnt = 1;

    for(j = 0 to N-1)
    {
        //Deciding whether to take non-zero or zero part of jth L array.
        if(jth bit in bitmask == true)
            tmp_cnt *= z_nz[j][1];
        else
            tmp_cnt *= z_nz[j][0];
    }

    number_of_submatrices += temp_cnt;
}

output (S and number_of_submatrices);
That completes the algorithm. The editorialist's solution mirrors the editorial. Please refer to it for implementation details.

COMPLEXITY:
O(2N)O(2N) per test case.  */

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)
 
using namespace std;
 
#define MAXN 11
int A[MAXN];
 
#define INF 1000000000000000000LL
#define MOD 1000000007
 
int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  while (T--) {
    int N;
    scanf("%d", &N);
    long long m = 1, M = 1, mcnt = 1, Mcnt = 1;
    long long nonzero_cnt = 1, zero_cnt = 0;
    while (N--) {
      int S;
      scanf("%d", &S);
      REP(i, S) scanf("%d", A + i);
      long long nm = INF, nM = -INF, nmcnt = 0, nMcnt = 0;
      long long new_nonzero_cnt = 0, new_zero_cnt = 0;
      REP(i, S) REP(j, i + 1) {
        int sum = 0;
        FOR(k, j, i) sum += A[k];
        // printf("N: %d sum: %d m: %lld M: %lld\n", N, sum, m, M);
 
        new_zero_cnt = (new_zero_cnt + zero_cnt) % MOD;
        if (sum == 0) new_zero_cnt = (new_zero_cnt + nonzero_cnt) % MOD;
        else new_nonzero_cnt = (new_nonzero_cnt + nonzero_cnt) % MOD;
 
        if (m * sum < nm) { nmcnt = 0; nm = m * sum; }
        if (m * sum == nm) nmcnt = (nmcnt + mcnt) % MOD;
 
        if (m * sum > nM) { nMcnt = 0; nM = m * sum; }
        if (m * sum == nM) nMcnt = (nMcnt + mcnt) % MOD;
 
        if (m < M) {
          if (M * sum < nm) { nmcnt = 0; nm = M * sum; }
          if (M * sum == nm) nmcnt = (nmcnt + Mcnt) % MOD;
 
          if (M * sum > nM) { nMcnt = 0; nM = M * sum; }
          if (M * sum == nM) nMcnt = (nMcnt + Mcnt) % MOD;
        }
      }
      m = nm; mcnt = nmcnt;
      M = nM; Mcnt = nMcnt;
      zero_cnt = new_zero_cnt;
      nonzero_cnt = new_nonzero_cnt;
      // printf("After N: %d m: %lld mcnt: %lld M: %lld Mcnt: %lld zero_cnt: %lld nonzero_cnt: %lld\n\n", N, m, mcnt, M, Mcnt, zero_cnt, nonzero_cnt);
    }
    if (M == 0) Mcnt = zero_cnt;
    printf("%lld %lld\n", M, Mcnt);
  }
  return 0;
}