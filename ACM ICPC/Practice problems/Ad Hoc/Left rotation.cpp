/*A left rotation operation on an array of size n shifts each of the array's elements d unit to the left. 
For example, if 2 left rotations are performed on array , 
[1,2,3,4,5] then the array would become [3,4,5,1,2].

Given an array of n integers and a number, d, perform d left rotations on the array. Then print the updated array as a single line of space-separated integers.*/

int main() {
    
    int n, d, a[1000000+2], b[1000000+2];
    
    cin>>n>>d;
    
    for(int i=0;i<n;++i) cin>>a[i];
    
    for(int i=0;i<n;++i){
        int x = i-d;
        while(x<0) x += n;
        b[x%n] = a[i];
    }
    
    for(int i=0;i<n;++i) cout <<b[i] <<" ";
    cout << endl;
    return 0; 
}
