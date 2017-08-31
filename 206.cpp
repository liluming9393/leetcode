//Reverse a singly linked list.
//Hint:
//A linked list can be reversed either iteratively or recursively.Could you implement both ?
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
ListNode* reverseList1(ListNode* head);
ListNode* reverseList2(ListNode* head);
int main()
{
	vector<int> data = { 5, 5, 3, 4, 5 };
	ListNode* head = CreateList(data);
	DispList(head);
	head = reverseList2(head);
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
ListNode* reverseList1(ListNode* head) 
{
	if (head == NULL)
	{
		return NULL;
	}
	ListNode*p = head;
	ListNode*q = p->next;
	if (q == NULL)
	{
		return p;
	}
	ListNode*r = q->next;
	if (r == NULL)
	{
		q->next = p;
		p->next = NULL;
		return q;
	}
	p->next = NULL;
	while (r != NULL)
	{
		q->next = p;
		p = q;
		q = r;
		r = r->next;
	}
	q->next = p;
	return q;
}
ListNode* reverseList2(ListNode* head)
{
	if (head == NULL)
	{
		return NULL;
	}
	if (head->next == NULL)
	{
		return head;
	}
	ListNode*p = head->next;
	ListNode*n = reverseList2(p);
	p->next = head;
	head->next = NULL;
	return n;
}