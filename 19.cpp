/*Given a linked list, remove the nth node from the end of list and return its head.
For example,
Given linked list : 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.
Note :
	 Given n will always be valid.
	 Try to do this in one pass.*/
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
ListNode* removeNthFromEnd1(ListNode* head, int n);
ListNode* removeNthFromEnd2(ListNode* head, int n);

int main()
{
	vector<int> data = { 1, 2, 3, 4, 5 };
	ListNode* head = CreateList(data);
	DispList(head);
	head = removeNthFromEnd2(head, 1);
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
ListNode* removeNthFromEnd1(ListNode* head, int n)
{
	int length = 0;
	ListNode*p = head;
	while (p != NULL)
	{
		length++;
		p = p->next;
	}
	if (n == length)
	{
		return head->next;
	}
	else
	{
		p = head;
		int count = 1;
		while (count < (length - n))
		{
			p = p->next;
			count++;
		}
		p->next = p->next->next;
	}
	return head;
}
ListNode* removeNthFromEnd2(ListNode* head, int n)
{
	ListNode*p = head;
	ListNode*q = head;
	int count = 1;
	while (count <= n)
	{
		p = p->next;
		count++;
	}
	if (p == NULL)
	{
		return head->next;
	}
	while (p->next != NULL)
	{
		p = p->next;
		q = q->next;
	}
	q->next = q->next->next;
	return head;
}