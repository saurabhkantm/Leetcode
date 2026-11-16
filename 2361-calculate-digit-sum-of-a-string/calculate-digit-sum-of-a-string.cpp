class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size() > k){
            string temp;
            for(int i = 0; i < s.size(); i+=k){
                int sum = 0;
                string temp2 = s.substr(i, k); //
                int j = 0;
                while(j < temp2.size()){
                    sum += temp2[j] - '0';
                    j++;
                }
                temp += to_string(sum);
            }
            s = temp;
        }
        return s;
    }
};