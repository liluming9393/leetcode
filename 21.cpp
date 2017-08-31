//Merge two sorted linked lists and return it as a new list.The new list should be made by splicing together the nodes of the first two lists.
#include<iostream>
#include <stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode* CreateList(vector<int> &data);
void DispList(ListNode* head);
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
int main()
{
	vector<int> data1 = { 1, 2, 2, 4, 9 };
	ListNode* l1 = CreateList(data1);
	DispList(l1);
	vector<int> data2 = { 2, 3, 3, 7, 8 };
	ListNode* l2 = CreateList(data2);
	DispList(l2);
	ListNode* result = mergeTwoLists(l1, l2);
	DispList(result);
	system("pause");
	return 0;
}
ListNode* CreateList(vector<int> &data)
{
	ListNode *head = new ListNode(data[0]);
	ListNode *p = head;
	for (int i = 1; i < data.size(); i++)
	{
		ListNode *temp = new ListNode(data[i]);
		p->next = temp;
		p = p->next;
	}
	p->next = NULL;
	return head;
}
void DispList(ListNode* head)
{
	ListNode *p = head;
	while (p != NULL)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	if (l1 == NULL && l2 == NULL)
	{
		return NULL;
	}
	if (l1 == NULL)
	{
		return l2;
	}
	if (l2 == NULL)
	{
		return l1;
	}
	ListNode*result;
	if (l1->val >= l2->val)
	{
		result = l2;
		l2 = l2->next;
	}
	else
	{
		result = l1;
		l1 = l1->next;
	}
	ListNode*p = result;
	while (l1 != NULL && l2 != NULL)
	{
		if (l1->val >= l2->val)
		{
			p->next = l2;
			p = p->next;
			l2 = l2->next;
		}
		else
		{
			p->next = l1;
			p = p->next;
			l1 = l1->next;
		}
	}
	if (l1 == NULL)
	{
		p->next = l2;
	}
	else
	{
		p->next = l1;
	}
	return result;
}