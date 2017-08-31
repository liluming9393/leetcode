//Given a sorted linked list, delete all duplicates such that each element appear only once.
//For example,
//Given 1->1->2, return 1->2.
//Given 1->1->2->3->3, return 1->2->3.
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
ListNode* deleteDuplicates1(ListNode* head);
ListNode* deleteDuplicates2(ListNode* head);
int main()
{
	vector<int> data = { 1, 1, 3, 4, 4 };
	ListNode* head = CreateList(data);
	DispList(head);
	head = deleteDuplicates2(head);
	DispList(head);
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
ListNode* deleteDuplicates1(ListNode* head) 
{
	if (head == NULL)
	{
		return NULL;
	}
	ListNode*p = head;
	while (p->next != NULL)
	{
		if (p->val == p->next->val)
		{
			p->next = p->next->next;
		}
		else
		{
			p = p->next;
		}
	}
	return head;
}
ListNode* deleteDuplicates2(ListNode* head)
{
	if (head == NULL)
	{
		return NULL;
	}
	ListNode*result = new ListNode(head->val);
	ListNode*p = head->next;
	ListNode*q = result;
	while (p != NULL)
	{
		if (p->val != q->val)
		{
			q->next = p;
			p = p->next;
			q = q->next;
		}
		else
		{
			p = p->next;
		}
	}
	q->next = NULL;
	return result;
}