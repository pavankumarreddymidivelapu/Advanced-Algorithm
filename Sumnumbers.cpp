#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numMap;

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];

        if (numMap.find(complement) != numMap.end()) {
            vector<int> result;
            result.push_back(numMap[complement]);
            result.push_back(i);
            return result;
        }

        numMap[nums[i]] = i;
    }

    return vector<int>();
}

int main() {
    vector<int> nums1;
    nums1.push_back(2);
    nums1.push_back(7);
    nums1.push_back(11);
    nums1.push_back(15);

    int target1 = 9;
    vector<int> result1 = twoSum(nums1, target1);

    if (!result1.empty()) {
        cout << "Output: [" << result1[0] << ", " << result1[1] << "]" << endl;
    } else {
        cout << "No solution found." << endl;
    }

    vector<int> nums2;
    nums2.push_back(3);
    nums2.push_back(2);
    nums2.push_back(4);

    int target2 = 6;
    vector<int> result2 = twoSum(nums2, target2);

    if (!result2.empty()) {
        cout << "Output: [" << result2[0] << ", " << result2[1] << "]" << endl;
    } else {
        cout << "No solution found." << endl;
    }

    vector<int> nums3;
    nums3.push_back(3);
    nums3.push_back(3);

    int target3 = 6;
    vector<int> result3 = twoSum(nums3, target3);

    if (!result3.empty()) {
        cout << "Output: [" << result3[0] << ", " << result3[1] << "]" << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}
