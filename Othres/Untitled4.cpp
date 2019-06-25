#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define SIZE 65536
 
int main(int argc, char *argv[]) {
    char buffer[SIZE];
    unsigned long n, k, ti, d;
    int c, j;
 
    d = 0;
    scanf("%lu %lu\n", &n, &k);
 
    ti = 0;
    while ( (c=fread(buffer, 1, SIZE, stdin)) > 0) {
 
        for (j=0;j<c;j++) {
            if (buffer[j] == '\n') {
                if (ti % k == 0) d++;
                ti = 0;
            } else {
                ti = ti*10 + (buffer[j] - '0');
            }
        }
 
    }
 
    printf("%lu\n", d);
 
    return 0;
}
