class Solution {
public:
   bool bfs(int i , vector<int>&colored , vector<vector<int>>&graph){
   colored[i]=0;
   queue<int>q;
   q.push(i);
   while(!q.empty()){
    int node = q.front();
    q.pop();
    for(auto neighbour:graph[node]){
    if(colored[neighbour]!=-1  && colored[neighbour]==colored[node]){ // yahan pe pakka color hua h 
     return false ; 
    }
    else if(colored[neighbour]==-1){ // uncolored h 
        colored[neighbour]= 1-colored[node];
        q.push(neighbour);
    }
    }
   }
   return true;
   }
    bool isBipartite(vector<vector<int>>& graph) {
      // humko direct adjacency list di hui h 
      int n = graph.size();
      vector<int>colored(n,-1); // yahi visited array ka kaam karega 
      for(int i=0 ; i<n ; i++){
        if(colored[i]==-1){ // that means uncolored
          if(bfs(i,colored,graph)==false)return false; // ye connected components ke liye h , ek component ke liye sirf ek baar jayega 
        }
      }  
      return true;
    }
};