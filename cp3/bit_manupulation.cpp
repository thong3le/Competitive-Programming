#include <iostream>
#include <stack>

using namespace std;

#define is_on(S, i) (S & (1<<i))
#define set_bit(S, i) (S |= (1<<i))
#define clear_bit(S, i) (S &= ~(1<<i))
#define toggle_bit(S, i) (S ^= (1<<i))
#define low_bit(S) (S & (-S))
#define set_all(S, n) (S = (1<<n)-1)

void print_binary(int num){
	cout << "S = " << num << " = ";
	stack<int> stack;
	while (num)
		stack.push(num % 2), num >>= 1;
	while (!stack.empty())
		cout << stack.top(), stack.pop();
	cout << endl;
}

int main(){
	int S, T;
	cout << "Binary representation: " << endl;
	S = 34; 
	print_binary(S);
	S >>= 1; 
	print_binary(S);
	cout << is_on(S, 4) << endl;
	set_bit(S, 3);
	print_binary(S);
	return 0;
}