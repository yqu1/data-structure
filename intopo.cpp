#include <stack>
#include <iostream>
using namespace std;

bool isoperand(string s);
bool isoperator(string s);
bool isopenpar(string s1);
bool isclosepar(string s1);
bool HasHigherPrec(string s1, string s2);

bool isoperand(string s)
{
	if((!isoperator(s))&&(!isclosepar(s))&&(!isopenpar(s)))
	{
		return true;
	}

	return false;
}

bool isoperator(string s)
{
	if((s=="+")||(s=="-")||(s=="*")||(s=="/"))
	{
		return true;
	}

	return false;
}

bool isopenpar(string s1)
{
	if((s1=="(")||(s1=="{")||(s1=="["))
	{
		return true;
	}

	return false;
}

bool isclosepar(string s1)
{
	if((s1==")")||(s1=="}")||(s1=="]"))
	{
		return true;
	}

	return false;
}

bool HasHigherPrec(string s1, string s2)
{

	if(((s1=="*")||(s1=="/"))&&((s2=="+")||(s2=="-"))) return true;

	return false;
}

int main()
{

stack<string > S;

string list[]={"2","*","(","3","+","4",")","+","5","/","6"};
string res="";

for(int i=0; i<11; i++)
{
	if(isoperand(list[i]))
	{
		res=res+list[i];
	}


	else if(isoperator(list[i]))
	{
		
		while((!S.empty())&&(!isopenpar(S.top()))&&HasHigherPrec(S.top(),list[i]))
		{
			res=res+S.top();
			S.pop();

		}
		S.push(list[i]);

	}

	else if(isopenpar(list[i])) 
	{
		S.push(list[i]);

	}

	else if(isclosepar(list[i]))
	{
		while((!S.empty())&&(!isopenpar(S.top())))
		{
			res=res+S.top();
			S.pop();
		}

		S.pop();
	}

}

while(!S.empty())
{
	res=res+S.top();
	S.pop();
}

cout<<res<<endl;

}