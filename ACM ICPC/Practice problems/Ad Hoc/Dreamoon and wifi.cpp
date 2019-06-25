/*Dreamoon is standing at the position 0 on a number line. Drazil is sending a 
list of commands through Wi-Fi to Dreamoon's smartphone and Dreamoon follows them.

Each command is one of the following two types:

Go 1 unit towards the positive direction, denoted as '+'
Go 1 unit towards the negative direction, denoted as '-'
But the Wi-Fi condition is so poor that Dreamoon's smartphone reports some of the commands can't be recognized 
and Dreamoon knows that some of them might even be wrong though successfully recognized. Dreamoon decides to 
follow every recognized command and toss a fair coin to decide those unrecognized ones 
(that means, he moves to the 1 unit to the negative or positive direction with the same probability 0.5).

You are given an original list of commands sent by Drazil and list received by Dreamoon. 
What is the probability that Dreamoon ends in the position originally supposed to be final by Drazil's commands?

Input
The first line contains a string s1 — the commands Drazil sends to Dreamoon, 
this string consists of only the characters in the set {'+', '-'}.

The second line contains a string s2 — the commands Dreamoon's smartphone recognizes, 
this string consists of only the characters in the set {'+', '-', '?'}. '?' denotes an unrecognized command.

Lengths of two strings are equal and do not exceed 10.

Output
Output a single real number corresponding to the probability. 
The answer will be considered correct if its relative or absolute error doesn't exceed 10^ - 9.

Examples
input
++-+-
+-+-+
output
1.000000000000
input
+-+-
+-??
output
0.500000000000  */


import math

def nCr(n,r):
    f = math.factorial
    return f(n) / f(r) / f(n-r)

x=input()
plus = x.count('+')
minus = x.count('-')
x=input()
plus_ = x.count('+')
minus_ = x.count('-')
n=x.count('?')
a=plus-plus_
b=minus-minus_
if(a<0 or b<0 or a+b!=n):
    print(0.0)
else:
    print(nCr(n,a)/(1<<n))

///////////////////////////////////////////////////////

#include <cstdio>
#include <map>
char s[16],p[16];
int i,t;
std::map<int,double> d, nd;
int main(){
 gets(s); gets(p);
 for(d[0]=1;s[i];i++){
  t += 44-s[i];
  nd.clear();
  for (auto x:d)
   if (p[i]=='?')
    nd[x.first+1] += x.second/2,
    nd[x.first-1] += x.second/2;
   else
    nd[x.first+44-p[i]] += x.second;
  d = nd;
 }
 printf("%.10lf", d[t]);
}