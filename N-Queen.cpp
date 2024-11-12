#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define pb push_back

bool isSafe(int **arr, int x, int y, int n)
{
    // Check the column above (x, y)
    for (ll row = 0; row < x; row++)
    {
        if (arr[row][y] == 1) return false;  // If there's a queen above, it's not safe
    }

    // Check the upper-left diagonal
    int row = x;
    int col = y;
    while(row >= 0 && col >= 0)  // Move up and to the left
    {
        if(arr[row][col] == 1) return false;  // If there's a queen on the diagonal, it's not safe
        row--;  // Move up
        col--;  // Move left
    }

    // Check the upper-right diagonal
    row = x;
    col = y;
    while(row >= 0 && col < n)  // Move up and to the right
    {
        if(arr[row][col] == 1) return false;  // If there's a queen on the diagonal, it's not safe
        row--;  // Move up
        col++;  // Move right
    }

    return true;  // Safe to place queen at (x, y) if no threats found
}

// Recursive function to solve the N-Queens problem
bool nQueen(int** arr, int x, int n)
{
    // Base case: all queens are placed successfully
    if(x >= n) return true;

    // Try placing a queen in each column of the current row (x)
    for(int col = 0; col < n; col++)
    {
        // Check if placing queen at (x, col) is safe
        if(isSafe(arr, x, col, n))
        {
            arr[x][col] = 1;  // Place queen at (x, col)

            // Recursively try to place queens in the next row
            if(nQueen(arr, x + 1, n)) return true;  // If successful, return true
        }

        // Backtrack: remove queen from (x, col) if placing it here leads to no solution
        arr[x][col] = 0;
    }

    return false;  // Return false if no safe position in the current row
}

int main()
{
    int n;
    cin >> n;  // Input the size of the board (n x n)

    // Dynamically allocate a 2D array (n x n) for the chessboard, initializing all elements to 0
    int** arr = new int*[n];
    for (ll i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (ll j = 0; j < n; j++)
        {
            arr[i][j] = 0;  // No queens placed initially
        }
    }

    // Attempt to solve the N-Queens problem starting from the first row
    if(nQueen(arr, 0, n))
    {
        // Print the solution (positions of the queens on the board)
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";  // Print each row
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No solution exists for " << n << " queens." << endl;  // If no solution is found
    }

    // Free dynamically allocated memory
    for (ll i = 0; i < n; i++) delete[] arr[i];
    delete[] arr;

    return 0;
}
