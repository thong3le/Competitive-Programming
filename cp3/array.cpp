#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
	int a[5] = {7,7,7};
	vector<int> v(5,5); 

	printf("a[2] = %d  and v[2] = %d\n", a[2], v[2]);
	for(int i = 0; i < 5; i++){
		a[i] = i;
		v[i] = i;
	}
	printf("a[2] = %d  and v[2] = %d\n", a[2], v[2]);
	v.push_back(5);
	printf("%d\n", (int)v.size());
	printf("%d\n", v[5]);


 	for(auto it = v.begin(); it != v.end(); it++){
 		*it += 1;
 		printf(" %d", *it);
 	}

 	printf("\n");
 	printf("%d\n", v.front());
 	printf("%d\n", * max_element(v.begin(), v.end()));
	
 	string test = "THONGLE";
 	for(string::iterator it = test.begin(); it != test.end(); it++){
 		printf("%c\n", *it);
 	}
	return 0;
}