//  Quiz 1

//1.Removing duplicates from a sorted array

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;

    int i = 0;
    for (int j = 1; j < nums.size(); j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}

//2.Rotate Array

void rotate(vector<int>& nums, int k) {
    k = k % nums.size(); 
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}

//3.Finding Duplicates

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> seen;
    for (int num : nums) {
        if (seen.find(num) != seen.end()) {
            return true;
        }
        seen.insert(num);
    }
    return false;
}

//4. Single number

int singleNumber(vector<int>& nums) {
    int single = 0;
    for (int num : nums) {
        single ^= num;
    }
    return single;
}

