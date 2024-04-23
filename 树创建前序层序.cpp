#include<bits/stdc++.h>
using namespace std;
typedef struct treenode
{
	int var;
	treenode* left, * right;
	treenode() :var(0), left(nullptr), right(nullptr) {}
	treenode(int a) :var(a), left(nullptr), right(nullptr) {}
	treenode(int a, treenode* l, treenode* r) :var(a), left(l), right(r) {}

}* treelink;

void treebuild(treelink &r)
{
	int x;
	cin >> x;
	
	if (x==0)
	{
		r = nullptr;
		return;
	}
	else
	{
		r = new treenode(x);
		treebuild(r->left);
		treebuild(r->right);
	}
}
void preprint(treelink &r)
{
	if (r)
	{
		cout << r->var<< ' ';
		preprint(r->left);
		preprint(r->right);
	}
}

queue<treenode*> que;
void levelOrder1(treelink& r)
{
	if (!r)
	{
		return ;
	}
	que.push(r);
	while (!que.empty())
	{
		int size = que.size();
		for ( int i = 0; i < size; i++)
		{
			treenode* node = que.front();
			que.pop();
			cout << node->var << " ";
			if (node->left) que.push(node->left);
			if (node->right) que.push(node->right);
			
		}
		cout << endl;
	}
	
	return ;
}
void order(treelink& r,vector<vector<int>> & result, int depth)
{
	if (r) return;
	if (result.size()==depth)
	{
		result.push_back(vector<int>());
	}
	result[depth].push_back(r->var);
	order(r->left, result, depth + 1);
	order(r->right, result, depth + 1);
}
vector<vector<int>> levelOrder2(treelink& r)
{
	vector<vector<int>> result;
	int depth = 0;
	order(r,result,depth);
	return result;
}
int main()
{
	treelink r;
	treebuild(r);
	//preprint(r);
	levelOrder2(r);
	return 0;
}