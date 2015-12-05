#include <iostream>

using namespace std;
#define ALPHABET_SIZE (26)

struct node
{
	int prefix_count;
	bool end;
	node* child[ALPHABET_SIZE];
};

class Trie
{
	node* head;

	public:
	node* GetNewNode();
	Trie();
	~Trie();
	void Insert(string word);
	bool Search(string word);
	void Delete(string word);
	void DeleteAll();
	bool IsEmpty()
	{
		if(head==NULL) return true;
		else return false;
	}

	int position(char c) 
	{
		return int(c)-int('a');
	}

	int with_prefix(string prefix);

	private:
	void Delete(string word, int i, node* current);
	void DeleteAll(node* current);
};

Trie::Trie()
{
	head=NULL;
}

Trie::~Trie()
{
	DeleteAll();
}

node* Trie::GetNewNode()
{
	node* temp=new struct node;
	temp->prefix_count=0;
	temp->end=false;
	for(int i=0; i<ALPHABET_SIZE; i++)
	{
		temp->child[i]=NULL;
	}
	return temp;
}

void Trie::Insert(string word)
{
	if(head==NULL)
	{
		head=GetNewNode();
	}

	if(Search(word)) return;

	node* current=head;

	for(int i=0; i<word.length(); i++)
	{
		int letter=position(word[i]);
		if(current->child[letter]==NULL) current->child[letter]=GetNewNode();
		(current->child[letter]->prefix_count)++;
		current=current->child[letter];
	}

	current->end=true;
}

bool Trie::Search(string word)
{
	node* current=head;

	if(current==NULL) return false;

	for(int i=0; i<word.length(); i++)
	{
		int letter=position(word[i]);
		if(current->child[letter]==NULL) 
		{
			return false;
		}
		current=current->child[letter];
	}

	return current->end;
}

int Trie::with_prefix(string prefix)
{
	node* current=head;

	if(current==NULL) return 0;

	for(int i=0; i<prefix.length(); i++)
	{
		int letter=position(prefix[i]);
		if(current->child[letter]==NULL) return 0;
		current=current->child[letter];
	}

	return current->prefix_count;

}

void Trie::Delete(string word)
{
	if (Search(word)==false)
	{
		cout<<"word does not exist"<<endl;
		return;
	}


	Delete(word, 0, head);


}

void Trie::Delete(string word, int i, node* current)
{
	if(i==word.length()) return;

	Delete(word, i+1, current->child[position(word[i])]);

	if((current->child[position(word[i])]->prefix_count)>1) (current->child[position(word[i])]->prefix_count)--;
	
	else
	{
		 delete current->child[position(word[i])];
		 current->child[position(word[i])]=NULL;
	}
}

void Trie::DeleteAll()
{
	if(IsEmpty()) return;
	DeleteAll(head);
	head=NULL;
}

void Trie::DeleteAll(node* current)
{
	for (int i=0; i<ALPHABET_SIZE; i++)
	{
	  if(current->child[i]!=NULL)
	  {
	  	   DeleteAll(current->child[i]);
	  }
	}
	delete current;
}

