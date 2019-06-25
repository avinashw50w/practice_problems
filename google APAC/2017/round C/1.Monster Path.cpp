/*Codejamon is a mobile game in which monster trainers walk around in the real world to catch monsters. You have an old smartphone with a short battery life, so you need to choose your path carefully to catch as many monsters as possible.

Suppose the Codejamon world is a rectangular grid with R rows and C columns. Rows are numbered from top to bottom, starting from 0; columns are numbered from left to right, starting from 0. You start in the cell in the Rsth row and the Csth column. You will take a total of S unit steps; each step must be to a cell sharing an edge (not just a corner) with your current cell.

Whenever you take a step into a cell in which you have not already caught a monster, you will catch the monster in that cell with probability P if the cell has a monster attractor, or Q otherwise. If you do catch the monster in a cell, it goes away, and you cannot catch any more monsters in that cell, even on future visits. If you do not catch the monster in a cell, you may still try to catch the monster on a future visit to that cell. The starting cell is special: you have no chance of catching a monster there before taking your first step.

If you plan your path optimally before making any move, what is the maximum possible expected number of monsters that you will be able to catch?

The battery can only support limited steps, so hurry up!
Input

The first line of the input gives the number of test cases, T. T test cases follow.

Each test case starts with a line of five integers: R, C, Rs, Cs and S. R and C are the numbers of rows and columns in the grid; Rs and Cs
are the numbers of the row and column of your starting position, and S is the number of steps you are allowed to take.

The next line contains two decimals P and Q, where P is the probability of meeting a monster in cells with a monster attractor, 
and Q is the probability of meeting a monster in cells without a monster attractor. P and Q are each given to exactly four decimal places.

Each of the next R lines contains contains C space-separated characters; the j-th character of the i-th line represents the cell at 
row i and column j. Each element is either . (meaning there is no attractor in that cell) or A (meaning there is an attractor in that cell).

Output

For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the largest possible 
expected number of monsters that the player can catch in the given amount of steps.

y will be considered correct if y is within an absolute or relative error of 10-6 of the correct answer. See the FAQ for an explanation of 
what that means, and what formats of real numbers we accept.

Limits

1 = T = 100.
0 = Rs < R.
0 = Cs < C.
0 = Q < P = 1.
Small dataset

1 = R = 10.
1 = C = 10.
0 = S = 5.
Large dataset

1 = R = 20.
1 = C = 20.
0 = S = 9.*/

int T;
int r,c,s;
double p,q;
pii mulai;
char data[25][25];
int ada[25][25];
int visit[25][25];
double risan;

void dfs(int x, int y, int steps)
{
  if (steps < 0) return;

  if (steps == 0)
  {
    double temp = 0;
    REP(i,r) REP(j,c)
    {
      if (visit[i][j] == 0) continue;
      double X = pow(1-q,visit[i][j]);
      if (ada[i][j]) X = pow(1-p,visit[i][j]);

      temp += (1 - X);
    }
    //VALUE(temp);
    MAX(risan,temp);
    return;
  }

  REP(i,4)
  {
    int xx = x + dirx[i];
    int yy = y + diry[i];
    if (0 <= xx && xx < r && 0 <= yy && yy < c)
    {
      ++visit[xx][yy];
      dfs(xx,yy,steps-1);
      --visit[xx][yy];
    }
  }
}

int main()
{
  scanf("%d",&T);
  REPN(cases,T)
  {
    printf("Case #%d: ",cases);
    scanf("%d %d %d %d %d",&r,&c,&mulai.fi,&mulai.se,&s);
    scanf("%lf %lf",&p,&q);
    REP(i,r)
    {
      REP(j,c)
      {
        scanf(" ");
        scanf("\n");
        scanf(" ");
        scanf("%c",&data[i][j]);
      }
    }
    RESET(ada,0);
    REP(i,r) REP(j,c)
    {
      if (data[i][j] == 'A')
      {
        ada[i][j] = 1;
      }
    }
    risan = 0;
    dfs(mulai.fi,mulai.se,s);

    printf("%.10lf\n",risan);
  }
  return 0;
}









