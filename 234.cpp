//Given a singly linked list, determine if it is a palindrome.
//Follow up :
//Could you do it in O(n) time and O(1) space ?
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
bool isPalindrome1(ListNode* head);
bool isPalindrome2(ListNode* head);
ListNode* reverseList(ListNode* head, ListNode* slow);//翻转slow之前的链表
int main()
{
	vector<int> data = { 5, 4, 3, 4, 5 };
	ListNode* head = CreateList(data);
	DispList(head);
	bool result = isPalindrome2(head);
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
bool isPalindrome1(ListNode* head) 
{
	if (head == NULL)
	{
		return true;
	}
	if (head->next == NULL)
	{
		return true;
	}
	ListNode*slow = head;
	ListNode*fast = head;
	int flag = 0;//0表示链表奇数个，1表示偶数个
	while (1)
	{
		slow = slow->next;
		fast = fast->next;
		if (fast->next == NULL)
		{
			flag = 1;
			break;
		}
		fast = fast->next;
		if (fast->next == NULL)
		{
			flag = 0;
			break;
		}
	}
	//翻转slow之前的链表
	head = reverseList(head, slow);
	ListNode*p = head;
	ListNode*q = slow;
	if (flag == 0)
	{
		q = slow->next;
	}
	else if (flag == 1)
	{
		q = slow;
	}
	while (q != NULL)
	{
		if (p->val != q->val)
		{
			return false;
		}
		p = p->next;
		q = q->next;
	}
	return true;
}
ListNode* reverseList(ListNode* head, ListNode* slow)//翻转slow之前的链表
{
	if (head == NULL)
	{
		return NULL;
	}
	if (head->next == slow)
	{
		return head;
	}
	ListNode*p = head->next;
	ListNode*n = reverseList(p,slow);
	p->next = head;
	head->next = slow;
	return n;
}
bool isPalindrome2(ListNode* head)
{
	if (head == NULL)
	{
		return true;
	}
	if (head->next == NULL)
	{
		return true;
	}
	vector<int> data;
	while (head != NULL)
	{
		data.push_back(head->val);
		head = head->next;
	}
	for (int i = 0; i < data.size() / 2; i++)
	{
		if (data[i] != data[data.size() - 1 -i])
		{
			return false;
		}
	}
	return true;
}