class Solution {
public:
    static bool comp(int a,int b){
        int first = 0;
        int second = 0;
        int tempA = a;
        int tempB = b;
        while(a>0){
            first += (a & 1);
            a = a>>1;
        }
        while(b>0){
            second += (b & 1);
            b = b>>1;
        }
        // cout<<"a:"<<tempA<<endl;
        // cout<<"b:"<<tempB<<endl;
        // cout<<first<<endl;
        // cout<<second<<endl;
        if(first == second)
            return tempA < tempB;
        return first<second;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),comp);
        return arr;
    }
};