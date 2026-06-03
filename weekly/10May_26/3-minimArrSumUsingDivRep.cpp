class Solution {
public:
    long long minArraySum(vector<int>& nums) {

        long long sum = 0;
        vector<int> arr;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++) {

            int a = nums[i];

            if(arr.size() == 0) {
                arr.push_back(a);
                sum += a;
                continue;
            }

            bool found = false;
            int val = a;

            for(int j = 0; j < arr.size(); j++) {

                if(a % arr[j] == 0) {
                    val = arr[j];
                    found = true;
                    break;
                }
            }

            if(found == false)
                arr.push_back(a);

            sum += val;
        }

        return sum;
    }
};