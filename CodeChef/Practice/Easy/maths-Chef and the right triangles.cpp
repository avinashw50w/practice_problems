/*The Chef is given a list of N triangles. Each triangle is identfied by the coordinates of its three corners in the 2-D cartesian plane. His job is to figure out how many
of the given triangles are right triangles. A right triangle is a triangle in which one angle is a 90 degree angle. The vertices
of the triangles have integer coordinates and all the triangles given are valid( three points aren't colinear ).  
 
Input

The first line of the input contains an integer N denoting the number of triangles. Each of the following N
lines contain six space separated integers x1 y1 x2 y2 x3 y3 where (x1, y1),
(x2, y2) and (x3, y3) are the vertices of a triangle.
 
Output

Output one integer, the number of right triangles among the given triangles.
 
Constraints

1 ≤ N ≤ 100000 (105)
0 ≤ x1, y1, x2, y2, x3, y3 ≤ 20
 
Example

Input:
5
0 5 19 5 0 0
17 19 12 16 19 0
5 14 6 13 8 7
0 4 0 14 3 14
0 2 0 14 9 2

Output:
3*/

int main() {
	int t=inp();
	int x1,x2,x3,y1,y2,y3;
	int d1,d2,d3;
	int ans=0;
	while(t--){
		cin>>x1>>y1>>x2>>y2>>x3>>y3;

		d1=(int)(pow((x1-x2),2)+pow((y1-y2),2));
		d2=(int)(pow((x1-x3),2)+pow((y1-y3),2));
		d3=(int)(pow((x3-x2),2)+pow((y3-y2),2));
		
		if(d1>=d2 and d1>=d3) { if(d1==d2+d3) ans++; }
		else if(d2>=d1 and d2>=d3) { if(d2==d1+d3) ans++; }
		else if(d3>=d1 and d3>=d2) { if(d3==d2+d1) ans++; }
	}
	printf("%d\n",ans) ;
	return 0;
}
