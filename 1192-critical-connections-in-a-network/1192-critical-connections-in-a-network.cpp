class Solution {
public:
    void dfs(int node,int parent ,vector<int>&vis,vector<int>adjList[],vector<int>&tin,vector<int>&low,vector<vector<int>>&bridges,int &timer){
    vis[node]=1; // mark kardiya 
    tin[node]=low[node]=timer; // initialize kardiya hoon 
    timer++; // timer increase kardiya hoon for next 
    for(auto it:adjList[node]){ // adjacent node per jao 
    if(it==parent)continue; // parent ko ignore karo 
    if(vis[it]==0){  // agar visited nhi h to 
     dfs(it,node,vis,adjList,tin,low,bridges,timer); // dfs continue karo 
     low[node]=min(low[node],low[it]); // low ko update karo
     if(low[it]>tin[node]){ // v----u
       bridges.push_back({it,node}); // bridge ko store karte chalo! 
     }
    } 
    else { // visited h or parent bhi h nhi h tab 
        low[node]= min(low[node],low[it]);
    }
    }
}
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
       // n = number of nodes/vertex 
       vector<int>adjList[n]; // SC->0(V+2E) for adjacency list
       int E = connections.size();
       for(int i=0 ; i<E ; i++){
        int u = connections[i][0] ; 
        int v = connections[i][1] ;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
       } 
       // adjlist banadiya

       vector<int>visi(n,0);
       vector<int>tin(n,0);
       vector<int>low(n,0);
       //SC->0(3V)~0(V) | V is number of Nodes 
       vector<vector<int>> bridges ; // it will store the bridges
       int timer = 1;
       dfs(0,-1,visi,adjList,tin,low,bridges,timer); //TC->0(V+2E)
        return bridges ;
    }
};