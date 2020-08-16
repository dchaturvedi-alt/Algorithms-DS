int t[4*N], lazy[4*N];
    void push(int v){
        int l = v*2, r = v*2+1;
        if(lazy[v]) {
            t[l] = t[r] = t[v];
            lazy[l] = lazy[r] = lazy[v];
            lazy[v] = 0;
        }
    }
    void update(int v, int tl, int tr, int l, int r, int val){
        if(l>r) return ;
        if(l==tl && tr==r){
            t[v] = val;
            lazy[v] = val;
            return ;
        }
        push(v);
        int mid = (tl+tr)/2;
        update(v*2, tl, mid, l, min(r, mid), val);
        update(v*2+1, mid+1, tr, max(l,mid+1), r, val);
    }
    int query(int v, int tl, int tr, int pos){
        if(tl == tr){
            return t[v];
        }
        push(v);
        int mid = (tl+tr)/2;
        if(mid>=pos) return query(v*2, tl, mid, pos);
        else return query(v*2+1, mid+1, tr, pos);
    }