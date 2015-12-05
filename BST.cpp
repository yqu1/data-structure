#include "BST.h"


int main()
{
	BST bst;
	bst.Insert(3);
	bst.Insert(4);
	bst.Insert(2);
	bst.Insert(5);



	int number, data;
	cout<<"Enter number be searched: "<<endl;
	cin>>number;
	if(bst.Search(number)) cout<<"Found!"<<endl;
	else cout<<"Not found"<<endl;

	cout<<"Height is: "<<bst.FindHeight()<<endl;
	cout<<"Level order traversal: "<<endl;
	bst.LevelOrder();
	cout<<"Preorder traversal: "<<endl;
	bst.PreOrder();
	cout<<"Inorder traversal: "<<endl;
	bst.InOrder();
	cout<<"Postorder traversal: "<<endl;
	bst.PostOrder();
	if(bst.IsBSTUtil(MAX,MIN)) cout<<"is bst!"<<endl;
	else cout<<"is not bst!"<<endl;
	cout<<"delete a node: "<<endl;
	cin>>data;
	bst.Delete(data);
	cout<<endl;
	bst.LevelOrder();
	cout<<"get successor of node: "<<endl;
	cin>>number;
	if(bst.GetSuccessor(number)!=NULL) cout<<"successor is: "<<(bst.GetSuccessor(number))->data<<endl;
	else cout<<"not in list"<<endl;
}