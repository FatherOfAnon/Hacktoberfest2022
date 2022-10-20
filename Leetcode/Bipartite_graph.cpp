class Solution {
public:
    
    bool bfs(vector<vector<int>>& graph,int root,vector<int> &color){
        queue<int> q;
        q.push(root);
        color[root] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            int parentColor = color[node];
            for(auto a:graph[node]){
                if(color[a]==-1){
                    color[a] = !parentColor;
                    q.push(a);
                }else{
                    if(color[a]==parentColor) return false;
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!bfs(graph,i,color)) return false;
            }
        }
        return true;
    }
};
