class Solution{
    public:
    bool subArrayExists(int arr[], int n)
    {
        int sum=0;
        unordered_set<int>s;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==0 || s.find(sum)!=s.end())
                return true;
            s.insert(sum);
        }
        return false;
    }
};

/*
	Given an array of integers. Find if there is a subarray (of size at-least one) with 0 sum. 
	You just need to return true/false depending upon whether there is a subarray present with 0-sum or not.

	Input:
	n = 5
	arr = {4,2,-3,1,6}
	Output: Yes
	
	T.C : O(n)
	S.C : O(n)
*/	
