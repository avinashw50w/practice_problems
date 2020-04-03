/*Given a string, , of lowercase letters, determine the index of the character whose removal will make  a palindrome. 
If  is already a palindrome or no such character exists, then print -1. There will always be a valid solution, and any correct answer is acceptable. 
For example, if  "bcbc", we can either remove 'b' at index  or 'c' at index .

Input Format

The first line contains an integer, , denoting the number of test cases. 
Each line  of the  subsequent lines (where ) describes a test case in the form of a single string, .*/

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t;cin>>t;
    while(t--){
        string s; cin>>s;
        int n = s.size();
        int indx, f=0, i, j, x, y;
        for(i=0;i<n/2;++i){
            if(s[i]!=s[n-i-1]) break;
        }
        if(i==n/2){
            if(n%2==1) {
                cout<<n/2<<endl;
                continue;
            }
        }
        for(x=i+1,y=j;x<y;++x,--y)
            if(s[x] != s[y])
                break;
        if(x>=y){ cout << i << endl; continue; }
        
        for(x=i,y=j-1;x<y;++x,--y)
            if(s[x] != s[y])
                break;
        if(x>=y){ cout << j << endl; continue; }
        
        cout << -1 << endl;
    }
    return 0;
}
