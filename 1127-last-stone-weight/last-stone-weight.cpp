class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        //max heap
        priority_queue<int>pq;
        for(int i=0;i<n;i++){
            pq.push(stones[i]);
        }
        while(pq.size()>1){
            int y=pq.top();
            pq.pop();
            int x=pq.top();
            pq.pop();
            if(y!=x){
             y-=x;
             pq.push(y);
            }
            if(pq.size()==0) return 0;
        }
            return pq.top();
        }
};