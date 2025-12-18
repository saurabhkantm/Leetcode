class Solution {
public:
    void reverseString(vector<char>& s) {
        vector<char>st;
        for(int i=0;i<s.size();i++){
            st.push_back(s[i]);
        }
        int i=0;
        while(!st.empty()){
            s[i]=st.back();
            st.pop_back();
             i++;
        }
    }
};