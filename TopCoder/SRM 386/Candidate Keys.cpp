/*A database table consists of a set of columns called attributes, and a set of rows called entries. 
A superkey is a set of attributes such that each entry's values for those attributes forms a unique ordered set. 
That is, for any superkey, each pair of entries differs in at least one of the attributes contained within the superkey.
 A candidate superkey is a superkey such that no proper subset of its attributes forms a superkey.



Return a int[] with exactly two elements. The first element should be the number of attributes in the smallest 
candidate superkey of the table, and the second element should be the number of attributes in the largest candidate 
superkey of the table. If there is no valid candidate superkey, return an empty int[] instead.



The input is described by a String[] table. Each String in table represents one entry, 
while characters contained in the String are attribute values for that entry.
 
Definition
    	
Class:	CandidateKeys
Method:	getKeys
Parameters:	String[]
Returns:	int[]
Method signature:	int[] getKeys(String[] table)
(be sure your method is public)
    
 
Notes
-	A proper subset of a superkey is a set of attributes that is formed by removing one or more attributes from the superkey.
 
Constraints
-	table will contain between 2 and 50 elements, inclusive.
-	Each element of table will contain between 1 and 10 characters, inclusive.
-	Each element of table will contain the same number of characters.
-	Each character in table will be an uppercase letter ('A'-'Z').
 
Examples
0)	
    	
{
"ABC",
"ABC",
"ABC"
}
Returns: { }
Since all entries are the same, there is no set of attributes that can differentiate between them. 
Therefore, this table has no candidate superkeys.
1)	
    	
{
"ABC",
"ABD",
"ABE"
}
Returns: {1, 1 }
There are four superkeys here:

{column 0, column 1, column 2}

{column 0, column 2}

{column 1, column 2}

{column 2}

Note that the fourth superkey is a subset of all the other superkeys, so it is the only candidate superkey.
*/
char valid[1<<10]; 

class CandidateKeys { 
public: 
  	vector <int> getKeys(vector <string> table) { 
	    int n = table[0].size(); 
	    int N = 1<<n; 
	    
	    memset(valid, 1, sizeof(valid)); 
	    
	    int minv = n+1, maxv = -1; 
		
		/* iterate through all possible keys */    
	    for (int i=1; i<N; ++i) { 
	      	if (!valid[i]) 
	        	continue; 
	      	
	      	vector<string> entries(table.size()); 
	      	
	      	for (int j=0; j<n; ++j) { 
	        	if ((1<<j) & i) 
	          		for (int k=0; k<(int)table.size(); ++k) 
	            		entries[k] += table[k][j]; 
	      	} 
	      	
	      	set<string> bla; 
	      	
	      	for (int j=0; j<(int)entries.size(); ++j) 
	        	bla.insert(entries[j]); 
	      
	      	if (bla.size() != entries.size()) 
	        	continue; 
	      	
	      	int len = entries.back().size(); 
	      	
	      	if (len > maxv) 
	        	maxv = len; 
	      
	      	if (len < minv) 
	        	minv = len; 
	      
	      	/*check if this subset i is a proper subset of any other set j*/
	      	/*if i is a proper subset of a set j, then j is not a condidate key*/
	      	/*Note that i can be a proper subset of j iff i < j */
	      	for (int j=i+1; j<N; ++j) 
	        	if ((i&j) == i) 
	          		valid[j] = 0; 
	    } 
	    
	    vector<int> res; 
	    
	    if (minv > maxv) 
	     	return res; 
	    
	    res.push_back(minv); 
	    res.push_back(maxv); 
	    return res; 
	} 
}; 
