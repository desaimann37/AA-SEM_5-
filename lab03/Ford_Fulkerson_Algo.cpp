/*
	Author : Mann Desai
	Topic : Ford Fulkerson Algo.
*/

#include<bits/stdc++.h>
using namespace std;

void printAugmentedPaths(vector<vector<int>>&augmentedPaths){
    cout<<"Printing All Augmented Paths..."<<endl;
    for(auto &x : augmentedPaths){
        for(auto &y : x){
            cout<<y<<"->";
        }
        cout<<endl;
    }
}
bool BFS(vector<vector<int>>&residualCapacity , map<int , int>&parent , int source , int sink){
    // cout<<"Inside BFS...";
    int n = residualCapacity.size();
    vector<bool>visited(n , false);
    queue<int>que;
    que.push(source);
    visited[source] = true;
    bool foundAugmentedPath = false;
    
    while(!que.empty()){
        int u = que.front();
        // cout<<u<<" ";
        que.pop();
        // cout<<u<<" ";
        for(int v=0 ; v<residualCapacity.size() ; v++){
            
            if(!visited[v] && residualCapacity[u][v] > 0){
                parent.insert({v , u});
                visited[v] = true;
                // cout<<"Hi ";
                que.push(v);
                if(v == sink){
                    foundAugmentedPath = true;
                    break;
                }
            }
        }
    }
    return foundAugmentedPath;
}


int maxFlow(vector<vector<int>>&capacity , int source , int sink){
    int n = capacity.size();
    int m = capacity[0].size();
    vector<vector<int>>residualCapacity(n , vector<int>(m , 0));
    
    for(int i=0 ; i<residualCapacity.size() ; i++){
        for(int j=0 ; j<residualCapacity[0].size() ; j++){
            residualCapacity[i][j] = capacity[i][j];
        }
    }
    
    map<int , int>parent;
    //For Storing All Augmented Paths...
    vector<vector<int>>augmentedPaths;
    int maxFlow = 0;
    
    while(true){
        parent.clear();

        if(!BFS(residualCapacity , parent , source , sink)){
            break;
        }
        vector<int>augmentedPath;
        int flow = INT_MAX;
        //Find Min. Residual Capacity From Augmented Path
        //Add Vertices to augmented Path
        int v = sink;
        while(v != source){
            augmentedPath.push_back(v);
            int u = parent[v];
            // cout<<u<<" ";
            if(flow > residualCapacity[u][v]){
                flow = residualCapacity[u][v];
            }
            v = u;
        }
        augmentedPath.push_back(source);
        reverse(augmentedPath.begin() , augmentedPath.end());
        augmentedPaths.push_back(augmentedPath);
        
        maxFlow += flow;
        
        //(Increase / Decrease) From u->v and v->u in Augmented Path.
        v = sink;
        while(v != source){
            int u = parent[v];
            residualCapacity[u][v] -= flow;
            residualCapacity[v][u] += flow;
            v = u;
        }
    }
    printAugmentedPaths(augmentedPaths);
    
    return maxFlow;
}


int main() {
    
    vector<vector<int>>capacity{{0 , 16 , 13 , 0 , 0 , 0},
        {0 , 0 , 10 , 12 , 0 , 0 },
        {0 , 4 , 0 , 0 , 14 , 0 },
        {0 , 0 , 9 , 0 , 0 , 20 },
        {0 , 0 , 0 , 7 , 0 , 4 },
        {0 , 0 , 0 , 0 , 0 , 0 }
};
    cout<<"Maximun Flow : "<<maxFlow(capacity , 0 , 5);
    

return 0;
}



