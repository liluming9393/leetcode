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
vector<vector<int>> levelOrderBottom(TreeNode* root);
void Display_2DVector(vector<vector<int>> &data);
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
	vector<vector<int>> result = levelOrderBottom(root);
	Display_2DVector(result);
	system("pause");
	return 0;
}
void Display_2DVector(vector<vector<int>> &data)
{
	for (int i = 0; i < data.size(); i++)
	{
		for (int j = 0; j < data[i].size(); j++)
		{
			cout << data[i][j] << " ";
		}
		cout << endl;
	}
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
vector<vector<int>> levelOrderBottom(TreeNode* root)
{
	queue<pair<TreeNode*, int>> q;
	pair<TreeNode*, int> temp;
	pair<TreeNode*, int> out;
	vector<vector<int>> result;
	if (root != NULL)
	{
		temp.first = root;
		temp.second = 0;
		q.push(temp);
		while (q.empty() == false)
		{
			out = q.front();
			int i = out.second + 1;
			if (result.size() < i)
			{
				result.resize(i);
			}
			result[i - 1].push_back(out.first->val);
			q.pop();
			if (out.first->left != NULL)
			{
				temp.first = out.first->left;
				temp.second = out.second + 1;
				q.push(temp);
			}
			if (out.first->right != NULL)
			{
				temp.first = out.first->right;
				temp.second = out.second + 1;
				q.push(temp);
			}
		}
		for (int k = 0; k < result.size() / 2; k++)
		{
			swap(result[k], result[result.size() - 1 - k]);
		}
	}
	return result;
}