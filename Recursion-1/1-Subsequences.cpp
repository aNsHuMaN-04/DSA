#include<bits/stdc++.h>
using namespace std;

// 1: Print/Store ALL Subsequences

void printSubsequence(int i, vector<int> nums, vector<int>& ds, vector<vector<int>>& ans)  {
	
    if (i == nums.size())
     {
		ans.push_back(ds);
		return;
	 }

	//Pick Condition for index i
	ds.push_back(nums[i]);
	printSubsequence(i + 1, nums, ds, ans);

	//Popping out while backtracking , i.e. Don't Pick Condition for index i
	ds.pop_back();
	printSubsequence(i + 1, nums, ds, ans);

}


// 2 : Print/Store ALL Subsequences with sum = k


void sumK_allSubsequence(int i, vector<int> nums, vector<int>& ds, vector<vector<int>>& ans, int sum, int k)  {
	
    if (i == nums.size())
     {
        if(sum == k)
		    ans.push_back(ds);
		return;
	 }

	
	ds.push_back(nums[i]);
    sum += nums[i];
	sumK_allSubsequence(i + 1, nums, ds, ans, sum, k); 

	
	ds.pop_back();
    sum -= nums[i];
	sumK_allSubsequence(i + 1, nums, ds, ans, sum, k);

} //Not passing sum as reference cuz we change it's value and then only pass it to the recursive func every time



// 3 : Print ONLY 1 Subsequence with sum = k

bool sumK_OneSubsequence(int i, vector<int> nums, vector<int>& ds, vector<vector<int>>& ans, int sum, int k)  {
	
    if (i == nums.size())
     {
        if(sum == k)
        {
		    ans.push_back(ds);
            return true;
        }  
        else
            return false;
	 }

	
	ds.push_back(nums[i]);
    sum += nums[i];
	if(sumK_OneSubsequence(i + 1, nums, ds, ans, sum, k) == true)
        return true; 

	ds.pop_back();
    sum -= nums[i];
	if(sumK_OneSubsequence(i + 1, nums, ds, ans, sum, k) == true)
        return true; 

    return false;

} // All these return true statments prevent further recursive calls as soon as one answer is found


// 4 : Count Subsequences with sum = k

int countSubsequence(int i, vector<int> nums, int sum, int k)
{
    if(i == nums.size())
    {
        if(sum == k)
            return 1;
        else
            return 0;
    }

    sum += nums[i];
    int left = countSubsequence(i+1, nums, sum, k);

    sum -= nums[i];
    int right = countSubsequence(i+1, nums, sum, k);

    return left + right;
}

