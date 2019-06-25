/*Given an unordered list of assignment statements, write a program to determine whether the 
assignment statements can be put in some order in which all variables can be evaluated.

For our problem, an assignment statement will consist of an assignment variable, an assignment operator, 
and an expression, in that order. Statements will be evaluated one at a time, in the order you choose for them. 
A variable can be evaluated if and only if it has been the assignment variable of a previous assignment statement.

To simplify the problem, all the expressions are single function calls. Functions can take an arbitrary number 
of arguments, including zero; a function with zero arguments is always valid, and a function with variable arguments 
is valid as long as all of the variables are evaluatable.

For example, for the following list of assignment statements:

a=f(b,c)
b=g()
c=h()
this is one order that makes every statement valid:

b=g()
c=h()
a=f(b,c)
This is because: (1) b and c can be evaluated because the expressions g() and h() don't depend on any variables; 
and (2)a can also be evaluated because expression a depends on b and c, which are evaluatable.
Input

The first line of the input gives the number of test cases, T. T test cases follow. The first line of each test case 
contains an integer N: the number of assignment statements. Then, N lines follow. Each contains one assignment statement.

Each assignment statement consists of three parts: the assignment variable, the assignment operator, and the expression, 
with no spaces in between. The assignment operator is always =. All expressions consist of a function name, then (, 
then zero or more comma-separated variable names, then ). All variables and function names consist of one or more lowercase 
English alphabet letters. No variable has the same name as a function. No variable will appear more than once as the assignment variable. 
However, variables may appear more than once in various functions (even within the same function), and functions may appear more than once.

Output

For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) 
and y is GOOD if all variables are evaluatable or BAD otherwise.

Limits

1 = T = 20.
All functions take between 0 and 10 arguments, inclusive. All variable names consist of between 1 and 20 lowercase English alphabet letters.

Small dataset

1 = N = 100.
Large dataset

1 = N = 1000.
Sample


Input 
 	
Output 
 
4
3
a=f(b,c)
b=g()
c=h()
2
a=f(b)
b=f(a)
2
aaa=foo(x,y)
bbb=bar(aaa,bbb)
2
x=f()
y=g(x,x)*/

int T;
int n;
string s;
char x[100000];
string var[1005];
vector<string> varr[1005];
string now;
vi adj[1005];
bool cycle;
int state[1005];
set<string> ada;

void dfs(int now)
{
  state[now] = 1;
  REP(i,0,SIZE(adj[now]))
  {
    if (state[adj[now][i]] == 1) cycle = 1;
    if (state[adj[now][i]] == 0) dfs(adj[now][i]);
  }
  state[now] = 2;
}

int main()
{
  scanf("%d",&T);
  REPN(cases,T)
  {
    printf("Case #%d: ",cases);
    ada.clear();
    scanf("%d",&n);
    REP(i,0,n)
    {
      scanf("\n");
      varr[i].clear();
      adj[i].clear();
      scanf("%[^=]",x);
      var[i] = x;
      scanf("%[^(]",x); getchar(); scanf("%s",x); s = x;
      string ss = "";
      REP(j,0,SIZE(s))
      {
        if (s[j] == ')' || s[j] == ',')
        {
          if (SIZE(ss) > 0) varr[i].pb(ss);
          ss = "";
        } else ss += s[j];
      }
    }
    REP(i,0,n) ada.insert(var[i]);
    REP(i,0,n)
    {
      REP(j,0,SIZE(varr[i]))
      {
        if (ada.count(varr[i][j]) == 0)
        {
          puts("BAD");
          goto hell;
        }
      }
    }
    REP(i,0,n)
    {
      REP(j,0,n)
      {
        REP(k,0,SIZE(varr[j])) if(varr[j][k] == var[i])
        {
          adj[i].pb(j);
        }
      }
    }
    RESET(state,0);
    cycle = 0;
    REP(i,0,n) if(state[i] == 0) dfs(i);
    puts(cycle ? "BAD" : "GOOD");
    hell:;
  }
  return 0;
}









