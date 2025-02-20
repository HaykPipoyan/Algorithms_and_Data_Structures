class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(const auto& i : edges){
            int u = i[0];
            int v = i[1];
            graph[v].push_back(u);
        }
        vector<vector<int>> result(n);
        for(int i = 0; i < n; ++i){
            stack<int> st;
            vector<bool> visit(n, false);
            st.push(i);
            while(!st.empty()){
                int vertex = st.top();
                st.pop();
                for(int j: graph[vertex]){
                    if(visit[j] == false){
                        visit[j] = true;
                        st.push(j);
                        result[i].push_back(j);
                    }
                }
            }
            sort(result[i].begin(), result[i].end());
        }
        return result;
    }
};
