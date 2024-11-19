template <typename T> struct Segment_tree{

private:

    struct Node{

        T val;

        Node(T value = 0) : val(value) {}

        Node operator = (const T &a){
            val = a;
            return *this;
        }

    };

    int size;
    vector<Node> tree;
    Node ret;

    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }
    int mid(int l, int r) { return l + (r-l) / 2; }

    void build(vector<T> &v, int x, int lx, int rx){

        if (lx == rx){
            if (lx < sz(v)) tree[x] = v[lx];
            return;
        }

        int m = mid(lx, rx);

        build (v, left(x), lx, m);
        build (v, right(x), m + 1, rx);

        tree[x] = merge(tree[left(x)], tree[right(x)]);
    }

    void update(int i, T val, int x, int lx, int rx){

        if (lx == rx){
            tree[x] = val;
            return;
        }

        int m = mid(lx, rx);

        if (i <= m) update(i, val, left(x), lx, m);
        else update(i, val, right(x), m + 1, rx);

        tree[x] = merge(tree[left(x)], tree[right(x)]);
    }

    Node query(int l, int r, int x, int lx, int rx){

        if (l > rx || r < lx) return ret;
        if (l <= lx && rx <= r) return tree[x];

        int m = mid(lx, rx);

        return merge(query(l, r, left(x), lx, m), query(l, r, right(x), m + 1, rx));
    }

public:

    Segment_tree(int n, vector<T> &v, T Default = 0){ 

        ret = Default;
        size = 1;
        while (size < n) size *= 2;

        tree.assign(2 * size, ret);

        build(v, 0, 0, size - 1);
    }

    void update(int i, T val){
        update(i, val, 0, 0, size - 1);
    }

    T query(int l, int r, int base = 1){
        if (base) return query(l-1 , r-1, 0, 0, size - 1).val;
        return query(l, r, 0, 0, size - 1).val;
    }

    Node merge(Node a, Node b){
        return a.val + b.val;
    }

    T get(int i){
        return query(i, i);
    }

    void print(){
        for (int level = 1 ; level <= size ; level *= 2){
            for (int i = 0 ; i < level ; i++){
                cout << tree[level + i -1].val << " ";
            }
            cout << nl;
        }
    }
    
};