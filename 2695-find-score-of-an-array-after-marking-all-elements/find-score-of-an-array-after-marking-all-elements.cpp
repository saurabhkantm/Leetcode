class Solution {
public:
    long long findScore(vector<int>& nums) {
         // Min-heap to store pairs of (value, index)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    int n = nums.size();
    long long score = 0;
    // marked array to keep track of marked and unmarked
    vector<bool>marked(n,0);

        for(int i=0;i<n;i++){
            minHeap.push({nums[i],i});  // push (value, index) pair in minHeap
        }

        while(!minHeap.empty()){
            auto[value, index] = minHeap.top();
            minHeap.pop();

            if(marked[index])  // already marked
                continue;

            // unmarked    
            score+=value;
            marked[index] = 1;
            if(index-1>=0)
                marked[index-1] = 1;
            if(index+1<n)
                marked[index+1] = 1;
        }
        return score;
    }
};