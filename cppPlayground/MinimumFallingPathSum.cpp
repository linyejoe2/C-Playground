#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		return fun(nums, 0);
	}

	int fun(vector<int>& nums, int i)
	{
		// cout << i << endl;
		if (i == nums.size()) {
			return nums[i - 1];
		}
		if (i + 2 < nums.size()) {
			nums[i + 2] = max(nums[i + 1], nums[i] + nums[i + 2]);

		}
		if (i + 1 < nums.size()) {
			nums[i + 1] = max(nums[i], nums[i + 1]);
		}

		return fun(nums, i+1);

	}
};
