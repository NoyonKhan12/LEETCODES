class SmallestInfiniteSet {
public:
    map<int, int> mp;
    
    SmallestInfiniteSet() 
    {
        for(int i =1; i<=1000; i++) 
        {
            mp[i]++;
        }
    }
    
    int popSmallest() 
    {
        int x = mp.begin()->first;
        mp.erase(x);
        return x;
    }

    void addBack(int num) 
    {
        mp[num]++;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */