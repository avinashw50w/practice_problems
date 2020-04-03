/* Eugene has a sequence of upper hemispheres and another of lower hemispheres. The first set consists of N upper hemispheres indexed 1 to N 
and the second has M lower hemispheres indexed 1 to M. The hemispheres in any sequence can have different radii.
He is now set out on building spheres using them. To build a sphere of radius R, he must take one upper half of the radius R and one lower half 
of the radius R. Also, he can put a sphere into a bigger one and create a sequence of nested concentric spheres. But he can't put two or more 
spheres directly into another one.
Examples:


If there is a sequence of (D+1) nested spheres, we can call this sequence as a D-sequence.


Eugene has to find out how many different X-sequence are possible (1 <= X <= C). An X sequence is different from another if the index of 
any of the hemisphere used in one X-sequence is different from the other. Eugene doesn't know how to do it, so Chef agreed to help him. 
Of course, Chef is too busy now and he asks you to help him.
Input

The first line contains a three integers: N denoting the number of upper sphere halves, M denoting the number of lower sphere halves and C.
The second line contains N space-separated integers U1, U2, ..., UN denoting the radii of upper hemispheres.
The third line contains M space-separated integers L1, L2, ..., LM denoting the radii of lower hemispheres.
Output

Output a single line containing C space-separated integers D1, D2, ..., DC, where Di is the number of ways there are to build i-sequence in modulo 109+7.
Constraints

1 = N = 105
1 = M = 105
1 = C = 103
1 = Ui = C
1 = Li = C
Subtasks

Subtask 1: 1 = N, M, C = 10 - 15 points
Subtask 2: 1 = N, M, C = 100 - 25 points
Subtask 3: Original constraints - 60 points
Example

Input:
3 4 3
1 2 3
1 1 3 2

Output:
5 2 0
Explanation

We can build spheres with such radii:
R=1 and there are 2 ways to do it. (We can choose any of 2 lower hemispheres with R=1)
R=2 and there is 1 way to do it.
R=3 and there is 1 way to do it.
We can build these 1-sequences:
1->2 and there are 2 ways to do it. ( sphere with radius 1 is inside sphere with radius 2, we can choose any of 2 ways of building sphere with radius 1)
1->3 and there are 2 ways to do it.
2->3 and there is 1 way to do it.
2 + 2 + 1 = 5
We can build these 2-sequences:
1->2->3 and there are 2 ways to do it.
We can't build 3-sequences, because we don't have 4 spheres of different radii.*/

#include<stdio.h>
int main(){
  int n,m,c,i,j,num;
  unsigned long long rad1[1009]={0},rad2[1009]={0},rad[1009]={0};
  unsigned long long s_cum[1009]={0};
  unsigned long long temp,x[1009]={0};
  scanf("%d %d %d",&n,&m,&c);
  for(i=0;i<n;++i){
    scanf("%d",&num);
    rad1[num]+=1;
  }
  for(i=0;i<m;++i){
    scanf("%d",&num);
    rad2[num]+=1;
  }
  for(i=1;i<=1000;++i){
    rad[i]=rad1[i]*rad2[i];
  }
  s_cum[1]=rad[1];
  for(i=2;i<=1000;++i)
    s_cum[i]=s_cum[i-1]+rad[i];
  for(i=2;i<=1000;++i){
    for(j=i-2;j>=1;--j){
      temp=x[j]*rad[i];

      x[j+1]+=temp;
      x[j+1]=x[j+1]%1000000007;
    }
    temp=s_cum[i-1]*rad[i];
 
    x[1]+=temp;
    x[1]=x[1]%1000000007;
  }
  for(i=1;i<=c;++i)
    printf("%llu ",(x[i]%1000000007));
  return 0;
}
 
