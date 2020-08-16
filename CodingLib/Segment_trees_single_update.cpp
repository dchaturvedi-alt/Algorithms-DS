    struct data{
        int ans = 0, sum = 0, pre = 0, suf = 0; 
    };
    data node[4*N];
    data make(int val){
        data res;
        
        return res;
    }
    data combine(data left, data right){
        data res;
        
        return res; 
    }
    void build(int v = 1, int tl = 1, int tr = n){
        if(tl==tr){
            node[v] = make(a[tl]);
            return ; 
        }
        int tm = (tl+tr)/2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        node[v] = combine(node[v*2], node[v*2+1]);
    }
    void update(int v, int tl, int tr, int pos, int val){
        if(tl==tr) {
            node[v] = make(val);
            return ;
        }
        int tm = (tl+tr)/2;
        if(pos<=tm) update(v*2, tl, tm, pos, val);
        else update(v*2+1, tm+1, tr, pos, val);
        node[v] = combine(node[v*2], node[v*2+1]);
    }
    data query(int v, int tl, int tr, int l, int r){
        if(l > r) return make(-INF);
        if(l<=tl && tr<=r) return node[v];
        int tm = (tl+tr)/2;
        return combine(query(v*2, tl, tm, l, min(r,tm)), query(v*2+1, tm+1, tr, max(l,tm+1), r));
    }
    data temp;