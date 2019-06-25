/*Ten-year-old Tangor has just discovered how to compute the area of a triangle. Being a bright boy, he is amazed by how many different ways 
one can compute the area. He also convinced himself that, if all the points of the triangle have integer coordinates, 
then the triangle's area is always either an integer or half of an integer! Isn't that nice?

But today Tangor is trying to go in the opposite direction. Instead of taking a triangle and computing its area, he is taking an integer A 
and trying to draw a triangle of area A/2. He restricts himself to using only the integer points on his graph paper for the triangle's vertices.

More precisely, the sheet of graph paper is divided into an N by M grid of square cells. 
The triangle's vertices may only be placed in the corners of those cells. If you imagine a coordinate system on the paper, 
then these points are of the form (x, y), where x and y are integers such that 0 ≤ x ≤ N and 0 ≤ y ≤ M.

Given the integer A, help Tangor find three integer points on the sheet of graph paper such that the area of the triangle 
formed by those points is exactly A/2, if that is possible. In case there is more than one way to do this, any solution will make him happy.

Input

One line containing an integer C, the number of test cases in the input file.

The next C lines will each contain three integers N, M, and A, as described above.

Output

For each test case, output one line. If there is no way to satisfy the condition, output

Case #k: IMPOSSIBLE
where k is the case number, starting from 1. Otherwise, output
Case #k: x1 y1 x2 y2 x3 y3
where k is the case number and (x1, y1), (x2, y2), (x3, y3) are any three integer points on the graph paper that form a triangle of area A/2.
Limits

0 ≤ C ≤ 1000

1 ≤ A ≤ 108

Small dataset

1 ≤ N ≤ 50

1 ≤ M ≤ 50

Large dataset

1 ≤ N ≤ 10000

1 ≤ M ≤ 10000

Sample


Input 

Output 
3
1 1 1
1 2 64
10 10 1

Case #1: 0 0 0 1 1 1
Case #2: IMPOSSIBLE
Case #3: 1 1 2 3 5 8
*/

int main()
{
    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        int X, Y, A;
        cin >> X >> Y >> A;
        printf("Case #%d: ", cas + 1);
        if (A > X * Y)
            printf("IMPOSSIBLE\n");
        else
        {
            int x1, y1, x2, y2;
            x1 = X; y1 = 1;
            x2 = -(A % X);
            while (x2 < 0) x2 += X;         
            y2 = (A + x2) / X;

            printf("0 0 %d %d %d %d\n", x1, y1, x2, y2);
        }
    }
    return 0;
}


//  Here’s a formula to use, based on the counterclockwise entry of the coordinates of the vertices of the triangle 
// (x1, y1), (x2, y2), (x3, y3) or (2, 1), (8, 9), (1, 8): 2A = x1y2 + x2y3 + x3y1 – x1y3 – x2y1 – x3y2.
// ie. A = 1/2 * ( x1(y2-y3) + x2(y3-y1) + x3(y1-y2) )