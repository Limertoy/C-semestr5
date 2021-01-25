#include <iostream>
#include <typeinfo>
using namespace std;

void addOne(int x){
	cout << x+1;
}

int main() 
{ 
	int x;
	addOne(x+1); 
}
