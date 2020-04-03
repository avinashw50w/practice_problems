#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cmath>
 
using namespace std;
 
const int M = 1<<18;
 
int heads_up[M<<1]; // it counts the number of heads-up coins in subtree, regardless of the operations made on it, and it parent,grandparent, grandgrandparent ...
int times[M<<1]; // it counts the parity of the number of flipping this subtree
 
void add(int a, int b, int p, int k, int v)  { // flip coins on interval [a,b], [p,k] is actual interval, v is actual vertex
        if(k < a or p > b) // no intersction
                return; // if [p,k] has no intersection with [a,b], we end
        else if(a <= p && k <= b)  // [p,k] is in [a,b] so we can just change the parity of changes on this subtree
                times[v]^=1;
        else { // partial
                int sum = 0;
                add(a,b,p,(p+k)/2,v*2);
                add(a,b,(p+k)/2+1,k,v*2+1);
                if(times[v*2] == 0) // if left son has been flipped even times we add him to the result normally
                        sum += heads_up[v*2];
                else // else we add the rest of the interval [p,k]
                        sum += (k-p+1)/2 - heads_up[v*2];
                if(times[v*2+1] == 0) // the same with right son
                        sum += heads_up[v*2+1];
                else
                        sum += (k-p+1)/2-heads_up[v*2+1];
                heads_up[v] = sum;
        }
}
 
int query(int a, int b, int p, int k, int v, int xsum) // a,b,p,k,v means the same, xsum is xor sum from 1 to v. We need this, because we keep heads_up regardless 
														//of what has happened to vertexes up v.
{
        if(k < a or p > b) // no intersction, result is zero
                return 0;
        else if(a <= p && b >= k) { // fully
                if((xsum^times[v]) == 0) // if v was flipped even times, return normally
                        return heads_up[v];
                else // return rest of interval [p,k]
                        return (k-p+1)-heads_up[v];
        }
        else { // partial
                int sum = 0; // partial intersection, so just walk down to left and right son
                sum += query(a,b,p,(p+k)/2,v*2,xsum^times[v]);
                sum += query(a,b,(p+k)/2+1,k,v*2+1,xsum^times[v]);
                return sum;
        }
}
 
 
int main () {
        int n,q,t,a,b;
        cin >> n >> q;
        while(q--) {
                cin >> t >> a >> b;
                if(t == 0)
                        add(a,b,0,M-1,1);
                else
                        cout << query(a,b,0,M-1,1,0) << endl;
        }
}