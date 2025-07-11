#include<bits/stdc++.h>
using namespace std;


 int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        int n1 = version1.size();
        int n2 = version2.size();

        while (i < n1 || j < n2) {
            int num1 = 0;
            int num2 = 0;

            // Extract number from version1
            while (i < n1 && version1[i] != '.') {
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }

            // Extract number from version2
            while (j < n2 && version2[j] != '.') {
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }

            if (num1 > num2) return 1;
            if (num1 < num2) return -1;

            // Skip dots
            i++;
            j++;
        }

        return 0;
    }