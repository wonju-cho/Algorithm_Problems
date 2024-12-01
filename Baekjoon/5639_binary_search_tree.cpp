#include<iostream>

using namespace std;

struct Node
{
	Node() = default;
	Node(int data) : mData(data){}

	int mData = -1;
	Node* mLeft = nullptr;
	Node* mRight = nullptr;
};

Node* InsertNode(Node* node, int data)
{
	if(node == nullptr)
	{
		return new Node(data);
	}

	if (data < node->mData)
		node->mLeft = InsertNode(node->mLeft, data);
	else
		node->mRight = InsertNode(node->mRight, data);

	return node;
}

void PostOrder(Node* root)
{
	if (root == nullptr)
		return;
	
	PostOrder(root->mLeft);
	PostOrder(root->mRight);
	cout << root->mData << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int data;
	Node* root = nullptr;
	
	while(cin >> data)
	{
		root = InsertNode(root, data);
	}

	PostOrder(root);
}