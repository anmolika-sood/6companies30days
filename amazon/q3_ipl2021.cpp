// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
      vector <int> v;
      deque <int> dq;
      for(int i=0;i<arr.size();i++){
          
          while(!dq.empty()&&arr[i]>=dq.back())
          dq.pop_back();
          dq.push_back(i);
          if(!dq.empty()&&dq.front()==i-k)
          dq.pop_front();
          
          if(i>=k-1)
          v.push_back(arr[dq.front()]);
      }
     return v;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}  // } Driver Code Ends
