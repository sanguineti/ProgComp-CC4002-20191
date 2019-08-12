#include<stdio.h>
#include <iostream>
#include <algorithm> 
using namespace std;

int isPossibleToPlaceCows(int stallers[], int n, int cows, int min){
    int placedCows = 1, lastPlacedCow = stallers[0];
    for(int i = 1; i<n; i++){
        if(stallers[i] - lastPlacedCow >= min){
            placedCows++;
            lastPlacedCow = stallers[i];
        }
        if (placedCows==cows) return true;
    }
    
    return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int cases;
	int n, cows;
	cin >> cases;
	for (int i = 0; i < cases; i++){
		cin >> n;
		cin >> cows;
		int stallers[n];
		for (int j = 0; j < n; j++){
			cin >> stallers[j];
        }
		sort(stallers, stallers + n);
		// hacer búsqueda binaria
        int hi = stallers[n-1];
        int lo = 0;
        int mid;
        while (hi - lo > 1){
            mid = lo + (hi - lo) / 2;
            if(isPossibleToPlaceCows(stallers, n, cows, mid)) lo = mid;
            else hi = mid;

        }
        cout << lo << endl;

	}
	return 0;
}