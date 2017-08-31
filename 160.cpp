/*Write a program to find the node at which the intersection of two singly linked lists begins.
For example, the following two linked lists :
A :		a1 ¡ú a2
				¨K
					c1 ¡ú c2 ¡ú c3
				¨J
B : b1 ¡ú b2 ¡ú b3
	begin to intersect at node c1.
Notes :
	  If the two linked lists have no intersection at all, return null.
	  The linked lists must retain their original structure after the function returns.
	  You may assume there are no cycles anywhere in the entire linked structure.
	  Your code should preferably run in O(n) time and use only O(1) memory.*/
#include<iostream>
#include<stdint.h>
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
ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB);
ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB);
int main()
{
	vector<int> data1 = { 1, 2, 3, 4, 5 };
	ListNode* headA = CreateList(data1);
	DispList(headA);
	ListNode*p = headA;
	p = p->next;
	p = p->next;
	vector<int> data2 = { 6, 7, 8 };
	ListNode* headB = CreateList(data2);
	ListNode* q = headB;
	q = q->next;
	q = q->next;
	q->next = p;
	DispList(headB);
	ListNode* result = getIntersectionNode2(headA, headB);
	if (result != NULL)
	{
		cout << result->val << endl;

	}
	else
	{
		cout << "NULL" << endl;
	}
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
ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) 
{
	ListNode*p = headA;
	ListNode*q = headB;
	while (p != NULL)
	{
		q = headB;
		while (q != NULL)
		{
			if (p == q)
			{
				return p;
			}
			else
			{
				q = q->next;
			}
		}
		p = p->next;
	}
	return NULL;
}
ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB)
{
	ListNode*p = headA;
	ListNode*q = headB;
	int lengthA = 0;
	int lengthB = 0;
	while (p != NULL)
	{
		lengthA++;
		p = p->next;
	}
	while (q != NULL)
	{
		lengthB++;
		q = q->next;
	}
	ListNode* longlist = headA;
	ListNode* shortlist = headB;
	int count = lengthA - lengthB;
	if (lengthA < lengthB)
	{
		longlist = headB;
		shortlist = headA;
		count = lengthB - lengthA;
	}
	for (int i = 0; i < count; i++)
	{
		longlist = longlist->next;
	}
	while (longlist != NULL)
	{
		if (longlist == shortlist)
		{
			return longlist;
		}
		else
		{
			longlist = longlist->next;
			shortlist = shortlist->next;
		}
	}
	return NULL;
}