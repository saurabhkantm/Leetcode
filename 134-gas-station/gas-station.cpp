class Solution{
public:
	int canCompleteCircuit(vector<int>&gas,vector<int>&cost){
		int n=gas.size();
		int t=0;
		int tank=0;
		int ind=0;
		for(int i=0;i<n;i++){
			int diff=gas[i]-cost[i];
			t+=diff;
			tank+=diff;
			if(tank<0){
				ind=i+1;
				tank=0;
			}
		}
		if(t<0)return-1;
		return ind;
	}
};