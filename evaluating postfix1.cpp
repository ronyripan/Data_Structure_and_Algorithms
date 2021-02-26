#include<iostream>
#include<stack>
#include<string>
using namespace std;
int evaluating_postfix(string a);
bool isnumeric(char c);
bool isoperator(char c);
int perform_operation(char operator1,int operand1,int operand2);
int main()
{
	string expression;
	cout<<"Enter Postfix Expression \n";
	getline(cin,expression);
	int result = evaluating_postfix(expression);
	cout<<"Output = "<<result<<"\n";
}
int evaluating_postfix(string expression)
{
	// Declaring a Stack from Standard template library in C++.
	stack<int> S;

	for(int i = 0;i< expression.length();i++) {

		// Scanning each character from left.
		// If character is a delimitter, move on.
		if(expression[i] == ' ' || expression[i] == ',') continue;

		// If character is operator, pop two elements from stack, perform operation and push the result back.
		else if(isoperator(expression[i])) {
			// Pop two operands.
			int operand2 = S.top(); S.pop();
			int operand1 = S.top(); S.pop();
			// Perform operation
			int result = perform_operation(expression[i], operand1, operand2);
			//Push back result of operation on stack.
			S.push(result);
		}
		else if(isnumeric(expression[i])){
			// Extract the numeric operand from the string
			// Keep incrementing i as long as you are getting a numeric digit.
			int operand = 0;
			while(i<expression.length() && isnumeric(expression[i])) {
				// For a number with more than one digits, as we are scanning from left to right.
				// Everytime , we get a digit towards right, we can multiply current total in operand by 10
				// and add the new digit.
				operand = (operand*10) + (expression[i] - '0');
				i++;
			}
			// Finally, you will come out of while loop with i set to a non-numeric character or end of string
			// decrement i because it will be incremented in increment section of loop once again.
			// We do not want to skip the non-numeric character by incrementing i twice.
			i--;

			// Push operand on stack.
			S.push(operand);
		}
	}
	// If expression is in correct format, Stack will finally have one element. This will be the output.
	return S.top();
}
bool isnumeric(char C)
{
	if(C >= '0' && C <= '9') return true;
	return false;
}
bool isoperator(char C)
{
	if(C == '+' || C == '-' || C == '*' || C == '/')
		return true;

	return false;
}
int perform_operation(char operation, int operand1, int operand2)
{
	if(operation == '+') return operand1 +operand2;
	else if(operation == '-') return operand1 - operand2;
	else if(operation == '*') return operand1 * operand2;
	else if(operation == '/') return operand1 / operand2;

	else cout<<"Unexpected Error \n";
	return -1;
}
/*int evaluating_postfix(string a)
{
    stack<int>s;
    for(int i = 0;i<a.length();i++)
    {
        if(a[i]==' '||a[i]==',') continue;
        else if(isnumeric(a[i]))
        {
            int operand = 0;
            while(i<a.length()&&isnumeric(a[i]))
            {
                operand=(operand*10)+(a[i]-'0');
                i++;
            }
            i--;
            s.push(operand);
        }
        else if(isoperator(a[i]))
        {
            int operand2 = s.top(); s.pop();
            int operand1 = s.top(); s.pop();
            int result = perform_operation(a[i],operand1,operand2);
            s.push(result);
        }
    }
    return s.top();
}
*/


