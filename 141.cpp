//Given a linked list, determine if it has a cycle in it.
//Follow up :
//Can you solve it without using extra space ?
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
bool hasCycle(ListNode *head);
int main()
{
	vector<int> data = { 5, 5, 3, 4, 5 };
	ListNode* head = CreateList(data);
	DispList(head);
	ListNode*p = head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	ListNode*q = head;
	q = q->next;
	q = q->next;
	p->next = q;
	bool result = hasCycle(head);
	cout << result << endl;
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
bool hasCycle(ListNode *head) 
{
	if (head == NULL)
	{
		return false;
	}
	if (head->next == NULL)
	{
		return false;
	}
	ListNode*slow = head;
	ListNode*fast = head;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast == NULL)
		{
			break;
		}
		fast = fast->next;
		if (slow == fast)
		{
			return true;
		}
		else
		{
			slow = slow->next;
		}
	}
	return false;
}