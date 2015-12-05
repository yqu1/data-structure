#include <iostream>
#include <queue>
using namespace std;
const int MAX=100000000;
const int MIN=-100000000;

struct BstNode
{
	int data;
	BstNode* left;
	BstNode* right;
};

class BST
{
	BstNode* root;

	public:
	BST();
	~BST();
	void Insert(int data);
	BstNode* GetNewNode(int x);
	bool Search(int data);
	BstNode* Find(int value);
	BstNode* FindMax(BstNode* node);
	BstNode* FindMin(BstNode* node);
	int FindHeight();
	void LevelOrder();
	void PreOrder();
	void InOrder();
	void PostOrder();
	bool IsBST();
	bool IsBSTGreater(BstNode* node, int value);
	bool IsBSTLesser(BstNode* node, int value);
	bool IsBSTUtil(int max, int min);
	void Delete(int data);
	BstNode* GetSuccessor(int value);
	private:
	void Insert(BstNode* node, BstNode* parent, int value);
	int FindHeight(BstNode* cur);
	void PreOrder(BstNode* node);
	void InOrder(BstNode* node);
	void PostOrder(BstNode* node);
	bool IsBST(BstNode* node);
	bool IsBSTUtil(BstNode* node, int max, int min);
	void Delete(BstNode* node, BstNode* parent, int value);
	void post_order_delete(BstNode *node);

};

BST::BST()
{
	root=NULL;
}

BST::~BST()
{
	post_order_delete(root);
}

void BST::Insert(int data)
{
	
	Insert(root, NULL, data);
}

void BST::Insert(BstNode* node, BstNode* parent, int value)
{
	if(node==NULL)
	{
		node=GetNewNode(value);
		if(parent==NULL) root=node;
		else if(value<=parent->data) parent->left=node;
		else if(value>parent->data) parent->right=node;
	}



	else if(value<=node->data)
	{
		Insert(node->left, node, value);
	}

	else if(value>node->data)
	{
		Insert(node->right, node, value);
	}

}

