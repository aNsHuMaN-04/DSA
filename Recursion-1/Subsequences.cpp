#include<bits/stdc++.h>
using namespace std;


void subsequence(int i, string s, string &f) {
	if (i == s.length()) {
		cout << f << " ";
		return;
	}

	//Pick Condition for index i
	f = f + s[i];
	subsequence(i + 1, s,  f);

	//Popping out while backtracking , i.e. Don't Pick Condition for index i
	f.pop_back();
	subsequence(i + 1, s,  f);

}
