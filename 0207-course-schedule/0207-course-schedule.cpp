class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      // numcourses-> no of vertex 
      // prerequisites -> edges 
      // simple topo sort h ye to 
      // cycle exits to false 
      // else true 
      // cnt lekar compare karlenge 
      //  BFS se karenge 
      int V = numCourses ;
      vector<int>adjList[V];
      for(int i=0 ; i<prerequisites.size() ; i++){
        adjList[prerequisites[i][0]].push_back(prerequisites[i][1]);
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
  while(!q.empty()){
    int front = q.front();
    q.pop();
    cnt++;
    for(auto it:adjList[front]){
     indeg[it]--;
     if(indeg[it]==0)q.push(it);
    }
  }
     if(cnt!=V)return false;
     return true ;        
    }
};