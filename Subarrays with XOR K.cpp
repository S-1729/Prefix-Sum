class Solution{
public:
	int subarraysXor(vector<int> &arr, int k)
	{
	    int sum=0,ans=0;
	    unordered_map<int,int>mp;
	    mp[0]=1;
	    for(auto i:arr){
	        sum^=i;
	        ans+=mp[sum^k];
	        mp[sum]++;
	    }
	    return ans;
	}
};

/*
	Given an array of integers ‘ARR’ and an integer ‘X’, you are supposed to find the number of subarrays of 'ARR' which have bitwise XOR of the elements equal to 'X'.
	Note:
	An array ‘B’ is a subarray of an array ‘A’ if ‘B’ that can be obtained by deletion of, several elements(possibly none) from the start of ‘A’ and several elements(possibly none) from the end of ‘A’. 

	Input:
	4 2
	1 2 3 2
	Output: 3
	Explanation: Subarrays have bitwise xor equal to ‘2’ are: [1, 2, 3, 2], [2], [2].
	
	T.C : O(n)
	S.C : O(n)
*/
