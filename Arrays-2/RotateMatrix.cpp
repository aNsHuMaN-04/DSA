//By observation, we see that the first column of the original matrix is the reverse of the first row of the rotated matrix, 
//so that’s why we transpose the matrix and then reverse each row . 

#include<bits/stdc++.h>
using namespace std;

void rotate(vector < vector < int >> & matrix) {
    int n = matrix.size();
    //transposing the matrix
    for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
        swap(matrix[i][j], matrix[j][i]);
    }
    }
    //reversing each row of the matrix
    for (int i = 0; i < n; i++) {
    reverse(matrix[i].begin(), matrix[i].end());
    }
}