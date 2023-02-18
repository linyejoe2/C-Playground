#ifndef SOLUTION_H
#define SOLUTION_H

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    Solution();

    int longestCommonSubsequence(string text1, string text2);

    /**
     * @brief leet 1971.
     * @date 12/19/2022
     * @author linyejoe2
     * @see https://leetcode.com/problems/find-if-path-exists-in-graph/
     */
    bool validPath(int n, vector<vector<int>> &edges, int source,
                   int destination) {
        queue<vector<int>> path;

        for (int i = 0; i < edges.size(); i++) {
            for (int j = 0; j < edges[i].size(); j++) {
                if (edges[i][0] == source) path.push(edges[i]);
                if (edges[i][1] == source) {
                    reverse(edges[i].begin(), edges[i].end());
                    path.push(edges[i]);
                    // path.f
                }
            }
        }
    }

    /**
     * @brief leet 841.
     * @date 12/20/2022
     * @author linyejoe2
     * @see https://leetcode.com/problems/keys-and-rooms/
     */
    bool canVisitAllRooms(vector<vector<int>> &rooms) {
        // create a map to store key that we pickup
        map<int, int> keyinBag;
        keyinBag[0] = 0;

        while (!keyinBag.empty()) {
            auto key = keyinBag[0];

            if (rooms[key].size() != 0) {
                for (int i = 0; i < rooms[key].size(); i++) {
                    if (!keyinBag[rooms[key][i]])
                        keyinBag[rooms[key][i]] = rooms[key][i];
                }
            }
            keyinBag[0] = -1;
        }
        return rooms.size() == keyinBag.size();
    }

    bool containsDuplicate(vector<int> &nums) {
        map<int, bool> numMap;
        numMap[nums[0]] = true;
        for (int i = 1; i < nums.size(); i++) {
            if (numMap[nums[i]]) return true;
            numMap[nums[i]] = true;
        }
        return false;
    }

    /**
     * @brief leetcode 53.
     * @date 01/09/2022
     * @author linyejoe2
     * @see https://leetcode.com/problems/maximum-subarray/
     */
    int maxSubArray(vector<int> &nums, int currVal = 0, int maxVal = 0,
                    int i = 0) {
        // nums     [-2, 1,-3, 4,-1, 2, 1,-5, 4]
        // currVal  [-2, 1,-2, 4, 3, 5, 6, 1, 5]
        // maxVal   [-2, 1, 1, 4, 4, 5, 6, 6, 6]
        //// cout << maxVal << endl;
        //// cout << "i: " << i << endl;

        if (i == 0) return maxSubArray(nums, nums[i], nums[i], i + 1);  // init.

        if (i == nums.size()) return maxVal;  // end case.

        if (currVal < 1)
            return maxSubArray(nums, nums[i], max(maxVal, nums[i]), i + 1);
        return maxSubArray(nums, currVal + nums[i],
                           max(maxVal, currVal + nums[i]), i + 1);
        // return maxSubArray(nums, max(maxVal, maxVal + nums[i]), i + 1);
    }

    /**
     * @brief leetcode 1470.
     * @date 02/06/2023
     * @author linyejoe2
     * @see https://leetcode.com/problems/shuffle-the-array/
     */
    vector<int> shuffle(vector<int> &nums, int n) {
        vector<int> ans;
        for (int i = 0; i < nums.size() - n; i++) {
            ans.push_back(nums[i]);
            ans.push_back(nums[i + n]);
        }
        return ans;
    }

    /**
     * @brief leetcode 104.
     * @date 02/16/2023
     * @author linyejoe2
     * @see https://leetcode.com/problems/maximum-depth-of-binary-tree/
     * @return int
     */
    int maxDepth(TreeNode *root) { return dfs(root, 0); }

    int dfs(TreeNode *root, int depth = 0) {
        if (!root) return depth;
        return max(dfs(root->left, depth + 1), dfs(root->right, depth + 1));
    }

    /**
     * @brief leetcode 783.
     * @date 02/17/2023
     * @author linyejoe2
     * @see https://leetcode.com/problems/minimum-distance-between-bst-nodes/
     *
     * @param root
     * @return int
     */
    int minDiffInBST(TreeNode *root) {
        vector<int> nums;
        int minVal = INT_MAX;

        df(root, &nums);

        for (int i = 0; i < nums.size() - 1; i++) {
            minVal = min(minVal, abs(nums[i] - nums[i + 1]));
        }
        return minVal;
    }

    void df(TreeNode *root, vector<int> *nums) {
        if (!root) return;

        df(root->left, nums);
        nums->push_back(root->val);
        df(root->right, nums);
    }

    /**
     * @brief leetcode 226.
     * @date 02/18/2023
     * @author linyejoe2
     * @see https://leetcode.com/problems/invert-binary-tree/description/
     *
     * @param root
     * @return TreeNode*
     */
    TreeNode *invertTree(TreeNode *root) {
        _invertTree(root);
        return root;
    }

    void _invertTree(TreeNode *root) {
        if (!root) {
            return;
        }
        _invertTree(root->left);
        _invertTree(root->right);

        TreeNode temp = *root->right;
        root->right = root->left;
        root->left = &temp;
    }

    /**
     * @brief leetcode 226.
     * @date 02/18/2023
     * @author linyejoe2
     * @see https://leetcode.com/problems/invert-binary-tree/description/
     * @version 2
     * 
     * @param root
     * @return TreeNode*
     */
    TreeNode *invertTree(TreeNode *root) {
        if (!root) return root;
        TreeNode *left = invertTree(root->left);
        TreeNode *right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
};

#endif  // SOLUTION_H
