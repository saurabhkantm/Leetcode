class Solution {
public:

    bool found = false;
    string ans ;
    int n ;
    void solve( int idx , set<string>&st  , string str)
    {
        if(found ) return;
        if( idx == n )
        {
            if(st.count(str) == 0 )
            {
                found = true;
                ans = str;
            }
            return ;
        }

        str+="0";   

        solve( idx+1 , st , str );
        str.pop_back();
        str+="1";
        solve( idx+1 , st , str );

    }

    string findDifferentBinaryString(vector<string>& nums) {
        
        n = nums[0].size();

        // i bit can be zero or one

        set<string>st(nums.begin() , nums.end());


        string str = "";

        solve( 0 , st , str );
        return ans;
    }
};