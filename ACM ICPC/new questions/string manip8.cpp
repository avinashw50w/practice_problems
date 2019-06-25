/*Suppose you have a long flowerbed in which some of the plots are planted and some are not. However, flowers cannot be planted 
in adjacent plots - they would compete for water and both would die. Given a flowerbed (represented as a string), 
return if a given number of new flowers can be planted in it without violating the no-adjacent-flowers rule 
Sample inputs 

Input: 1,0,0,0,0,0,1,0,0 

3 => true 
4 => false 
Input: 1,0,0,1,0,0,1,0,0 

1 => true 
2 => false 
input: 0 

1 => true 
2 => false */ 

// K is the number of flowers to plant
bool solve(string bed, int K) {

	int n = bed.size();

	if(n == 0 or n < K) return false;

	if(K == 0) return true;

	int cnt = 0;

	for(int i = 0; i < n; ++i) {

		if(bed[i] == '0') {
			if(i > 0 and bed[i-1] == '1') continue;
			
			if(i < n-1 and bed[i+1] == '1') continue;
		}

		bed[i] = 1;
		cnt++;

		if(cnt == K) return true;
	}

	return false;
}