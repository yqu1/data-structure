#include <iostream>
#include <vector>
#include "trie.h"
using namespace std;

vector<string > dict = {"GEEKS", "FOR", "QUIZ", "GO"};

class Boggle
{
	int row;
	int col;
	vector<vector<char> > board;
	vector<vector<bool> > visited;

	public:
	Boggle();
	Boggle(int row, int col);
	void FindWords();

	private:
	bool IsWord(string &str);
	void FindWordsUtil(int i, int j, string &str);
};

Boggle::Boggle()
{
	row(0);
	col(0);
}

Boggle::Boggle(int row, int column)
{
	this->row = row;
	this->col = col;

	for(int i = 0; i < row; i++)
	{
		vector<char> = Row;
		vector<bool> = flag
		for(int j = 0; j < col; j++)
		{
			cout << "enter character: "<<endl;
			cin >> Row[j];
			flag[j] = false;

		}

		board[i] = Row;
		visited[i] = flag;
	}
}

bool Boggle::IsWord(string &str)
{
	for(int i=0; i<dict.size(); i++)
	{
		if(str.compare(dict[i]) == 0) return true;
	}

	return false;
}

void Boggle::FindWords()
{
	string str = "";
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			FindWordsUtil(i, j, str);
		}
	}
}

void Boggle::FindWordsUtil(int i, int j, string &str)
{
	visited[i][j] = true;
	str = str + board[i][j];

	if(IsWord(str)) cout<<str<<endl;

	for(int )

}


