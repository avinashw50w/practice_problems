#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define SIZE 65536
 
int main(int argc, char *argv[]) {
    char buffer[SIZE];
    unsigned long n, k, t, divisible;
    int c, j;
 
    d = 0;
    scanf("%lu %lu\n", &n, &k);
 
    t = 0;
    while ( (c=fread(buffer, 1, SIZE, stdin)) > 0) {
 
        for (j=0;j<c;j++) {
            if (buffer[j] == '\n') {
                if (t % k == 0) divisible++;
                t = 0;
            } else {
                t = t*10 + (buffer[j] - '0');
            }
        }
 
    }
 
    printf("%lu\n", divisible);
 
    return 0;
} 
