//Naive algorithm for Pattern Searching
#include <bits/stdc++.h> 
using namespace std; 

void search(string txt2, string txt1) 
{ 
	int M = txt2.size(); 
	int N = txt1.size(); 
	int i = 0; 

	while (i <= N - M) 
	{ 
		int j; 

	
		for (j = 0; j < M; j++) 
			if (txt1[i + j] != txt2[j]) 
				break; 

		if (j == M) 
		{ 
			cout << "Pattern found at index " << i << endl; 
			i = i + M; 
		} 
		else if (j == 0) 
			i = i + 1; 
		else
			i = i + j; 
	} 
} 


int main() 
{ 
	string txt1 = "HELLOWORLDTHISISRIYA"; 
	string txt2 = "IS"; 
	search(txt2, txt1); 
	return 0; 
} 



