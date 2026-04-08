class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr(2*n);
        for(int i=0;i<arr.size();i++){
            arr[i] = nums[i%n];
        }
        stack<int>st;
        vector<int>ans(n);
        for(int i=2*n-1;i>=0;i--){
            while(!st.empty() && st.top()<=arr[i]){
                st.pop();
            }
            if(st.empty()){
                if(i<n){
                    ans[i] = -1;
                }
            }
            else{
                if(i<n){
                    ans[i] = st.top();
                }
            }
            st.push(arr[i]);
        }
        return ans;
    }
};

// 1,2,1,1,2,1