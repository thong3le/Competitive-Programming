#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(){
	int a[100];
	while (scanf("%d", a) != EOF) {
		int n = 0;
		while (a[n] != -999999){
			n++;
			scanf("%d", a + n);
		}

		long long ret[n];
		long long max = 
		for (int i = 1; i < n; i++){
			ret[i] = ret[i-1] * a[i];
		}

		for(int i = 0; i < n; i++){
			printf("%d ", ret[i]);
		}
		printf("\n");
	}
	
	return 0;
}