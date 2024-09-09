Template <typename T> struct Floyed{
    
    vector<vector<T>> dist;
    vector<vector<T>> parent;

    Floyed(int n): dist(n, vector<T>(n, LLONG_MAX)), parent(n, vector<T>(n, -1)) {}
    void AddE(T u, T v, T w, bool directed = false){
        dist[u][v] = w;
        parent[u][v] = u;
        if (!directed) dist[v][u] = w, parent[v][u] = v;
    }

    void get_dist(){
        for (int k = 0; k < sz(dist); k++){
            for (int i = 0; i < sz(dist); i++){
                for (int j = 0; j < sz(dist); j++){
                    if (dist[i][k] < LLONG_MAX && dist[k][j] < LLONG_MAX && dist[i][j] > dist[i][k] + dist[k][j]){
                        dist[i][j] = dist[i][k] + dist[k][j];
                        parent[i][j] = parent[k][j];
                    }
                }
            }
        }
    }
};
