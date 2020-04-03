#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int a[21]={1,9,45,55,99,297,703,999,2223,2728,4950,5050,7272,7777,9999,17344,22222,77778,82656,95121,99999};
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int p,q;
	cin>>p>>q;
	bool outputed=false;
	for(int i=0;i<21;++i)
		if(a[i]>=p && a[i]<=q)
		{
			outputed=true;
			cout<<a[i]<<" ";
		}
	if(!outputed)
		cout<<"INVALID RANGE";
    return 0;
}

