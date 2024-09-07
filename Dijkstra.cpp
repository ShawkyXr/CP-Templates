template <typename T=int> struct Dijkstra{

  struct edge{
    T u, v, w;
    edge(T u, T v, T w): u(u), v(v), w(w) {}
    bool operator < (const edge& e) const{
      return w > e.w;
    }
  };

  vector<vector<edge>> adj;
  vector<T> dist;
  vector<T> parent;

  Dijkstra(int n): adj(n), dist(n, oo), parent(n, -1) {}

  void AddE(T u, T v, T w, bool directed = false){
    adj[u].emplace_back(edge(u, v, w));
    if (!directed) adj[v].emplace_back(edge(v, u, w));
  }

  void FindDist(T src,T target = -1){
    dist.assign(sz(adj), oo);
    parent.assign(sz(adj), -1);
    // create pq with edges sorted by lowest weight
    priority_queue<edge> pq;
    pq.emplace(edge(-1, src, 0));
    // initialize the distance of the source node to 0
    dist[src] = 0;
    parent[src] = -1;

    while (!pq.empty()){
        edge e = pq.top();
        pq.pop();
        if (e.v == target) return;
        if (dist[e.v] < e.w) continue;
        // relax all the edges that are going out of the current node
        for (auto& node : adj[e.v]){
            if (dist[node.v] > e.w + node.w){
              dist[node.v] = e.w + node.w;  // relaxtion
              parent[node.v] = e.v;
              pq.emplace(edge(node.u, node.v, dist[node.v]));
            }
        }
    }

  }

};
