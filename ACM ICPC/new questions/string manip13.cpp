/*Given a string S. Your task is to remove all duplicates characters from the string S*/

int main()
{
    string s;
    int f[26] = {};
    cin>>s;
    int n = s.size();
    string str = "";
    for(int i = 0; i < n; ++i) {
    	if(!f[s[i]-'a']) f[s[i]-'a'] = 1, str += s[i];
    }
    cout << str;
    return 0;
}