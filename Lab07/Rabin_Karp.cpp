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

// vector<int>PI;

/*
	Author : Mann Desai
	Topic : String matching with Rabin Karp Algo.
*/


void init_code(){
	fast_io;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif // ONLINE_JUDGE
}  
int power(int a , int x){//a^x
	int res = 1;
	while(x > 0){
    	if(x%2 == 1){
        	res = res*a;
    	}
    	x /= 2;
    	a = a*a;
	}
	return res;
}

void Rabin_Karp_Algorithm(int p_num , int q , int m , int n , string pattern , string text){
	bool flag = false;
	int final_hit = p_num % q;
	vector<int>t(n-m , 0);
	for(int i=0 ; i<m ; i++){
    	p_num = (10 * p_num + (pattern[i] - '0')) % q;
    	t[i] = (10 * t[i] + (text[i] - '0')) % q;
	}
    
	int temp = t[0]*10 + t[1];//31
	cout<<p_num<<" "<<temp<<endl;
	//next two characters from text string
	for(int s=0 ; s<n-m ; s++){
    	if(p_num == temp){
        	for(int i=0 ; i<m ; i++){
            	if(pattern[i] == text[s+i]){
                	flag = true;
                	continue;
            	}
        	}
        	if(flag == true){
            	cout<<"Pattern Occurs with shift "<<s<<endl;
        	}
    	}
	}
}


int main()
{
	init_code();
	int q = 11;
	int p_num = 31;
	string pattern = to_string(p_num);
	int m = pattern.size();
	long long long_num = 3141592653589793;
	stringstream stream;
	stream<<long_num;
	string text = stream.str();
	int n = text.size();
	int h = power(10 , m-1) % q;
    
	Rabin_Karp_Algorithm(p_num , q , m , n , pattern , text);

    
	return 0;
}

