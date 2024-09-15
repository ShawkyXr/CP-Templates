template <typename T=int> struct Bellman{
    
    struct Edge{
        int from, to;
        T cost;
        Edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
    };

    Bellman(int n) : dist(n, oo), parent(n, -1) {}

    vector<Edge> edges;
    vector<T> dist;
    vector<int> parent;

    void addEdge(int from, int to, T cost){
        edges.push_back(Edge(from, to, cost));
    }

    bool bellmanFord(int src){
        dist[src] = 0;
        for(int i = 0; i < sz(edges) - 1; i++){
            for(auto &e : edges){
                if(dist[e.from] + e.cost < dist[e.to]){
                    dist[e.to] = dist[e.from] + e.cost;
                    parent[e.to] = e.from;
                }
            }
        }

        for(auto &e : edges){
            if(dist[e.from] + e.cost < dist[e.to]){
                return false;
            }
        }

        return true;
    }

};