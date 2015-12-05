#include "trie.h"

int main()
{
	Trie trie;
	trie.Insert("fun");
	trie.Insert("furniture");
	trie.Insert("day");
	trie.Insert("daddy");
	trie.Insert("daemon");
	cout<<trie.with_prefix("da")<<endl;
}