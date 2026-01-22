 #include <bits/stdc++.h>
using namespace std;
 
// Course Schedule - 1

 bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       vector<vector<int>> adj(numCourses);

    for (int i = 0; i < prerequisites.size(); i++) 
        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);

    vector<int> indegree(numCourses, 0);

      for (int i = 0; i < numCourses; i++) {
            for (auto it : adj[i]) {   
                indegree[it]++;
            }
        }

    queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
        }
    }
        int count = 0;

        while(!q.empty()) {

            int node = q.front();
            q.pop();
            count ++;

            for(auto it : adj[node]) {
                indegree[it] --;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }

        if(count == numCourses)
            return true;
        return false;
        
    }

    // Course Schedule - 2
    
     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);


        for (int i = 0; i < prerequisites.size(); i++) 
        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);

    vector<int> indegree(numCourses, 0);

      for (int i = 0; i < numCourses; i++) {
            for (auto it : adj[i]) {   
                indegree[it]++;
            }
        }

    queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;

        while (!q.empty()) {
        
            
            int node = q.front();
            q.pop();
            
            
            ans.push_back(node);
            
            
            for (auto it : adj[node]) {
                indegree[it]--;

                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        if (ans.size() != numCourses) return {};

        return ans;
        
    }