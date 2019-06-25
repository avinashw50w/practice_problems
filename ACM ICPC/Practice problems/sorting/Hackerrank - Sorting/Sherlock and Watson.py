''' John Watson performs an operation called Right Circular Rotation on an integer array [a0,a1,...aN−1]. Right Circular Rotation transforms the array from [a0,a1,...aN−1] to [aN−1,a0,...,aN−2].

He performs the operation K times and tests Sherlock's ability to identify the element at a particular position in the array. He asks Q queries. Each query consists of one integer, idx, for which you have to print the element at index idx in the rotated array, i.e. aidx.

Input Format 
The first line consists of three integers, N, K, and Q,, separated by a single space. 
The next line contains N space-separated integers which indicate the elements of the array A. 
Each of the next Q lines contains one integer per line denoting idx.

Output Format 
For each query, print the value at index idx in the updated array separated by newline.

Constraints

1≤N≤105
1≤ai ≤105
1≤K≤105
1≤Q≤500
0≤idx≤N−1
Sample input

3 2 3
1 2 3
0
1
2
Sample output

2
3
1 
'''
# Enter your code here. Read input from STDIN. Print output to STDOUT
#!/usr/bin/py
if __name__ == '__main__':
    n,k,q = map(int, raw_input().split())
    arr = map(int, raw_input().split())
    for _ in xrange(q):
        x = int(raw_input())
        print arr[(x-k)%n]


# c++ code:
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    ll n,k,q;
    cin>>n>>k>>q;
    ll a[n+1];
    for(int i=0;i<n;i++)cin>>a[i];
    ll x;
    while(q--){
        cin>>x;
        ll pos=x-k;
        while(pos<0) pos+=n;
        cout<<a[pos%n]<<endl;
    }
    return 0;
}