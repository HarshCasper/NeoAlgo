#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
      string digitsNum(int N)
	{
		/* If N = 0 the string will be 0 */
		string ans = "";
		if (N == 0){
			ans += "0";
			return ans;
		}

		/* If n is not perfectly divisible by 9
		output the remainder */
		if (N % 9 != 0)
			ans += char(N % 9 + '0');

		/* Print 9 N/9 times */
		for (int i = 1; i <= (N / 9); ++i)
			ans += "9";

		/* Append N zero's to the number so as to
		make it divisible by 10^N */
		for (int i = 1; i <= N; ++i)
			ans += "0";

		return ans;
	}
};	
	
	int main(){
	    int t;
	    cin >> t;
	    while(t--){
	        int n;
	        cin >> n;
	        Solution ob;
	        string ans=ob.digitsNum(n);
	        cout << ans << endl;
	        
	    }
	    return 0;
	}