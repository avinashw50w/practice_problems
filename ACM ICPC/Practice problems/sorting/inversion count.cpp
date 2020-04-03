/*Today is the reunion of all chefs in the world. Our Chef wants to make this moment more happier. He arranged a mass wedding in this reunion. 
For this, he made a strange stage and drew two horizontal parallel lines on the stage. There are N unmarried male chefs in the reunion and he 
gave each male chef i an unique number Mi. Then all male chefs will stand in the first line drawn by Chef. But they will stand in increasing 
order of their number. That means chef with the lowest number will stand at the leftmost position of the line, then right to him would be the 
chef with the second lowest number and so on. Similarly, there are N female chefs in the reunion and Chef also gave each female chef j an 
unique number Fj (sequences Fj and Mi can have equal numbers). Then all female chefs will stand in the other line following the same rule
(will stand in increasing order of the numbers) as the male chef.

Now chef will choose all the marriage pairs himself. He will select a female chef and a male chef (both of them have not selected before) 
and will draw a straight line between them. He calls this line a marriage line. He will do this for the rest of the chefs.

You will be given the N marriage lines; you have to find how many marriage line pairs intersect with each other.

Input

First line contains a single integer N. The i-th line of the next N lines contain two space separated integers Mi and Fi, means there is a 
marriage line between male chef Mi and female chef Fi. No marriage line will be mentioned twice.

Output

Output the number of marriage line pairs that intersect with each other on a single line.

Constraints

1 ≤ N ≤ 100000 (105)
0 ≤ Mi, Fi ≤ 1000000000 (109)
 

Example

Input:
3
2 3
3 6
5 4

Output:
1*/
#define male first
#define fem second
vii a;
int n, m, f;
ll inv = 0;

void merge(int l,int mid,int r){
	int i,j,k,p;
	i = l;
	j = mid+1;
	k = 0;
	vii tmp(r-l+2);
	while(i<=mid and j<=r){
		if(a[i].fem<=a[j].fem)
			tmp[k++] = a[i++];
		else{
			inv += mid-i+1;
			tmp[k++] = a[j++];
		}
	}
	while(i<=mid) tmp[k++] = a[i++];
	while(j<=mid) tmp[k++] = a[j++];
	rep(i,0,k)
		a[l+i] = tmp[i];
}

void mergesort(int l,int r){
	if(l<r){
		int mid = (l+r)>>1;
		mergesort(l,mid);
		mergesort(mid+1,r);
		merge(l,mid,r);
	}
}
int main() {
	int n; si(n);
	rep(i,0,n){
		si(m); si(f);
		a.push_back({m,f});
	}
	sort(a.begin(),a.end());
	mergesort(0,n-1);
	printf("%lld\n", inv);

	return 0;
}
