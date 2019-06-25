/*All submissions for this problem are available.

Hermione Granger, the most talented witch of her generation, likes to solve various types of mathematical problems in the Arithmancy class. 
Today, the professor has given her the following task: 
Find the number of fractions a/b such that- 
1.	gcd(a, b) = 1     2. 0 < a/b < 1    3. a * b = (n!) ^ (n!) Where "n!" denotes the factorial of n and "^" denotes power, i.e. (2!) ^ (2!) = 4.

She is quite confident that she can solve it for n <= 10,000,000 (i.e. 10^7), but then she remembers that she has to study 
some case history so that she can help Hagrid to win the case of Buckbeak. So, she wants your help to solve the problem.
Input

There will be one line for each test case containing the number n (1 <= n <= 10,000,000). Input will be terminated by EOF. 
There will be around 20,000 test cases.
Output

For each case, print the number of fractions in a separate line. This number may be very large, so print the answer modulo 10,007.
Example

Input:
1
2

Output:
0
1
*/

vector<int> v;
vector<bool> a(N,true);
int pow1(int a,int b){
    int ans = 1;
    while(b>0){
        if(b & 1){
            ans = (ans * a) % MOD;
        }
        b = b<<1;
        a = (a * a) % MOD;
    }
    return ans % MOD;
}
int main()
{
    int i,j;
    v.pb(2);
    for(i=2*2;i<=N;i=i+2)
        a[i]=false;
    for(i=3;i<=3163;i=i+2){
        if(a[i]){
            v.pb(i);
            for(j=i*i;j<=N;j=j+i+i)
                a[j]=false;
        }
    }
    //for(i=3163;i<=N;i++)
    while(i<=N){
        if(a[i])
            v.pb(i);
        i=i+2;
    }
    //cout<<v.size();
    int n;
    while(scanf("%d",&n)==1){
        if(n==1)
            cout<<"0"<<endl;
        else{
            int index = (int)(upper_bound(v.begin(),v.end(),n) - v.begin());
            //cout<<index<<endl;
            int ans = pow1(2,index - 1);
            //cout<<ans<<endl;
            printf("%d\n",ans);
        }
    }
    //system("pause");
 
}