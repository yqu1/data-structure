#include "hash.h"

int main()
{
	HashTable hash;

	for(int i=0; i<130; i++)
	{
		hash.Insert(i,i+1);
	}

	hash.Insert(158,161);
	cout<<hash.get(158)<<endl;;
}