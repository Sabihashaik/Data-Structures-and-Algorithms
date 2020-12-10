class Solution {
public:
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> edgeList; 
        vector<int> indegree;
         for(int i=0;i<numCourses;i++){
            indegree.push_back(0); 
            edgeList[i]=vector<int>();
         }

        int total_edges = prerequisites.size();
        for(int i=0;i<total_edges;i++){
            edgeList[prerequisites[i][1]].push_back(prerequisites[i][0]); 
            indegree[prerequisites[i][0]]++;
        }       

        queue<int> q; //zeroIndegreeStore
        int edgesRemoved=0;

        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int frontElement = q.front();
            q.pop();
            
            for(auto ele:edgeList[frontElement]){
                edgesRemoved++;
                indegree[ele]--; 
             
          // May need another loop here 
             if(indegree[ele]==0){
                 q.push(ele);
             }

         }
     }

     if(total_edges == edgesRemoved){
      return true; 
  }

  return false; 

}



};

