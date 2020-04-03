//start of jonathanirvings' template v3.0.3 (BETA)

/*Codejamon trainers are actively looking for monsters, but if you are not a trainer, these monsters could be 
really dangerous for you. You might want to find safe places that do not have any monsters!

Consider our world as a grid, and some of the cells have been occupied by monsters. We define a safe square 
as a grid-aligned D × D square of grid cells (with D = 1) that does not contain any monsters. Your task is to 
find out how many safe squares (of any size) we have in the entire world.
Input

The first line of the input gives the number of test cases, T. T test cases follow. Each test case starts with a 
line with three integers, R, C, and K. The grid has R rows and C columns, and contains K monsters. K more lines follow; 
each contains two integers Ri and Ci, indicating the row and column that the i-th monster is in. (Rows are numbered 
from top to bottom, starting from 0; columns are numbered from left to right, starting from 0.)
Output

For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y 
is the the total number of safe zones for this test case.
Limits

1 = T = 20.

(Ri, Ci) ? (Rj, Cj) for i ? j. (No two monsters are in the same grid cell.)

0 = Ri < R, i from 1 to K

0 = Ci < C, i from 1 to K

Small dataset

1 = R = 10.

1 = C = 10.

0 = K = 10.

Large dataset

1 = R = 3000.

1 = C = 3000.

0 = K = 3000.

Sample


Input 
 	
Output 
 
2
3 3 1
2 1
4 11 12
0 1
0 3
0 4
0 10
1 0
1 9
2 0
2 4
2 9
2 10
3 4
3 10
Case #1: 10
Case #2: 51
The grid of sample case #1 is:

0 0 0
0 0 0
0 1 0
Here, 0 represents a cell with no monster, and 1 represents a cell with a monster. It has 10 safe squares: 8 1x1 and 2 2x2.*/

int T;
int r,c,k,a,b;
int ada[3005][3005];
int bawah[3005][3005], kanan[3005][3005], dig[3005][3005];

int main()
{
  scanf("%d",&T);
  REPN(cases,T)
  {
    printf("Case #%d: ",cases);
    RESET(ada,0);
    RESET(bawah,0);
    RESET(kanan,0);
    RESET(dig,0);
    scanf("%d %d %d",&r,&c,&k);
    TC(k)
    {
      scanf("%d %d",&a,&b);
      ada[a][b] = 1;
    }
    PER(i,r-1,0)
    {
      REP(j,0,c)
      {
        if (ada[i][j]) bawah[i][j] = 0;
        else bawah[i][j] = bawah[i+1][j] + 1;
      }
    }
    PER(j,c-1,0)
    {
      REP(i,0,r)
      {
        if (ada[i][j]) kanan[i][j] = 0;
        else kanan[i][j] = kanan[i][j+1] + 1;
      }
    }
    LL risan = 0;
    PER(i,r-1,0)
    {
      REP(j,0,c)
      {
        dig[i][j] = min(bawah[i][j],kanan[i][j]);
        dig[i][j] = min(dig[i][j],dig[i+1][j+1] + 1);
        risan += dig[i][j];
      }
    }
    printf("%lld\n",risan);
  }
  return 0;
}









