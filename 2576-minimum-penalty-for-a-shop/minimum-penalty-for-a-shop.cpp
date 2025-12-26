class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int idx = 0;
        int customLeft = 0;
        for(int i = 0; i < n ; i++){
            if(customers[i]=='Y'){
                customLeft++;
                if(customLeft > 0){
                    idx = i + 1;
                    customLeft = 0;
                }
            }else{
                customLeft--;
            }
        }return idx; 
    }
};