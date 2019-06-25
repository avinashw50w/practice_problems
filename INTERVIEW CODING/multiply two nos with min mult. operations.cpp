/*Adobe: Multiply two numbers without using * operator, and minimum number of additions.*/

int mul(int m,int n)
{
   // make it more efficient 
    if(m<n)
     {
      int temp =m;
      m=n;
      n=temp;
     }   
 int v=0;
 if(n==1) 
      return m;
 v = mul(m,n>>1);
 v = v+v;
 if(n&1) 
      v+= m;
 return v;
}