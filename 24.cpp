//Given a linked list, swap every two adjacent nodes and return its head.
//For example,
//Given 1->2->3->4, you should return the list as 2->1->4->3.
//Your algorithm should use only constant space.You may not modify the values in the list, only nodes itself can be changed.
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
ListNode* swapPairs(ListNode* head);
int main()
{
	vector<int> data = { 5, 6, 3, 4, 5 };
	ListNode* head = CreateList(data);
	DispList(head);
	head = swapPairs(head);
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
ListNode* swapPairs(ListNode* head) 
{
	if (head == NULL)
	{
		return NULL;
	}
	if (head->next == NULL)
	{
		return head;
	}
	ListNode*p = head;
	ListNode*q = p->next;
	ListNode*r = new ListNode(0);
	head = q;
	while (1)
	{
		p->next = q->next;
		q->next = p;
		r->next = q;
		r = p;
		if (p->next == NULL)
		{
			break;
		}
		p = p->next;
		if (p->next == NULL)
		{
			break;
		}
		q = p->next;
	}
	return head;
}