#include <iostream>
#include <stack>
using namespace std;

bool match(char a, char b)
{
	if(((a=='{')&&(b=='}'))||((a=='[')&&(b==']'))||((a=='(')&&(b==')'))) return true;
	else return false;
}

int main()
{
	stack<char > S;
	char par[]={'{','(',')','}','[',']'};

	for (int i=0; i<6; i++)
	{
		if (par[i]=='('||par[i]=='['||par[i]=='{') 
		{
			S.push(par[i]);
		}

		else if(S.empty())
		{
			cout<<"not balanced"<<endl;
			break;
		}

		else if(match(S.top(), par[i])) S.pop();

		else 
		{
			cout<<"not balanced"<<endl;
			break;
		}

	}

	if(S.empty()) cout<<"balanced!"<<endl;
	else cout<<"not balanced"<<endl;
}

