class Solution {

    public:
     void backtrack(string &str, int start, vector<string> &results) {
        if (start == str.size() - 1) { // if start+1 is equal to string size then I found one permutaion
            results.push_back(str);
            return;
        }

        for (int i = start; i < str.size(); i++) {
            swap(str[start], str[i]); // Swap the current character with the start
            backtrack(str, start + 1, results); // Recurse
            swap(str[start], str[i]); // Backtrack (swap back)
        }
    }

    vector<string> permute(string str) {
        vector<string> results;
        backtrack(str, 0, results);
        return results;
    }

};

// Time Complexity: O(n!)
// Space Complexity: O(n!)