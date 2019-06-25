/*Cascading Style Sheets, or CSS is a style sheet language, most popularly known for styling web pages. Each object on a web page (like a picture, a paragraph, a table) can have various properties (like height, width, size, colour), and these properties can be set using CSS. Each of these objects has a unique identifier called id, using which CSS can identify the object and assign value to its property.

Due to hierarchical nature of the web page, often same property of an object gets assigned different values in different CSS statements. To decide what the final value will be, each statement has a priority assigned to it. The statement with the highest priority will be the one that sets the value of the property. If there are more than one statements with same priority, then the one which was executed last amongst those will set the value.

Given multiple CSS statements in the order they were executed, answer a few queries about the final values of certain objects

Input
First line contains two space-separated integers N and M, the number of CSS statements and the number of queries respectively.
Following N lines will each have 4 values id, attr, val, priority, which mean that a CSS statement tries to assign value val to the attribute named attr of the object id, and that the priority of this statement is equal to priority.
Each of the next M lines will contain two values id and attr, for which you have to print value of the attribute attr of object id. You can assume that there is a statement that assigns value to this attribute attr of object id.

Output
Print exactly M lines, ith line contains the answer to the ith query as described above.

Constraints
1 ≤ value, priority ≤ 106, for all subtasks.
For 20 points : 1 ≤ id, N, M, attr ≤ 103
For 30 points : 1 ≤ N, M ≤ 103, 1 ≤ id, attr ≤ 106
For 50 points : 1 ≤ N, M ≤ 105, 1 ≤ id, attr ≤ 106*/

template <typename T>
void inPos(T &x)
{
	register T c = inchar();
	while(((c<48) || (c>57)) && (c!='-')) c = inchar();
	x = 0;
	for(;c<48 || c>57; c = inchar());
	for(;c>47 && c<58; c = inchar())	x=(x<<3)+(x<<1)+(c-48);
}
 
int main()
{
    int t, q, n, i, j, a, b, c, d;
    inPos(t);
    inPos(q);
    map < pair<int, int> , pair<int, int> > magic;
    pair <int, int> one, two;
    while (t--)
    {
        inPos(one.fi);
        inPos(one.sec);
        inPos(two.fi);
        inPos(two.sec);
        if (magic[one].sec <= two.sec)
            magic[one] = two;
    }
    while (q--)
    {
        inPos(one.fi);
        inPos(one.sec);
        printf("%d", magic[one].fi);
        putchar_unlocked('\n');
    }
    return 0;
} 
////////////////////////////////////////////////////////////////////////


struct Data
    {
    	int id;
    	int att;
    	int val;
    	int priority;
    	int pos;
    }dt[100001];
    struct Data1
    {
    	int id;
    	int att;
    }ans[100001],node;
    bool comp(Data a,Data b)
    {
    	if(a.id<b.id)
    		return true;
    	else if(a.id==b.id)
    	{
    		if(a.att<b.att)
    			return true;
    		else if(a.att==b.att)
    		{
    			if(a.priority<b.priority)
    				return true;
    			else if(a.priority==b.priority)
    			{
    				if(a.pos<b.pos)
    					return true;
    				else
    					return false;
    			}
    			else
    				return false;
    		}
    		else
    			return false;
    	}	
    	else 
    		return false;
    }
    int value[100001];
    int binSearch(Data1 *A,int low,int high,Data1 node)
    {
    	if(low<=high)
    	{
    		int mid=(low+high)/2;
    		//cout<<low<<" "<<high<<endl;
    			if(A[mid].id>node.id)
    			{
    				return binSearch(A,low,mid-1,node);
    			}
    			else if(A[mid].id==node.id)
    			{
    				//cout<<A[mid].att<<" "<<node.att<<endl;
    				if(A[mid].att==node.att)
    					return mid;
    				else if(A[mid].att>node.att)
    					return binSearch(A,low,mid-1,node);
    				else
    					return binSearch(A,mid+1,high,node);
    			}
    			else
    			{
    				return binSearch(A,mid+1,high,node);
    			}	
    	}
    	return -1;
    }
    int main()
    {
    	int N,M;
    	N=read();
    	M=read();
    	for(int i=0;i<N;i++)
    	{
    		dt[i].id=read();
    		dt[i].att=read();
    		dt[i].val=read();
    		dt[i].priority=read();
    		dt[i].pos=i;
    	}
    	//sorting
    	sort(dt,dt+N,comp);
    	int i,k=0,prev_id=dt[0].id,prev_att=dt[0].att;
    	for(i=1;i<N;i++)
    	{
    		if(prev_id==dt[i].id && prev_att==dt[i].att)
    		{
    			
    		}
    		else
    		{
    			ans[k].id=dt[i-1].id;
    			ans[k].att=dt[i-1].att;
    			value[k]=dt[i-1].val;
    			prev_id=dt[i].id;
    			prev_att=dt[i].att;
    			k++;
    		}
    	}
    	ans[k].id=dt[i-1].id;
    	ans[k].att=dt[i-1].att;
    	value[k]=dt[i-1].val;
    	k++;
    	while(M--)
    	{
    		node.id=read();
    		node.att=read();
    		int index=binSearch(ans,0,k-1,node);
    		//cout<<index<<endl;
    		printf("%d\n",value[index]);
    	}
    //	getchar();
    	return 0;
    }   

///////////////////////////////////////////////////////////

typedef pair<int,int> pii;
map<pii, pii> mp;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M; 
    cin >> N >> M;

    int id, attr, val, prior;
    pii one, two;

    while(N--) {
        cin >> id >> attr >> val >> prior;
        one.first = id;
        one.second = attr;
        two.first = val;
        two.second = prior;

        if(mp[one].second <= two.second)
            mp[one] = two; 
    }

    while(M--) {
        cin >> id >> attr;
        one.first = id;
        one.second = attr;

        cout << mp[one].first << endl;
    }
}