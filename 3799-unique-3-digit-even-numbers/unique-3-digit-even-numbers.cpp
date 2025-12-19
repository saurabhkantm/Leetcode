class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        set<int> st;  // to store unique numbers

        for(int i = 0; i < n; i++) {
            if(digits[i] == 0) continue;  // hundreds place cannot be 0
            for(int j = 0; j < n; j++) {
                if(j == i) continue;  // digits must be different
                for(int k = 0; k < n; k++) {
                    if(k == i || k == j) continue;
                    if(digits[k] % 2 == 0) {  // last digit must be even
                        int num = digits[i]*100 + digits[j]*10 + digits[k];
                        st.insert(num);
                    }
                }
            }
        }

        return st.size();
    }
};
