#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
		char str[1500],str2[1005],l1,l2,*ptr1,*ptr2,flag1[10],flag2[10];
		while(t--){
			scanf("%s",flag1);
			scanf("%s",flag2);
			scanf("%s",str);
			int l=strlen(str);
			l1=strlen(flag1);
			l2=strlen(flag2);
			while(l){
			ptr1=strstr(str,flag1);
			ptr2=strstr(str,flag2);
			char *len=(ptr1-ptr2);
			if(ptr1!=0 && ptr2!=0){
				for(char *i=0;i<=len;i++)
				str[*i]='-1';
	}
			if(ptr2==0) break;
		}
		for(int i=0;i<l;i++){
			if(str[i]!=-1) printf("%c",str[i]);
		}
		printf("\n");
		}
		return 0;
}
