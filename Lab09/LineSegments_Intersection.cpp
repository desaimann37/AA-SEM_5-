#include <bits/stdc++.h>

using namespace std;

bool onSegment(pair<int , int>&p1 , pair<int , int>&p2 , pair<int , int>&p3){
    
    if((min(p1.first , p2.first) <= p3.first <= max(p1.first , p2.first)) && min(p1.second , p2.second) <= p3.second <= max(p1.second , p2.second)){
        return true;
    }
    return false;
}

int CrossProduct(pair<int , int>&a , pair<int , int>&b){
    //This function will Return cross product weather it's <0 , =0 OR >0
    int tmp = (b.second * a.first) - (b.first * a.second); 
    if(tmp > 0){
        return 1;
    }else if(tmp < 0){
        return -1;
    }
    return 0;
}

int Direction(pair<int , int>&a , pair<int , int>&b , pair<int , int>&c){
    
    //ac*ab-->Cross Product of these two 
    pair<int , int>temp1 = make_pair(c.first-a.first , c.second-a.second);
    pair<int , int>temp2 = make_pair(b.first-a.first , b.second-a.second);
    //Cross Product of these Two pair : 
    int ans = CrossProduct(temp1 , temp2);
    if(ans > 0){
        return 1;
    }else if(ans < 0){
        return -1;
    }
    return 0;
}

bool isSegmentIntersect(pair<int , int>&p1 , pair<int , int>&p2 , pair<int , int>&p3 , pair<int , int>&p4){
    
    int d1 = Direction(p3 , p4 , p1);
    int d2 = Direction(p3 , p4 , p2);
    int d3 = Direction(p1 , p2 , p3);
    int d4 = Direction(p1 , p2 , p4);
    
    if((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0) && (d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0)){
        return true;
    }else if(d1 == 0 && onSegment(p3 , p4 , p1)){
        return true;
    }else if(d2 == 0 && onSegment(p3 , p4 , p2)){
        return true;
    }else if(d3 == 0 && onSegment(p1 , p2 , p3)){
        return true;
    }else if(d4 == 0 && onSegment(p1 , p2 , p4)){
        return true;
    }else{
        return false;
    }
return true;        
}


int main()
{
    pair<int , int>p1 = make_pair(2 , 2);
    pair<int , int>p2 = make_pair(8 , 3);
    pair<int , int>p3 = make_pair(1 , 4);
    pair<int , int>p4 = make_pair(6 , 5);
    bool ans = isSegmentIntersect(p1 , p2 , p3 , p4);
    cout<<"These two line segments are : "<<ans;
    return 0;
}
