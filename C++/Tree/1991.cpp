#include <iostream>
#include <vector>

using namespace std;

struct node {
	char left;
	char right;
};

vector<node> BST(128);

void pre_order(char node)
{
	if (node == '.') return;

	cout << node;
	pre_order(BST[node].left);
	pre_order(BST[node].right);
}

void in_order(char node)
{
	if (node == '.') return;

	in_order(BST[node].left);
	cout << node;
	in_order(BST[node].right);
}

void post_order(char node)
{
	if (node == '.') return;

	post_order(BST[node].left);
	post_order(BST[node].right);
	cout << node;
}

int main()
{
	
	int N;
	cin >> N;

	while (N--)
	{
		char base, left, right;
		cin >> base >> left >> right;

		BST[base].left = left;
		BST[base].right = right;
	}

	char root = 'A';
	pre_order(root);
	cout << endl;
	in_order(root);
	cout << endl;
	post_order(root);
}