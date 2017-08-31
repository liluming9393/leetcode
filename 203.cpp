//Remove all elements from a linked list of integers that have value val.
//Example
//Given : 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
//Return: 1 --> 2 --> 3 --> 4 --> 5
//Write a function to delete a node(except the tail) in a singly linked list, given only access to that node.
//Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
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
ListNode* removeElements(ListNode* head, int val);
int main()
{
	vector<int> data = { 5, 5, 3, 4, 5 };
	ListNode* head = CreateList(data);
	DispList(head);
	head = removeElements(head, 5);
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
ListNode* removeElements(ListNode* head, int val) 
{
	ListNode* myhead = new ListNode(0);
	myhead->next = head;
	ListNode* p = myhead;
	while (p->next != NULL)
	{
		if (p->next->val == val)
		{
			p->next = p->next->next;
		}
		else
		{
			p = p->next;
		}
	}
	return myhead->next;
}