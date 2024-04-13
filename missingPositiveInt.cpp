#include <iostream>
#include <vector>

using namespace std;

// Function declaration
int firstMissingPositive(vector<int> &nums)
{
    int n = nums.size(); // Get the size of the input array

    int i = 0; // Initialize the loop index

    // Rearrange the elements in the array such that each positive integer
    // nums[i] is placed at its correct position nums[nums[i] - 1]
    while (i < n)
    {
        // Ensure that nums[i] is a positive integer and it is within the
        // range [1, n] Also, make sure that nums[i] is not already at its
        // correct position
        if (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
        {
            // Swap the current element with the element at its correct
            // position
            swap(nums[i], nums[nums[i] - 1]);
        }
        else
        {
            // Move to the next element if the current element doesn't meet
            // the conditions
            i++;
        }
    }

    for (int c : nums)
    {
        cout << c << ' ';
    }
    // output: 1 -1 3 4

    // Iterate through the array to find the first missing positive integer
    for (int i = 0; i < n; ++i)
    {
        // If the current element is not equal to its index + 1, then it is
        // the missing positive integer
        if (nums[i] != i + 1)
        {
            return i + 1;
        }
    }

    // If all positive integers in the range [1, n] are present, return n +
    // 1
    return n + 1;
}

int main()
{
    // Test case 1
    vector<int> nums1 = {3, 4, -1, 1};
    cout << "\n missing num : " << firstMissingPositive(nums1) << "\n";

    return 0;
}
