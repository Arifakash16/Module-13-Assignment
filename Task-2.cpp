class Solution {
    public:

     // to check if the next position is safe
    bool isSafe(int x, int y, int N, vector<vector<int>>& m, vector<vector<bool>>& visited)
    {
        return (x >= 0 && x < N && y >= 0 && y < N && m[x][y] == 1 && !visited[x][y]);
    }

     
    bool backtrack(vector<vector<int>>& m, int x, int y, int N, vector<vector<bool>>& visited)
    {
        // If reached destination, return true
        if (x == N - 1 && y == N - 1) {
            return true;
        }

        // Define the possible moves (down, up, right, left)
        int rowMoves[] = {1, -1, 0, 0};
        int colMoves[] = {0, 0, 1, -1};

        // Mark the current cell as visited
        visited[x][y] = true;

        // Explore all possible directions
        for (int i = 0; i < 4; i++) {
            int newX = x + rowMoves[i];
            int newY = y + colMoves[i];

            // Check if the new position is within bounds, is not visited, and is accessible
            if (isSafe(newX, newY, N, m, visited)) {
                if (backtrack(m, newX, newY, N, visited)) {
                    return true;
                }
            }
        }

        // Unmark the cell (backtrack)
        visited[x][y] = false;
        return false;
    }


    // Function to check if there's a path for the rat
    bool isPathExist(vector<vector<int>>& m, int N)
    {
        // If starting cell is 0, return false
        if (m[0][0] == 0) return false;

        vector<vector<bool>> visited(N, vector<bool>(N, false));

        return backtrack(m, 0, 0, N, visited);
    }

  
};

// Time Complexity: O(n^2)
// Space Complexity: O(n^2)