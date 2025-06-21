
#include <bits/stdc++.h>
using namespace std;

// Type - 1 : Returning the value at particular row and number
int nCr(int n, int r) {
    int res = 1;
    for (int i = 0; i < r; i++) {
        res = res * (n - i) / (i + 1);
    }
    return res;
}

// Type - 2 : Returning a Particular Line

void pascalTriangle(int n) {
    // printing the entire row n:
    for (int c = 1; c <= n; c++) {
        cout << nCr(n - 1, c - 1) << " ";
    }
    cout << "n";
}


// Type - 3 : COmplete Pascal Triangle

vector<vector<int>> completePascalTriangle(int n) {   
vector<vector<int>> ans;

    //Store the entire pascal's triangle:
    for (int row = 1; row <= n; row++) {
        vector<int> tempLst; // temporary list
        for (int col = 1; col <= row; col++) {
            tempLst.push_back(nCr(row - 1, col - 1));
        }
        ans.push_back(tempLst);
    }
    return ans;
}