class NumArray {
public:
    vector<int> tree;
    vector<int> arr;
    int n;

    int buildTree(int node, int s, int e){
        if(s == e){
            tree[node] = arr[s];
            return tree[node]; 
        }

        int mid = s+(e-s)/2;
        int left = buildTree(2*node+1, s, mid);
        int right = buildTree(2*node+2, mid+1, e);
        

        return tree[node] = left + right;
    }

    NumArray(vector<int>& nums) {
        this->n = nums.size();
        arr = nums;
        tree.resize(4*n);
        buildTree(0, 0, n-1);
    }


    int query(int node, int l, int r, int s, int e){
        // case -1 (fully out of range)
        if(e < l || s > r)
            return 0;
        // case-2 (fully in range)
        if(s >= l && e <= r)
            return tree[node];

        int mid = s+(e-s)/2;
        int left = query(2*node+1, l, r, s, mid);
        int right = query(2*node+2, l, r, mid+1, e);

        return left + right;        
    }

    
    int sumRange(int left, int right) {
        return query(0, left, right, 0, n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */