#include<bits/stdc++.h>
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define read(x) int x; cin>>x
#define fd(a,b) for(int i=a ; i<b ; i++)
#define pr pair<int , int>
#define mapi unordered_map<int , int>
#define pq priority_queue<int , int>
#define que queue<int>
#define setter set<int>
#define ll long long
using namespace std;


/*
	Topic : KMP Pattern Matching
	Problem : Finding first index of pattern present in text 
	TC : O(N)+O(N)
*/
vector<int>ans;
void fillLPS(string str , vector<int>&lps){ // TC : O(N)
	int n = str.size();
	int len = 0;
	int i = 1;
	lps[0] = 0;
	while(i < n){
		if(str[i] == str[len]){
			len++;
			lps[i] = len;
			i++;
		}else{
			if(len != 0){
				len = lps[len-1];
			}else{
                lps[i] = 0;
				i++;
            }
		}
	}
}
    void strStr(string text, string pattern) {//O(N)
        int n = text.size();
        int m = pattern.size();
        vector<int>lps(m);
        fillLPS(pattern , lps);
        
        int i=0, j=0;
        while(i < n){
            if(text[i] == pattern[j]){
                i++;
                j++;
            }
            if(j==m){
            	// return i-j;
                ans.push_back(i-j);
                j = lps[j-1];
            }
            else if(i<n && text[i] != pattern[j]){
                if(j==0)
                    i++;
                else{
                    j = lps[j-1];
                }
            }
        }
    }

void init_code(){
	fast_io;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif // ONLINE_JUDGE
}  

int main(){
	init_code();
	string text ="abcabcdabcdabcabcdabcabcdabcabcd";
	string pattern = "abcd";
	// cout<<"Answer Index : "<<strStr(text , pattern)<<"\n";
	strStr(text , pattern);
	//Printing answer vector :
	cout<<"At Below Indexes Substring came in Original text String : "; 
	for(int i=0 ; i<ans.size() ; i++){
		cout<<ans[i]<<" ";
	}

	return 0;
}