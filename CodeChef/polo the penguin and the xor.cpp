#include<stdio.h>
 
int input[100010];
 
main() {
    int T;
    int N;
    int numOne;
    int i, j, p;
    long long int answer = 0;
 
 
    scanf("%d\n", &T);
 
    while(T--) {
        scanf("%d\n", &N);
        input[0] = 0;
 
        for( i = 1; i <= N; i++ ) {
            scanf("%d", &input[i]);
            input[i] = input[i]^input[i-1];
        }
 
        for( i = 0, p = 1; i < 32; i++, p <<= 1 ) {
            numOne = 0;
            for( j = 0; j <= N; j++ ) {
                if( input[j]&p ) numOne++;
            }
            answer += (long long int)(numOne)*(N+1-numOne)*p;
        }
        printf("%lld\n", answer);//answer << endl;
        answer = 0;
    }
    return 0;
}
