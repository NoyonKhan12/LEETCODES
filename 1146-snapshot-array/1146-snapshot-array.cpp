class SnapshotArray {
public:
    int id;
    vector<vector<pair<int, int>>> v;

    SnapshotArray(int n) 
    {
        id = 0;
        v.resize(n);

         for(int i=0; i<n; i++ )
         {
             v[i].push_back({0, 0});
         }
    }
    
    void set(int index, int val) 
    {
        v[index].push_back({id, val});
    }
    
    int snap()
    {
        return id++;
    }
    
    int get(int index, int id)
    {
        auto it = upper_bound(v[index].begin(), v[index].end(), make_pair(id, 1000000001));
        it--;
        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */