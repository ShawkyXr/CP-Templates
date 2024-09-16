template <typename T=int> struct Bellman{

    struct Edge{
        int from, to;
        T cost;
        Edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
    };


    int n;
    bool inv = false;
    vector<Edge> edges;
    vector<T> dist;
    vector<int> parent;

    Bellman(int n,bool inv) : n(n), inv(inv) ,dist(n, oo), parent(n, -1) {}

    void addEdge(int from, int to, T cost, bool inv = false){
        if (inv) edges.emplace_back(from, to, -1LL*cost);
        else edges.emplace_back(from, to, cost);
    }

    ll bellmanFord(int src){
        dist[src] = 0;
        for(int i = 0; i < sz(edges) - 1; i++){
            for(auto &e : edges){
                if(dist[e.from] + e.cost < dist[e.to]){
                    dist[e.to] = dist[e.from] + e.cost;
                    parent[e.to] = e.from;
                }
            }
        }
        if (inv) return dist[n]*-1LL;
        return dist[n];
    }

    bool NegCycle(){
         for (int i=0 ; i< n-1 ; i++){
            for(auto &e : edges){
                if(dist[e.from] + e.cost < dist[e.to]){
                    return false; // Negative cycle 
                }
            }
        }
        return true;
    }

};