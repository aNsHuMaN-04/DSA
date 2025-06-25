 #include <bits/stdc++.h>
using namespace std;
 
// Approach -1  : O(N)

// Range of int is ....-648 to ....+647 
// Therefore while convertig from positive to negative that -648 might be an issue 
// And cuz of that we use long n1
// This approach gives TLE btw hehehe
 
double myPow(double x, int n) {
        
    double ans = 1.0;
    long n1 = n; 
    if(n < 0)
        n1 = -n;
    
    for (long i = 1; i <= n1; i++)
       {
        ans = ans * x;
       }

       if(n < 0)
        ans = 1/ans;

      return ans;
    }

    // Approach -2 : O(logn) : Binary Exponentiation
    
     double myPow1(double x, int n) {
        
    double ans = 1.0;
    long n1 = n;
    
    if (n1 < 0) 
        n1 = -n1;
    
    while (n1 != 0) 
    {
     
        if (n1 % 2 == 0) 
    {
      x = x * x;
      n1 = n1 / 2;
    }
       else 
     {
        ans = ans * x;
        n1 = n1 - 1;
     }
  }

  if (n < 0)
   ans = 1.0 / ans ;
  return ans;
}
    