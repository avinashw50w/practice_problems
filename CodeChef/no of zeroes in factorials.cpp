/*
For example, they defined the function Z. For any positive integer N, Z(N) is the number of zeros at the end of the decimal form of number N!. They noticed that 
this function never decreases. If we have two numbers N1<N2, then Z(N1) <= Z(N2). It is because we can never "lose" any
trailing zero by multiplying by any positive number. We can only get new and new zeros. The function Z is very interesting, so we need a computer program that 
can determine its value efficiently.
Input
There is a single positive integer T on the first line of input (equal to about 100000). It stands for the number of numbers to follow. Then there are T lines, 
each containing exactly one positive integer number N, 1 <= N <= 1000000000.
Output
For every number N, output a single line containing the single non-negative integer Z(N).
Example

Sample Input:
6
3
60
100
1024
23456
8735373
Sample Output:
0
14
24
253
5861
2183837
*/
#include <stdio.h>
#include <stdlib.h>               // we've to find the no of 5's in the number
 								//for eg. take 300! , keep dividing it by 5 and store the result  
			                   // 300/5=60 , 60/5=12 , 12/5=2 , so the total no of 5's are 60+12+2=74   ,ie. the no of zeroes in 300! is 74 
             // keep dividing the number till its >=5
        // num = (num*2) / 10
                    // keep storing the result

int readuint()
{
int n = 0;
char c = fgetc(stdin);             // read char from stdin
do {                               
n = n * 10 + (c - '0');              // convert the charachter to interger
} while ((c = fgetc(stdin)) != '\n');      // keep converting till new line occurs
return n;
}
void readuints(int* nArray, int nCount, int nElemStrMaxLen)     // for reading the testcases as a whole from stdin
{
int len = (nElemStrMaxLen + 1) * nCount;               // total length needed to store the whole testcases as charachters
char* str = (char*) malloc(len);                    // allocating a char array for storing the testcases
char* c = str;
register int n, z;
fread(str, 1, len, stdin);           // reading the test cases from stdin
int i;
for (i = 0; i < nCount; i++) {
n = 0;
do {
n = n * 10 + (*c - '0');          // converting each testcase which was taken as a string to integers
} while (*(++c) != '\n');
c++;
z = 0;
while (n >= 5) {
n = (n << 1) / 10;
z += n;
}
nArray[i] = z;
}
free(str);
}
void writeuints(int* nArray, int nCount, int nElemStrMaxLen)
{
int len = (nElemStrMaxLen + 1) * nCount;
char* str = (char*) malloc(len);
char* c = str + len;
for (nCount--; nCount >= 0; nCount--) {
int n = nArray[nCount];
*(--c) = '\n';
do {
*(--c) = n % 10 + '0';
n /= 10;
} while (n > 0);
}
fwrite(c, 1, str + len - c, stdout);
free(str);
}
int main()
{
int t = readuint();
int* nArray = (int*) calloc(t, sizeof(int));
readuints(nArray, t, 9);
writeuints(nArray, t, 9);
free(nArray);
return 0;
}
