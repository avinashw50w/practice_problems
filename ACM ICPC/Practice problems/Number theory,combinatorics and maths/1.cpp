/*There is a magical shop owned by The Monk, which consists of magical potions. On the first day there are A number of potions. Let, potions[I] denote the number of potions present in the shop on the Ith day.

potions[I] = potions[I-1] * potions[I-1]
You, Monk's favorite student love to play around with various types of potions. So, you visit the shop regularly and buy all the potions and just keep them with yourself. However, the Monk allows you to go to the shop only on specific days.

You have to find the number of potions that you will have at the very end. Since, the answer can be very large, output it modulo B.

Input Format:
The first line will contain A and B, the number of potions on the first day and the value with which modulo is to be taken. The second line consists of a string consisting of "0" and "1". If the Ith character from left is 1 then you can go to shop on Ith day to buy potions.

Output Format: 
Output on a single line, the number of potions that you will have at the end. Since, the answer can be very large, output it modulo B.

Constraints:
1 <= A, B <= 109
1 <= |Length of the string| <= 105 
The string will only consist of 1 and 0.*/

int main() {
    ll a,b;
    char s[MAXN+2];
    sl(a); sl(b); ss(s);
    ll sum = 0, n = strlen(s);
    rep(i,0,n){
        if(s[i] == '1'){
            sum += a;
            sum %= b;
        }
        a = (a*a)%b;
    }
    printf("%lld\n", sum%b);
    return 0;
}
