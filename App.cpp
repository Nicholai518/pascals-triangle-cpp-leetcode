#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // triangle to be returned
        vector<vector<int>> triangle;

        // iterate through each row 
        for (int i = 0; i < numRows; i++) {

            // first iteration = 1 number
            // each row has 1 more number than the previous
            // each row starts with 1
            vector<int> row(i + 1, 1);

            // start at index 1 because each row has a 1 at index 0
            for (int j = 1; j < i; j++)
            {
                // sum of above 2 boxes
                row[j] = triangle[i - 1][j] + triangle[i - 1][j - 1];
            }
            // add row to triangle
            triangle.push_back(row);
        }
        // return triangle
        return triangle;
    }
};

 void print_triangle(vector<vector<int>> triangle) 
 {
    // iterates each row
    for (int i = 0; i < triangle.size(); i++) {
        int sizeOfRow = triangle[i].size();
        // iterates numbers within each row
        for (int j = 0; j < sizeOfRow; j++) {
            cout << triangle[i][j] << " ";
        }
        cout << endl;
    }
}


int main()
{
    Solution solution;
    vector<vector<int>> triangle;
    triangle = solution.generate(5);

    print_triangle(triangle);
	return 0;
}
