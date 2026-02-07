class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> st;
        int cnt = 0;
        for(int i=0;i<s.size();i++){
            if(st.empty() || s[i] == 'b'){
                st.push(s[i]);
            }
            else if(s[i] == 'a' && st.top() == 'a'){
                st.push(s[i]);
            }
            else{
                st.pop();
                cnt++;
            }
        }

        return cnt;
    }
};