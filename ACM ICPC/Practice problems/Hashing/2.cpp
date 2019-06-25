/*Monk has to visit a land where strange creatures, known as Pokemons, roam around in the wild. Each Pokemon in the land will attack any visitor. 
They can only be pacified by feeding them their favorite food.

The Pokemon of type X eats one food item of type X.
Monk knows that he will encounter N ponds on the way. At each pond, he will find a food item and then encounter a Pokemon. The i'th pond has the food item 
of type Ai and the Pokemon of type Bi.

The monk can feed the item at the i'th pond to the Pokemon at the pond if the type matches. Monk may have to carry some food items with him before leaving 
so as to feed all the Pokemons. Help him find the number of items he must carry, to be to able to pass through the land safely.

Input:
The first line contains T, denoting the number of test cases. Then, T test cases follow.
The first line of each test case contains an integer N. Then, N lines follow.
Each line consists of 2 space-separated integers Ai and Bi.

Output: For each test case, print the answer in a new line.

Constraints:
1 ≤ T ≤ 10
1 ≤ N ≤ 105
1 ≤ Ai, Bi ≤ 106  */
int f[(int)1e6 +2];
int main() {
	caset{
		int n; si(n);
		int a,b, cnt = 0;
		memset(f,0,sizeof f);
		while(n--){
			si(a); si(b);
			if(a == b) { f[b] = 1; continue; }
			if(f[b] == 0) cnt++;
			f[b] = 1;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
