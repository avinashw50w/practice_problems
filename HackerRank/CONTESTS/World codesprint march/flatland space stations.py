'''Flatland is a country with nn cities, mm of which have space stations. Its cities (cc) are numbered from 00 to n−1n−1, where ithith city is referred to as cici.

Between each cici and ci+1ci+1 (where 0≤i<n0≤i<n), there exists a bidirectional road 1 km1 km long.

For example, if n=5n=5 and cities c0c0 and c4c4 have space stations, Flatland would look like this:

hreasy(5).png

For each city, determine its distance to the nearest space station and print the maximum of these distances.

Input Format

The first line consists of two space-separated integers, nn and mm . 
The second line contains mm space-separated integers c0,c1,...cm−1c0,c1,...cm−1 denoting the index of each city having a space station. These values are unordered and unique.

Constraints 
1≤n≤1051≤n≤105
1≤m≤n1≤m≤n

Note: There will be at least 11 city with a space station, and no city has more than one.

Output Format

Print an integer denoting the maximum distance that an astronaut in a Flatland city would need to travel to reach the nearest space station.

Solution : 

This can be solved in O(n). Assume arr[i]=1arr[i]=1 if ithith city has a solarpanel, 00 otherwise. Now calculate dp[i]dp[i] which denotes the distance to the nearest solarpanel on the left. if arr[i]=1arr[i]=1, than dp[i]=0dp[i]=0, otherwise dp[i]=dp[i−1]+1dp[i]=dp[i−1]+1.
Now calculate the distance to the nearest solarpanel of the right using the same technique. The minimum of these values is the distance to nearest solarpanel. Among all these values, print the maximum one.
Check problem-setter's code for this approach.'''

#python2.7
def calc(n,arr):
    dp=[0 for x in range(n)]
    for i in range(0,n):
        if arr[i]==1:
            dp[i]=0
        else:
            if i==0:
                dp[i]=1000000000
            else:
                dp[i]=dp[i-1]+1
    return dp

n,m=map(int,raw_input().split())
arr=map(int,raw_input().split())
flag=[0 for x in range(n)]
for val in arr:
    flag[val]=1


d1=calc(n,flag)
flag=flag[::-1]
d2=calc(n,flag)
d2=d2[::-1]
ans=0
for i in range(n):
    ans=max(ans,min(d1[i],d2[i]))

print ans