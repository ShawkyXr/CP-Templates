template <typename T> struct DSU{

    public:

        int n;
        vector <T> parent;
        vector <T> size;


        DSU(int n) : n(n) , parent(n+2), size(n+2) {

            for (int i=1 ; i<=n ; i++){
                parent[i] = i;
                size[i] = 1;
            }

        }
        

        T get_parent(T u){
            return parent[u] = (parent[u] == u ? u : get_parent(parent[u])); // path compression
        }


        bool connected(T u, T v){
            return get_parent(u) == get_parent(v);
        }


        void unoin(T u ,T v){
            
            if (connected(u,v)) return;

            int Pu = get_parent(u), Pv = get_parent(v);
            
            if (size[Pu] < size[Pv])
                swap(Pu,Pv);

            size[Pu]+=size[Pv];
            parent[Pv] = Pu;
           
        }

};