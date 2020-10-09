// A Dynamic Programming based 
// C++ program to partition problem 
// thanks to gfg
#include <bits/stdc++.h> 
using namespace std; 

// Returns true if arr[] can be partitioned 
// in two subsets of equal sum, otherwise false 
bool findPartiion (int arr[], int n) 
{ 
	int sum = 0; 
	int i, j; 

	for (i = 0; i < n; i++) 
	sum += arr[i]; 
	
	if (sum % 2 != 0) 
	return false; // not possible if total sum is odd
	
	bool DP[sum / 2 + 1][n + 1]; 
    //if sum is zero then it is possible {empty set}
	for (i = 0; i <= n; i++) 
	  DP[0][i] = true; 
    //if n is zero then it is not possible 
    // remember base case  in recursion
	for (i = 1; i <= sum / 2; i++) 
	  DP[i][0] = false; 

	for (i = 1; i <= sum / 2; i++) 
	{ 
		for (j = 1; j <= n; j++) 
		{ 
			DP[i][j] = DP[i][j - 1]; 
			if (i >= arr[j - 1]) 
			DP[i][j] = DP[i][j] || 
						DP[i - arr[j - 1]][j - 1]; 
		}	 
	} 
	return DP[sum / 2][n]; 
} 


int main() 
{ 
	int arr[] = {3, 1, 1, 2, 2, 1}; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	if (findPartiion(arr, n) == true) 
		cout << "YES"; 
	else
		cout << "NO";
	return 0; 
} 

