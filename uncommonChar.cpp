//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to remove duplicate characters from a string
    string removeDuplicates(string s)
    {
        string str = "";
        int hash[26] = {0}; // Hash array to count occurrences of each character

        // Count occurrences of each character in the string
        for (int i = 0; i < s.length(); i++)
        {
            hash[s[i] - 'a']++;
        }

        // Construct a new string without duplicate characters
        for (int i = 0; i < 26; i++)
        {
            if (hash[i] > 0)
            {
                str += (i + 'a'); // Append characters to the result string
            }
        }
        return str; // Return the string without duplicates
    }

    // Function to find and return uncommon characters between two strings
    string UncommonChars(string a, string b)
    {
        string ans = "";         // String to store uncommon characters
        a = removeDuplicates(a); // Remove duplicates from string a
        b = removeDuplicates(b); // Remove duplicates from string b

        int n = a.length(), m = b.length();

        int hash[26] = {0};  // Hash array to count occurrences of characters
        string temp = a + b; // Concatenate strings a and b

        // Count occurrences of each character in the concatenated string
        for (int i = 0; i < m + n; i++)
        {
            hash[temp[i] - 'a']++;
        }

        // Find uncommon characters
        for (int i = 0; i < 26; i++)
        {
            if (hash[i] == 1)
            {
                ans += char(i + 'a'); // Append uncommon characters to the result string
            }
        }

        // If no uncommon characters found, return "-1"
        return (ans.length()) ? ans : "-1";
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string A, B;
        cin >> A;
        cin >> B;
        Solution ob;
        cout << ob.UncommonChars(A, B);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


/*
Given two strings A and B consisting of lowercase english characters. Find the characters that are not common in the two strings. 

Note :- Return the string in sorted order.

Example 1:

Input:
A = geeksforgeeks
B = geeksquiz
Output: fioqruz
Explanation: 
The characters 'f', 'i', 'o', 'q', 'r', 'u','z' 
are either present in A or B, but not in both.


Your Task:  
You dont need to read input or print anything. Complete the function UncommonChars() which takes strings A and B as input parameters and returns a string that contains all the uncommon characters in sorted order. If no such character exists return "-1".
*/