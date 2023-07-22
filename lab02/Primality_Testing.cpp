#include <bits/stdc++.h>

using namespace std;
/*
    Author : Mann Desai
    Topic : Lab02_Randomized_Primality_Testing
*/

int k = 100;
long long int power(int x, unsigned n , int mod)
{
    long long int pow = 1;
 
    for (int i = 0; i < n; i++) {
        pow = (pow * x) % mod;
    }
 
    return pow;
}
int gcd(int a , int b){
    
    while(b > 0){
        int temp = a%b;
        a = b;
        b = temp;
    }
    return a;
}

bool isPrime(long long int n){
    
    if(n <= 1 || n == 4){
        return false;
    }
    if(n <= 3){
        return true;
    }
    for(int i=1 ; i<=k ; i++){
        
        srand(time(0));
        //Random Number 
        int random = 2 + (rand()%(n-3));
        if(gcd(random , n) != 1){
            return false;
        }
        if(power(random , n-1 , n) != 1){
            return false;
        }
    return true;
    }
}

int main()
{
    long long int n = 987646789;
    bool ans = isPrime(n);
    if(ans){
        cout<<"Given Number is Prime "<<endl;
    }else{
        cout<<"Given Number is Not Prime "<<endl;
    }
    return 0;
}
