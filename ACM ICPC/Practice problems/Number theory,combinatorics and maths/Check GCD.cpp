/*Devu is a student of Mathematics. He has just gotten to know about GCD.

Now, he has a set S having N elements. He wants to check if there is any subset of S whose gcd is K. As the number of subsets can be very large, 
he wants your help checking it.

Input Format

The first line will contain a number T, the number of test cases.

The first line of each test case will contain two integers, N and K. The second line of each test case will contain integers, S1...Sn.*/

/*Let L be the list of all numbers from S which are divisible by K. 

Let us consider that there is a subset S' of S whose GCD is K. By the property of the GCD, we can claim that each number will be divisible by K. 
This says that all members of S' must be members of L. 

Now, we can see that any subset of the list L will have GCD either K or a multiple of K.Now calculate the GCD of all numbers of L,and call it g. 
There are two cases: 

Case 1:
g = K. Then the list L is our subset and answer will be YES. 

Case 2:
 g = mK , where m>1. Now any subset of list L will have GCD either mK or a multiple of mK. So no subset of given set will have GCD K. hence, 
 answer will be NO.*/
 
int a[MAXN];
int main() {
    int n, k;
    caset{
        si(n); si(k);
        vector<int> v;
        rep(i,0,n){
            si(a[i]);
            if(a[i]%k == 0) v.push_back(a[i]);
        }

        int len = v.size();
        if(len == 0){ printf("NO\n"); continue; }
        if(len == 1){ 
            if(v[0] == k) printf("YES\n");
            else printf("NO\n");
            continue;
        }
        int g = __gcd(v[0], v[1]);
        rep(i,2,len)
            g = __gcd(g, v[i]);
        
        if(g == k) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
