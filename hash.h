#include <iostream>
#include <vector>
using namespace std;

class HashNode
{
	int key;
	int value;


	public:
	HashNode(int key, int value)
	{
		this -> key = key;
		this -> value = value;
	}

	int getKey()
	{
		return key;
	}

	int getValue()
	{
		return value;
	}

};

class HashTable
{
	int size;
	int count;
	vector<HashNode*> table; 

	public:

	int HashFunction(int key)
	{
		return key % size;
	}

	HashTable()
	{
		this->size = 128;
		this->count = 0;
		for(int i = 0; i < this->size; i++)
		{
			table.push_back(NULL);
		}
	}

	void Insert(int key, int value);
	int get(int key);
	void print();
	~HashTable();

	private:
	void resize();
};

void HashTable::print()
{
	for(int i=0; i<size; i++)
	{
		if(table[i] != NULL)
		{
			cout<<"("<<table[i]->getKey()<<","<<table[i]->getValue()<<")"<<" ";
		}
	}
	cout<<endl;
}

void HashTable::resize()
{
	int size1 = size;
	size = size + 5;
	vector<HashNode*> temp(size,NULL);
	for(int i = 0; i < size1; i++)
	{
		if(table[i] != NULL)
		{
			int hash = HashFunction(table[i]->getKey());
			int H(hash), j(1);

			while(temp[H] != NULL)
			{
				H = (hash + j * j) % size;
				j++;
			}

			temp[hash] = table[i];
		}
	}

	table=temp;
}

void HashTable::Insert(int key, int value)
{
	if(count == size)
	{
		resize();
	}

	int hash = HashFunction(key);

	int H(hash), j(1);
	while(table[H] != NULL && table[H]->getKey() != key)
	{
		H = (hash + j*j) % size;
		j++;
	}

	if(table[hash] != NULL)
	{
		delete table[hash];
	}

	table[hash] = new HashNode(key,value);

	count++;
}

int HashTable::get(int key)
{
	int hash = HashFunction(key);
	int H(hash), j(1);

	while(table[H] != NULL && table[H]->getKey() != key)
	{
		H = (hash + j*j) % size;
		j++;
	}

	if(table[hash] == NULL)
	{
		return -1;
	}

	return table[hash]->getValue();
}

HashTable::~HashTable()
{
	for(int i=0; i<size; i++)
	{
		if(table[i] != NULL)
		{
			delete table[i];
		}
	}
}


