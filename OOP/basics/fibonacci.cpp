#include <iostream>
#include <vector>

using namespace std;

class fibonacci {
  public:
    int n;

    vector<int> series() {
        vector<int> ans = {0,1};
        ans.reserve(n);
        for (int _ = 2; _<n; _++) {
            ans.push_back(ans[ans.size()-2] + ans[ans.size()-1]);
        }
        return ans;
    }
};

int main() {
    fibonacci f;
    cout<<"Enter n: ";
    cin>> f.n;
    cout<<"The series is: "<<endl;
    for (int i: f.series()) {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
