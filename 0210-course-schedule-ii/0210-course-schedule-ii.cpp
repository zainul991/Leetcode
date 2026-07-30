class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         int V = numCourses ;
      vector<int>adjList[V];
      for(int i=0 ; i<prerequisites.size() ; i++){
        adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
      }

      vector<int>indeg(V);
      for(int i = 0 ; i<V ; i++){
        for(auto it:adjList[i]){
        indeg[it]++;
        }
      } // indegree done 
    queue<int>q;
    for(int i = 0 ; i<V ; i++){
    if(indeg[i]==0)q.push(i);
    }
   int cnt=0; 
   vector<int>topo;
  while(!q.empty()){
    int front = q.front();
    q.pop();
    topo.push_back(front);
    for(auto it:adjList[front]){
     indeg[it]--;
     if(indeg[it]==0)q.push(it);
    }
  }
     if(topo.size()!=V)return {};
     return topo ;  
    }
};