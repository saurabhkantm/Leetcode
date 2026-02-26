class Solution {
public:
    void add(string &s){
        reverse(s.begin(),s.end());
        int carry = 1;
        int i = 0;
        cout<<"orig:"<<s<<endl;
        while(carry!=0 && i<s.length()){
            if(s[i]=='1' && carry==1){
                s[i] = '0';
                carry = 1;
            }
            else if(s[i]=='0' && carry == 0){
                s[i] = '0';
                carry = 0;
            }
            else{
                s[i] = '1';
                carry = 0;
            }
            i++;
        }
        if(carry){
            s.push_back(carry+'0');
        }
        reverse(s.begin(),s.end());
        // cout<<s<<endl;
        return;
    }
    int numSteps(string s) {
        int count = 0;
        while(s.length()!=1){
            int n = s.length();
            // cout<<s<<endl;
            if(s[n-1]=='1'){
                // cout<<"Here"<<endl;
                add(s);
            }
            else{
                s.pop_back();
            }
            count++;
        }
        return count;
    }
};