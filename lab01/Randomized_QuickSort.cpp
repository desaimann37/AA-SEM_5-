#include <bits/stdc++.h>
using namespace std;
/*
	Author : Mann Desai
	Topic : Sorting...

*/


int partition(vector<int>&arr , int p , int r){
    
	//Return Correct Index of Pivot Element	 
	int x = arr[r];
	int i = p-1;
	int j = 0;
	for(j=p ; j<r ; j++){
    	if(arr[j] <= x){
        	i++;
        	swap(arr[i] , arr[j]);
    	}
	}
	swap(arr[i+1] , arr[r]);
	i = i+1;
	return i;
}

int Random_partition(vector<int>&arr , int p , int r){
	srand(time(0));
	int n = arr.size();
	int random_index = (rand() % (r-p+1)) + p;
	swap(arr[random_index] , arr[r]);
	return (partition(arr , p , r));//This will Return Correct Index of Pivot Element.
    
}


void Randomized_QuickSort(vector<int>&arr , int p , int r){
    
	if(p < r){
    	int q = Random_partition(arr , p , r);
    	Randomized_QuickSort(arr , p , q-1);
    	Randomized_QuickSort(arr , q+1 , r);
	}
	cout<<"\n";
	for(auto &x : arr){
    	cout<<x<<" ";
	}
}




int main()
{
	vector<int>arr{1 , 2 , 3 , 4 , 5 , 6 , 7, 8 , 9};
	int n = arr.size();
	Randomized_QuickSort(arr , 0 , n-1);
    
	return 0;
}
