#include<iostream>
#include <stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<queue>
#include<string>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* CreateBinaryTree(vector<string> data);//创建二叉树
void PreOrder(TreeNode* root);//前序遍历
void InOrder(TreeNode* root);//中序遍历
void PostOrder(TreeNode* root);//后序遍历
void LayerOrder(TreeNode* root);//层先遍历
void Leaf(TreeNode* root);//统计叶节点数目，输出叶节点
bool hasPathSum(TreeNode* root, int sum);
bool hasPathSum1(TreeNode* root, int sum);
void myhasPathSum(TreeNode* root, vector<int> path, int sum, bool &flag);
int left_count = 0;
int main()
{
	vector<string> data = { "1", "2", "3", ".", "4", ".", "5", "6", "7", ".", "8" };
	TreeNode* root = CreateBinaryTree(data);
	/*PreOrder(root);
	cout << endl;
	InOrder(root);
	cout << endl;
	PostOrder(root);
	cout << endl;
	LayerOrder(root);
	cout << endl;
	Leaf(root);
	cout << endl;
	cout << left_count << endl;*/
	int sum = 14;
	int result = hasPathSum1(root, sum);
	cout << result << endl;
	system("pause");
	return 0;
}
//建立二叉树
TreeNode* CreateBinaryTree(vector<string> data)
{
	queue<TreeNode*> q;
	if (data.size() == 0)
	{
		return NULL;
	}
	int temp;
	temp = atoi(data[0].c_str());
	TreeNode* root = new TreeNode(temp);
	TreeNode* parent = new TreeNode(0);
	q.push(root);
	for (int i = 1; i < data.size();)
	{
		parent = q.front();
		q.pop();
		if (data[i] != ".")
		{
			temp = atoi(data[i].c_str());
			TreeNode *left = new TreeNode(temp);
			parent->left = left;
			q.push(left);
		}
		i = i + 1;
		if (i == data.size())
		{
			break;
		}
		if (data[i] != ".")
		{
			temp = atoi(data[i].c_str());
			TreeNode *right = new TreeNode(temp);
			parent->right = right;
			q.push(right);
		}
		i = i + 1;
	}
	return root;
}
//前序遍历
void PreOrder(TreeNode* root)
{
	if (root != NULL)
	{
		cout << root->val << " ";
		PreOrder(root->left);
		PreOrder(root->right);
	}
}
//中序遍历
void InOrder(TreeNode* root)
{
	if (root != NULL)
	{
		InOrder(root->left);
		cout << root->val << " ";
		InOrder(root->right);
	}
}
//后序遍历
void PostOrder(TreeNode* root)
{
	if (root != NULL)
	{
		PostOrder(root->left);
		PostOrder(root->right);
		cout << root->val << " ";
	}
}
//层先遍历
void LayerOrder(TreeNode* root)
{
	queue<TreeNode*> q;
	TreeNode* temp = new TreeNode(0);
	q.push(root);
	while (q.empty() != true)
	{
		temp = q.front();
		q.pop();
		cout << temp->val << " ";
		if (temp->left != NULL)
		{
			q.push(temp->left);
		}
		if (temp->right != NULL)
		{
			q.push(temp->right);
		}
	}
}
//统计叶节点数目，输出叶节点
void Leaf(TreeNode* root)
{
	if (root != NULL)
	{
		if (root->left == NULL && root->right == NULL)
		{
			cout << root->val << " ";
			left_count++;
		}
		Leaf(root->left);
		Leaf(root->right);
	}
}
bool hasPathSum(TreeNode* root, int sum) 
{
	bool result = false;
	vector<int> path;
	myhasPathSum(root, path, sum, result);
	return result;
}
void myhasPathSum(TreeNode* root, vector<int> path, int sum, bool &flag)
{
	if (root != NULL && flag==false)
	{
		path.push_back(root->val);
		if (root->left == NULL && root->right == NULL)
		{
			int temp = 0;
			for (int i = 0; i < path.size(); i++)
			{
				temp = temp + path[i];
			}
			if (temp == sum)
			{
				flag = true;
			}
		}
		myhasPathSum(root->left, path, sum, flag);
		myhasPathSum(root->right, path, sum, flag);
	}
}
bool hasPathSum1(TreeNode* root, int sum)
{
	if (root == NULL)
	{
		return false;
	}
	else if (root->left == NULL && root->right == NULL && root->val == sum)
	{
		return true;
	}
	else
	{
		return hasPathSum1(root->left, sum - root->val) || hasPathSum1(root->right, sum - root->val);
	}
	return true;
}