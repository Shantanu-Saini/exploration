#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> stringToMatrix(string S)
{
    int length = S.length();
    int rows = floor(sqrt(length));
    int cols = ceil(sqrt(length));

    int nonSpaceChars = 0;
    for (char c : S)
    {
        if (c != ' ')
        {
            nonSpaceChars++;
        }
    }

    vector<vector<char>> matrix(rows, vector<char>(cols, ' '));

    int index = 0;
    for (char c : S)
    {
        if (c != ' ')
        {
            matrix[index / cols][index % cols] = c;
            index++;
        }
    }

    return matrix;
}

int main()
{
    string S;
    cout << "Enter a string: ";
    getline(cin, S);
    int length = S.length();
    int rows = floor(sqrt(length));
    int cols = ceil(sqrt(length));

    vector<vector<char>> matrix = stringToMatrix(S);

    cout << "Matrix representation of the string:\n";
    for (int i = 0; i < rows; ++i)
    {
        cout << "{ ";
        for (int j = 0; j < cols; ++j)
        {
            cout << matrix[i][j] << ' ';
        }
        cout << " }" << '\n';
    }

    return 0;
}
