#include <bits/stdc++.h>
using namespace std;
const int N = 2*10e5;
#define ll long long
ll n, m, a[N];

int main(){
    cin >> n;
    ll max_sum = 0, left_sum, right_sum;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    ll left = 0, right = n-1;
    left_sum = a[left]; right_sum = a[right];
    while(left < right){
        if(left_sum == right_sum){
            max_sum = max(max_sum,left_sum);
            left++;
            right--;
            left_sum += a[left];
            right_sum += a[right];
        }
        else if(left_sum > right_sum){
            right--;
            right_sum += a[right];
        }
        else{
            left++;
            left_sum += a[left];
        }
    }
    cout << max_sum << endl;
}