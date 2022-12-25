#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout << "Write a string that includes '(', ')', '{', '}', '[' and ']': " << endl;
	string str = "";
	getline(cin, str);
	const int len = str.length();
	int maxDepth = 0;
	char stack[1000];
	int stackTop = 0;
	bool fl = false;
	for (int i = 0; i < len; i++) {
		if (str[i] == '[' || str[i] == ']' || str[i] == '(' || str[i] == ')' || str[i] == '{' || str[i] == '}') {
			if (str[i] == '[' || str[i] == '(' || str[i] == '{') {
				stack[stackTop] = str[i];
				stackTop++;
			}
			else {
				if ((str[i] == ')' && stack[stackTop - 1] == '(') || (str[i] == ']' && stack[stackTop - 1] == '[') || 
					(str[i] == '}' && stack[stackTop - 1] == '{')) {
					
					stack[stackTop - 1] = '0';
					stackTop--;
				}
				else {
					fl = true;
					break;
				}
			}
			if (maxDepth < stackTop) {
				maxDepth = stackTop;
			}
		}
	}

	if (fl == false) {
		cout << "The string is right. Max depth: " << maxDepth << endl;
	}
	else {
		cout << "The string is not right" << endl;
	}
	
	return 0;
}
