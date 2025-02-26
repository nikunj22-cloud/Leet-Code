
// class Solution {
// public:

//     bool checkBipartiteBFS(vector<int>adj[], int curr, vector<int>& color, int currColor) {
       
//         color[curr] = currColor; //color kardiya curr node ko
        
//         queue<int> que;
//         que.push(curr);
        
//         while(!que.empty()) {
//             int u = que.front();
//             que.pop();
//             // //ab ek ek krke q se element nikal kr unke phuchne wale nikalenege
//             for(int &v : adj[u]) {//check traverse krne wale ka color same toh ni h
//                 if(color[v] == color[u]) {
//                     return false;
//                 } else if(color[v] == -1) {
//                     color[v] = 1 - color[u];
//                     que.push(v);// //bad m kya pta iske adj node ko b toh traverse krna pdega na kyoki isme color hee nhi kiya gya thaa atoh ab kuya gya h toh mtlb iske adj node traverse krne baki 
//                 }
//             }
//         }
        
//         return true;
//     }


class Solution {
public:
    bool checkBipartite(std::vector<std::vector<int>>& graph, int curr, std::vector<int>& color, int currColor) {
        color[curr] = currColor;
        std::queue<int> q;
        q.push(curr);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int &v : graph[u]) {
                if (color[v] == color[u]) {
                    return false;  // If adjacent nodes have the same color, it's not bipartite
                } 
                else if (color[v] == -1) {
                    color[v] = 1 - color[u];  // Assign opposite color
                    q.push(v);  // Push `v`, not `u`
                }
            }
        }
        return true;
    }

    bool isBipartite(std::vector<std::vector<int>>& graph) {
        int V = graph.size();
        std::vector<int> color(V, -1);

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (!checkBipartite(graph, i, color, 1)) {
                    return false;
                }
            }
        }
        return true;
    }
};
