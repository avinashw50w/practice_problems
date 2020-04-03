/*Consider a new order of english alphabets (a to z), that we are not aware of. What we have though, dictionary of words, ordered according to the new order.

Our task is to give each alphabet a rank, ordered list of words. The rank of an alphabet is the minimum integer R that can be given to it, such that:

if alphabet Ai has rank Ri and alphabet Aj has Rj, then

Rj > Ri if and only if Aj > Ai
Rj < Ri if and only if Aj < Ai
Points to note:

We only need to find the order of alphabets that are present in the words
There might be some cases where a strict ordering of words cannot be inferred completely, given the limited information. 
In that case, give the least possible Rank to every alphabet
It can be assumed that there will be no direct or indirect conflict in different inferences got from the input
Input:

First line consists of integer 'W', the number of words. 1 <= W <= 100
Second line onwards, there are 'W' lines, given ordered list of words. The words will be non-empty, and will be of length <= 20 characters. 
Also all the characters will be lowercase alphabets, a to z
Output:

The alphabets, in order of their Rank, for alphabets with the same rank, print them in the order as we know it today

Examples

1)

Input: 2 ba ab

Output: b a

Explanation: ab comes after ba implies that b < a

2)

Input: 3 abc aca ca

Ouput: ab c

Explanation: from the first 2 words, we know b < c, and from the last 2 words, we know a < c. We don't have an ordering 
between a and b, so we give both of them the same rank, and print them in the order as we know today: ab*/

/*First we look at characters at first index: all characters of same type would be occurring together in the list of characters at first index. 
Example, say we need to consider "aba","aca","bda", "bfa", "cda". So, looking at first characters we know that a>b and a>c and b>c.

Now, we separately consider different sets where first character was same. Recursively we can do this again and again. 
After analysis each index we will get some relations. In fact, we can look at the relations as a directed graph between 26 nodes. 
Edge between node i and node j denotes that i>j.

Now, we can apply topological sort on this directed graph to get the correct ordering.*/
int diff(string s1,string s2) {
    int mn = min((int)s1.size(),(int)s2.size());
    for(int i = 0;i < mn;++i) {
        if(s1[i]!=s2[i]) {
            return i;
        }
    }
    return -1;
}
 
int main() {
    int n;
    cin>>n;
    vector<string>w(n);
    for(int i = 0;i < n;++i) {
        cin>>w[i];
    }
    int dep[256][256];
    int cnt[256],cnt1[256];
    memset(cnt, -1, sizeof(cnt));
    memset(dep, 0, sizeof(dep));
    for(int i = 0;i < n;++i) {
        for(int j = 0;j < (int)w[i].size();++j) {
            cnt[w[i][j]] = 0;
        }
    }
    for(int i = 0;i < n;++i) {
        for(int j = i+1;j < n;++j) {
            int firstDiff = diff(w[i],w[j]);
            if(firstDiff == -1) {
                continue;
            }
            if(dep[w[j][firstDiff]][w[i][firstDiff]]) continue;
         
            dep[w[j][firstDiff]][w[i][firstDiff]] = 1;
            cnt[w[j][firstDiff]]++;
        }
    }
    while (true) {
        string s;
        for(int i = 0;i < 256;++i) cnt1[i] = cnt[i];
        for(int i = 0;i < 256;++i) {
            if(cnt[i] == 0) {
                s += (char)i;
                for(int j = 0;j < 256;++j) {
                    if(dep[j][i]) --cnt1[j];
                    dep[j][i] = 0;
                }
                cnt1[i]=-1;
            }
        }
        for(int i = 0;i < 256;++i) cnt[i] = cnt1[i];
       // cout<<s<<" --> "<<cnt['c']<<"\n";
        if(s == "") {
            break;
        }
        cout<<s<<"\n";
    }
    return 0;
}