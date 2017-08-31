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
void deleteNode(ListNode* node);
ListNode* CreateList(vector<int> &data);
void DispList(ListNode* head);
int main()
{
	vector<int> data = { 1, 2, 3, 4, 5 };
	ListNode* head = CreateList(data);
	DispList(head);
	ListNode *p = head->next;
	p = p->next;
	deleteNode(p);
	DispList(head);
	system("pause");
	return 0;
}
ListNode* CreateList(vector<int> &data)
{
	ListNode *head = new ListNode(0);
	ListNode *p = head;
	for (int i = 0; i < data.size(); i++)
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
	ListNode *p = head->next;
	while (p != NULL)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}
void deleteNode(ListNode* node) 
{
	node->val = node->next->val;
	node->next = node->next->next;
}