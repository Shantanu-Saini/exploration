#include <iostream>
#include <cmath> // Required for round function

class Solution
{
public:
    // Function to find the square root of a given integer 'x'
    int mySqrt(int x)
    {
        // If 'x' is 0 or 1, the square root is 'x' itself
        if (x == 0 || x == 1)
            return x;

        // Initialize start and end for binary search
        int start = 2;
        int end = x;
        long long mid = start + (end - start) / 2; // Using long long to avoid overflow

        // Binary search for the square root of 'x'
        while (start <= end)
        {
            // Calculate mid point
            mid = start + (end - start) / 2;

            // If the square of mid is greater than 'x', move towards lower values
            if (mid * mid > x)
            {
                end = mid - 1;
            }
            // If the square of mid is equal to 'x', return mid
            else if (mid * mid == x)
            {
                return mid;
            }
            // If the square of mid is less than 'x', move towards higher values
            else
            {
                start = mid + 1;
            }
        }
        // Return the rounded square root
        // The square root is rounded down due to the binary search algorithm:
        // At the end of the binary search loop, 'end' points to the largest integer
        // whose square is less than or equal to 'x'. This integer is the floor
        // of the square root of 'x'. Hence, we return 'end' rounded to the nearest integer.
        return round(end);
    }
};

int main()
{
    // Example usage
    Solution solution;
    int x = 16;
    std::cout << "Square root of " << x << " is: " << solution.mySqrt(x) << std::endl;
    return 0;
}
