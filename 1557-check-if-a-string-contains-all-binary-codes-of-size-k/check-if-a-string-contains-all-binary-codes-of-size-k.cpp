class Solution {
public:
    // 2 ^ k substring it can have of size k
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        if(k>n) return false;
        set<string>st; // it contain all unique substring 
        for(int x = 0 ; x <= n-k ; x++ )
        {
            st.insert( s.substr( x,k ) );
        }
        if(st.size() == pow(2,k) ) return true;
        return false;
    }
};