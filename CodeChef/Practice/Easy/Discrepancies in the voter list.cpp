/*To be as accurate as possible, he entrusted the task to three different officials. Each of them was to independently record the list of voters and send it to the collector. 
In Siruseri, every one has a ID number and the list would only list the ID numbers of the voters and not their names. The officials were expected to arrange the ID numbers 
in ascending order in their lists.
On receiving the lists, the Collector realised that there were discrepancies - the three lists were not identical. He decided to go with the majority. That is, he decided 
to construct the final list including only those ID numbers that appeared in at least 2 out of the 3 lists. For example if the three lists were
23  30  42  57  90
21  23  35  57  90  92
21  23  30  57  90 
then the final list compiled by the collector would be:
21  23  30  57  90
The ID numbers 35, 42 and 92 which appeared in only one list each do not figure in the final list.
Your task is to help the collector by writing a program that produces the final list from the three given lists.
Input format
The first line of the input contains 3 integers N1, N2 and N3. N1 is the number of voters in the first list, N2 is the number of voters in the second list and N3 is 
the number of voters in the third list. The next N1 lines (lines 2,...,N1+1) contain one positive integer each and describe the first list in ascending order. 
The following N2 lines (lines N1+2,...,N1+N2+1) describe the second list in ascending order and the final N3 lines (lines N1+N2+2,...,N1+N2+N3+1) describe the third 
list in ascending order.
Output format
The first line of the output should contain a single integer M indicating the number voters in the final list. The next M lines (lines 2,...,M+1) should contain one 
positive integer each, describing the list of voters in the final list, in ascending order.
Test data
You may assume that 1 = N1,N2,N3 = 50000.*/

int a[50000+2],b[50000+2],c[50000+2],d[50000+2];
int main() {
	int N1,N2,N3;
	scanf("%d%d%d",&N1,&N2,&N3);
	int j=0,k=0;
	rep(i,0,N1)a[i]=inp();
	rep(i,0,N2)b[i]=inp();
	rep(i,0,N3)c[i]=inp();

	for(int i=0;i<N1;++i){
		for(;j<N2 and a[i]>=b[j];++j){
			if(a[i]==b[j] and a[i]!=0){
				d[k++]=a[i];
				a[i]=b[j]=0;
				j++;
				break;
			}
		}
	}
	j=0;
	for(int i=0;i<N2;++i){
		for(;j<N3 and b[i]>=c[j];++j){
			if(b[i]==c[j] and b[i]!=0){
				d[k++]=b[i];
				b[i]=c[j]=0;
				j++;
				break;
			}
		}
	}
	j=0;
	for(int i=0;i<N3;++i){
		for(;j<N1 and c[i]>=a[j];++j){
			if(c[i]==a[j] and c[i]!=0){
				d[k++]=c[i];
				c[i]=a[j]=0;
				j++;
				break;
			}
		}
	}
	printf("%d\n",k);
	sort(d,d+k);
	rep(i,0,k) printf("%d\n",d[i]);

	return 0;
}
