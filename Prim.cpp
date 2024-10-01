template <typename T> struct Prim{

    struct Edge{

        int from, to;
        T cost;

        Edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}

        bool operator < (const Edge &e) const{
            return cost > e.cost;
        }

    };

    int n;
    vector<vector<Edge>> adj;
    vector<bool> vis;
    vector<T> dist;
    vector<int> parent;

    Prim(int n) : n(n), adj(n+2), vis(n+2), dist(n+2, oo), parent(n+2, -1) {}

    void addEdge(int from, int to, T cost){
        adj[from].emplace_back(from, to, cost);
        adj[to].emplace_back(to, from, cost);
    }

    T prim(int src){

        priority_queue<Edge> pq;
        pq.push(Edge(-1, src, 0));
        T ans = 0;

        while(!pq.empty()){
            Edge e = pq.top();
            pq.pop();

            if (vis[e.to]) continue;
            vis[e.to] = true;
            ans += e.cost;

            for(auto &u : adj[e.to]){
                if (u.cost < dist[u.to]){
                    dist[u.to] = u.cost;
                    parent[u.to] = e.to;
                    pq.push(u);
                }
            }
        }

        return ans;
    }

    vector<int> getMST(){
        vector<int> ans;
        for (int i=1 ; i<=n ; i++){
            if (parent[i] != -1)
                ans.push_back(i);
        }
        return ans;
    }

};