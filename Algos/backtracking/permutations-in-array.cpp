#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> ans;

void generatePermutation(vector<int>& nums, int j) {
    if (j == nums.size()) {
        ans.push_back(nums);
        return;
    }
    for (int i = j; i < nums.size(); i++) {
        swap(nums[i], nums[j]);
        generatePermutation(nums, j + 1);
        swap(nums[i], nums[j]); // backtrack
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    ans.clear(); // Important to avoid old results on multiple runs
    generatePermutation(nums, 0);
    return ans;
}

int main() {
    int n;
    cout << "Enter size of the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<vector<int>> permutations = permute(nums);

    cout << "\nAll permutations are:\n";
    for (const auto& perm : permutations) {
        for (int val : perm) {
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}
