class Solution{
public:
	int countSubarrays(int n, vector<int> arr) {
	    unordered_map<string,int>mp;
	    mp["0&0"]=1;
	    int c0=0,c1=0,c2=0,ans=0;
	    for(int i=0;i<n;i++){
	        if(arr[i]==0)
	            c0++;
	        else if(arr[i]==1)
	            c1++;
	        else
	            c2++;
	        string key=to_string(c1-c0)+"&"+to_string(c2-c0);
	        ans+=mp[key];
	        mp[key]++;
	    }
	    return ans;
	}		
};

/*
	You are given an array containing ‘N’ integers. In the array, the elements are 0, 1 and 2. You have a simple task, find the count of non-empty subarrays containing an equal number of 0’s, 1’s and 2’s.
	
	Input: n= 6, arr= [1 0 2 1 0 2]
	Output: 5
	
	T.C : O(n)
	S.C : O(n)
*/


