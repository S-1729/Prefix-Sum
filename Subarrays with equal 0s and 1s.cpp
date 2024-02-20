class Solution{
  public:
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        long long ans=0,sum=0;
        unordered_map<long long,long long>mp;
        mp[0]=1;
        for(int i=0;i<n;i++){
            sum+= (arr[i]==0?-1:1);
            ans+=mp[sum];
            mp[sum]++;
        }
        return ans;
    }
};

/*
	Given an array containing 0s and 1s. Find the number of subarrays having equal number of 0s and 1s.
	
	Input:
	n = 7
	A[] = {1,0,0,1,0,1,1}
	Output: 8
	
	T.C : O(n)
	S.C : O(n)
*/
