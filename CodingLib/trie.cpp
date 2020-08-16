    typedef struct  data
    {
        data* bit[2];
        int cnt = 0;
    }trie;

    trie* head;
    
    void insert(int x){
        trie* node = head;
        for(int i = 30; i>=0; i--){
            int cur = 
            if(node->bit[cur] == NULL){
                node->bit[cur] = new trie();
            }
            node = node->bit[cur];
            node->cnt++;
        }
    }

    void remove(int x){
        trie* node = head;
        for(int i = 30; i>=0; i--){
            int cur = 
            node = node->bit[cur];
            node->cnt--;
        }
    }

    int query(int x){
        trie* node = head;
        int ans = 0;
        for(int i = 30; i>=0; i--){
            int cur = ;
            if(true){
                ans += 
                node = node->bit[cur^1];
            }
            else node = node->bit[cur];
        }
        return ans;
    }

    // Dont forget to initialize head in main
    head = new trie();