#include <stdio.h>
#include <stdlib.h>
 

int readuint()
{
	int n = 0;
	char c = fgetc(stdin);
	do {
		n = n * 10 + (c - '0');
	} while ((c = fgetc(stdin)) != '\n');
return n;
}
void readuints(int* arr, int t, int nElemStrMaxLen)
{
	int len = (nElemStrMaxLen + 1) * t;
	char* str = (char*) malloc(len);
	char* c = str;
	register int n, z;
	fread(str, 1, len, stdin);
	int i;
	for (i = 0; i < t; i++) {
	n = 0;
	do {
	n = n * 10 + (*c - '0');
	} while (*(++c) != '\n');
	c++;
	z = 0;
	while (n >= 5) {
		n = (n << 1) / 10;
		z += n;
		}
		arr[i] = z;
	}
	free(str);
}
void writeuints(int* arr, int t, int nElemStrMaxLen)
{
	int len = (nElemStrMaxLen + 1) * t;
	char* str = (char*) malloc(len);
	char* c = str + len;
	for (t--; t >= 0; t--) {
	int n = arr[t];
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
int* arr = (int*) calloc(t, sizeof(int));
readuints(arr, t, 9);
writeuints(arr, t, 9);
free(arr);
return 0;
}
