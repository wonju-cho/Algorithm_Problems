#include<iostream>
#include<unordered_map>

using namespace std;

struct Node
{
	Node() = default;
	Node(char data) : mData(data) {}

	char mData = '.';
	Node* mLeft = nullptr;
	Node* mRight = nullptr;
};

void PreOrder(Node* t)
{
	if (t == nullptr)
		return;

	cout << t->mData;
	PreOrder(t->mLeft);
	PreOrder(t->mRight);
}

void InOrder(Node* t)
{
	if (t == nullptr)
		return;

	InOrder(t->mLeft);
	cout << t->mData;
	InOrder(t->mRight);
}

void PostOrder(Node* t)
{
	if (t == nullptr)
		return;

	PostOrder(t->mLeft);
	PostOrder(t->mRight);
	cout << t->mData;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	cin >> N;

	unordered_map<char, Node*> tree;

	for (int i = 0; i < N; i++)
	{
		char node;
		char left;
		char right;
		cin >> node; cin >> left; cin >> right;

		if (!tree.count(node))
		{
			tree[node] = new Node(node);
		}

		if (left != '.') {
			if (!tree.count(left)) {
				tree[left] = new Node(left);
			}
			tree[node]->mLeft = tree[left];
		}
		if (right != '.') {
			if (!tree.count(right)) {
				tree[right] = new Node(right);
			}
			tree[node]->mRight = tree[right];
		}
	}

	Node* root = tree['A'];

	PreOrder(root);
	cout << "\n";
	InOrder(root);
	cout << "\n";
	PostOrder(root);

}