BstNode* BST::GetNewNode(int x)
{
	BstNode* temp=new struct BstNode;
	temp->data=x;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

bool BST::Search(int data)
{
	BstNode* temp=root;

	if(root==NULL)
	{
		return false;
	}

	while(temp!=NULL)
	{
		if(data<temp->data) temp=temp->left;

		else if(data>temp->data) temp=temp->right;

		else return true;
	}

	return false;
}

BstNode* BST::Find(int value)
{
	BstNode* temp=root;

	if(root==NULL)
	{
		return NULL;
	}

	while(temp!=NULL)
	{
		if(value<temp->data) temp=temp->left;

		else if(value>temp->data) temp=temp->right;

		else return temp;
	}

	return NULL;
}

BstNode* BST::FindMin(BstNode* node)
{
	if (node->left == nullptr) // go left until reached leaf
		return node;
	return FindMin(node->left);
}


BstNode* BST::FindMax(BstNode* node)
{
	if (node->right == nullptr) // go right until reached leaf
		return node; 
	return FindMax(node->right);
}

int BST::FindHeight()
{
	return FindHeight(root);
}

int BST::FindHeight(BstNode* cur)
{
	if(cur==NULL)
	{
		return -1;
	}

	int LH=FindHeight(cur->left);
	int RH=FindHeight(cur->right);

	return max(LH,RH)+1;
}

void BST::LevelOrder()
{
	if(root==NULL) 
	{
		cout<<"tree is empty"<<endl;
		return;
	}
	queue<BstNode* > Q;
	Q.push(root);

	while(!Q.empty())
	{
		BstNode* current=Q.front();
		cout<<current->data<<" "<<endl;;
		if(current->left!=NULL) Q.push(current->left);
		if(current->right!=NULL) Q.push(current->right);

		Q.pop();
	}
}

void BST::PreOrder()
{
	PreOrder(root);
}

void BST::PreOrder(BstNode* node)
{	
	if(node==NULL) return;
	cout<<node->data<<endl;
	PreOrder(node->left);
	PreOrder(node->right);
}

void BST::InOrder()
{
	InOrder(root);
}

void BST::InOrder(BstNode* node)
{
	if(node==NULL) return;
	InOrder(node->left);
	cout<<node->data<<endl;
	InOrder(node->right);
}

void BST::PostOrder()
{
	PostOrder(root);
}

void BST::PostOrder(BstNode* node)
{
	if(node==NULL) return;
	PostOrder(node->left);
	PostOrder(node->right);
	cout<<node->data<<endl;
}

bool BST::IsBST()
{
	return IsBST(root);
}

bool BST::IsBST(BstNode* node)
{
	if(node==NULL) return true;

	if(IsBSTGreater(node->right, node->data)&&IsBSTLesser(node->left, node->data)&&IsBST(node->left)&&IsBST(node->right)) return true;
	return false;
}

bool BST::IsBSTGreater(BstNode* node, int value)
{
	if(node==NULL) return true;

	if((node->data>value)&&IsBSTGreater(node->left, value)&&IsBSTGreater(node->right, value)) return true;
	return false;
}

bool BST::IsBSTLesser(BstNode* node, int value)
{
	if(node==NULL) return true;

	if((node->data<=value)&&IsBSTLesser(node->left, value)&&IsBSTLesser(node->right, value)) return true;
	return false;
}

bool BST::IsBSTUtil(int max, int min)
{
	return IsBSTUtil(root, max, min);
}

bool BST::IsBSTUtil(BstNode* node, int max, int min)
{
	if(node==NULL) return true;

	if(node->data<=max && node->data>min && IsBSTUtil(node->left, node->data, min) && IsBSTUtil(node->right, max, node->data))
		return true;
	return false;
}

void BST::Delete(int value)
{
	Delete(root, NULL, value);
}

void BST::Delete(BstNode* node, BstNode* parent, int value)
{
	if(node==NULL)
	{
		if(parent==NULL)
		{
			cout<<"tree is already empty"<<endl;
			return;
		}

		else  return;
	}

	else if(node->data<value) Delete(node->right, node, value);


	else if(node->data>value) Delete(node->left, node, value);

	else
	{
		//case 1:
		if(node->left==NULL&&node->right==NULL)
		{
			if(parent==NULL) 
			{
				root=NULL;
				return;
			}
			else 
			{
				if (node->data < parent->data)
						parent->left = NULL;
				else
						parent->right = NULL;
			}
			delete node;
			node=NULL;
			return;
		}

		//case 2:
		else if(node->left==NULL)
		{
			if (parent == NULL) 
			{
				root = node->right;
			}
			if(parent->left==node) parent->left=node->right;

			if(parent->right==node) parent->right=node->right;
			delete node;
			node=NULL;
			return;
		}

		else if(node->right==NULL)
		{
			if (parent == NULL) 
			{
				root = node->left;
			}
			if(parent->data > node->right->data) parent->left=node->left;

			if(parent->data < node->right->data) parent->right=node->left;
			delete node;
			node=NULL;
			return;
		}

		//case 3:
		else
		{
			BstNode* temp=FindMin(node->right);
			node->data=temp->data;
			Delete(node->right,node,temp->data);

		}
	}
}

void BST::post_order_delete(BstNode *node)
{
	if (node == NULL) return; // base case
	else 
	{ // post-order traversal
		post_order_delete(node->left);
		post_order_delete(node->right);
		delete node;
	}
}


BstNode* BST::GetSuccessor(int value)
{
	BstNode* Current=Find(value);
	if(Current==NULL) return NULL;

	//case 1: has right subtree
	else if(Current->right!=NULL) return FindMin(Current->right);

	//case 2: no right subtree
	else
	{
		BstNode* Ancestor=root;
		BstNode* Successor=NULL;

		while(Ancestor!=Current)
		{
			if(Current->data<Ancestor->data) 
			{
				Successor=Ancestor;
				Ancestor=Ancestor->left;
			}

			else
			{
				Ancestor=Ancestor->right;
			}
		}

		return Successor;
	}


}



