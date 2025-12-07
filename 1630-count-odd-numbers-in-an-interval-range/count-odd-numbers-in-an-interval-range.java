class Solution {
    public int countOdds(int low, int high) {
        int count=0;
        count=(high-low)/2;
            if(high%2!=0||low%2!=0){
                count++;
            }
        return count;
    }
}
//tle testcase low=0 and high=1000000000