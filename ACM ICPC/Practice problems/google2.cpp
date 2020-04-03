/*Given a length n, return the number of strings of length n that can be made up of the letters 'a', 'b', and 'c', where there can only be a maximum of 1 'b's 
and can only have up to two consecutive 'c's 

Example: 
findStrings(3) returns 19 
since the possible combinations are: aaa,aab,aac,aba,abc,aca,acb,baa,bac,bca,caa,cab,cac,cba,cbc,acc,bcc,cca,ccb
and the invalid combinations are: 
abb,bab,bba,bbb,bbc,bcb,cbb,ccc*/

int findStrings(int n)
{
    int res = 0;

    // 0 'c's
    res += 1; // 0 'b's
    res += n; // 1 'b' in each position

    // 1 'c's
    res += 1 * n; // 0 'b's, 1 'c' in n pos
    res += (n - 1) * n; // 1 'b' in n-1 pos, 1 'c' in n pos

    // 2 'c's, (nk) pos
    res += 1 * ((n - 1) * n / 2); // 0 'b's, 2 'c's in (nk) pos
    res += (n - 2) * (n * (n - 1) /2); // 1 'b' in n-2 pos, 2 'c's in (nk) pos

    return res;
}