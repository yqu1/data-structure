#include <iostream>
#include <stack>
#include <sstream>
#include <stdlib.h>
using namespace std;

double operation(double op1, double op2, string op)
{
	if(op=="+") return op1+op2;

	if(op=="-") return op2-op1;

	if(op=="*") return op2*op1;

	if(op=="/") return double(op2)/double(op1);

	else return 0;
}

int main()
{
	stack<string > S;
	string list[]={"2","3","*","5","4","*","+","9","-"};
	double op1, op2, temp;
	std::ostringstream strs;
	std::string str;
	for (int i=0; i<9; i++)
	{
		if ((list[i]!="+")&&(list[i]!="-")&&(list[i]!="*")&&(list[i]!="/"))
		{
			S.push(list[i]);
		}

		else
		{
			op1=stod(S.top());
			S.pop();
			op2=stod(S.top());
			S.pop();
			temp=operation(op1,op2,list[i]);
			std::ostringstream strs;
			strs << temp;
			std::string str;
			str = strs.str();
			S.push(str);
		}
	}

	cout<<S.top()<<endl;

}