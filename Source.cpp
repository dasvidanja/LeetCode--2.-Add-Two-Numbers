/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.


*/
// LeetCode
#include <iostream>
#include <string>
using namespace std;

struct node {

	int data;
	node * next;

};


//Create one linked list
//Be able to print the elements back and fouth 
//Attempt problem   
int main()
{
	//Create new element
	//lists
	node *listOne = new node();
	listOne->data = 9;

	node *listTwo = new node();
	listTwo->data = 0;

	//First element
	node* head;
	head = listOne;

	node* head2;
	head2 = listTwo;

	//Place holder for last element 
	node * tail;
	tail = listOne;
	tail->next = NULL;

	node * tail2;
	tail2 = listTwo;
	tail2->next = NULL;

	//Populate list with additional elements

	//List one 
	node * tampa = new node();
	tampa->data = 1;
	tail->next = tampa;
	tail = tail->next;

	//List one 
	node * tampa2 = new node();
	tampa2->data = 6;
	tail->next = tampa2;
	tail = tail->next;


	////List two
	//node * tampa22 = new node();
	//tampa22->data = 4;
	//tail2->next = tampa22;
	//tail2 = tail2->next;

	//   //List two
	//   node * tampa23 = new node();
	//   tampa23->data = 3;
	//   tail2->next = tampa23;
	//   tail2 = tail2->next;


	//Find out number of nodes for list1
	int counter = 0;
	node * temp;
	temp = head;

	while (temp != NULL) {
		counter++;
		temp = temp->next;
	}

	temp = head;
	cout << "Total number of L11 elements: " << counter << endl;

	//Find out number of nodes for list2
	int counter2 = 0;
	node * temp2 = new node();
	temp2 = head2;

	while (temp2 != NULL) {
		counter2++;
		temp2 = temp2->next;
	}



	temp2 = head2;
	cout << "Total number of L2 elements: " << counter2 << endl;

	//Reverse contents of list 1
	//Loop n times (total number of nodes)
	//Go to last elemen, last -1, last -2, last-3 ,  .....
	int position = counter - 1;
	int keep = 0;
	int foo[50];

	for (int i = 0; i< counter; i++) {

		while (keep != position) {
			temp = temp->next;
			keep++;
		}


		foo[i] = temp->data;
		keep = 0;
		temp = head;
		position--;

	}

	//Reverse contents of list 2   
	int position2 = counter2 - 1;
	int keep2 = 0;
	int foo2[50];

	for (int i = 0; i< counter2; i++) {

		while (keep2 != position2) {

			temp2 = temp2->next;
			keep2++;
		}


		foo2[i] = temp2->data;
		keep2 = 0;
		temp2 = head2;
		position2--;
	}


	//Print put L1 in reverse
	cout << "L1 " << endl;
	for (int i = 0; i<counter; i++) {

		cout << foo[i] << " ";

	}
	cout << " " << endl;

	//Print put L2 in reverse 
	cout << "L2" << endl;
	for (int i = 0; i<counter2; i++) {

		cout << foo2[i] << " ";

	}

	cout << " " << endl;


	//Print Original list1 content
	cout << "Actual List" << endl;
	node *temporary = new node();
	temporary = head;

	while (temporary != NULL) {
		cout << temporary->data << " ";
		temporary = temporary->next;
	}
	cout << " " << endl;

	//Print Original list2 content
	cout << "Actual List2" << endl;
	node *temporary2 = new node();
	temporary2 = head2;

	while (temporary2 != NULL) {
		cout << temporary2->data << " ";
		temporary2 = temporary2->next;
	}

	//Wouldn't it make more sense to check if they have same lenght
	//if yes compare last and last 
	//if greater than 10
	//if different size, 

	bool flag = false;
	
	int foo3[100];


	if (counter2> counter) {
		foo3[counter2 + 1];
	}else {
		foo3[counter+1];
	}



	//Same lenght
	if (counter == counter2) {
		for (int i = counter - 1; i >= 0; i--) {
			int r;


			if (flag == false) {
				r = foo[i] + foo2[i];

			}
			else {
				r = foo[i] + foo2[i] + 1;
				flag = false;
			}


			if (r>9) {
				foo3[i + 1] = r % 10;
				flag = true;


			}
			else {

				foo3[i + 1] = r;
			}
		}


		if (flag == true) {
			foo3[0] = 1;
		}
		else {
			foo3[0] = 0;
		}
	}

	//Different Length
	if (counter>counter2) {
		int min = 0;
		int z = counter2 - 1;
		for (int i = counter - 1; i >= 0; i--) {
			int r;

			if (flag == false) {
				//if we are out of bound do not add foo2
				if (min >=counter2) {
					r = foo[i];
				}
				else {
					r = foo[i] + foo2[z];
				}
			}
			else {
				if (min >=counter2) {
					r = foo[i] + 1;
				}
				else {
					r = foo[i] + foo2[z] + 1;
				}

				//r = foo[i] + foo2[i] + 1;
				flag = false;
			}

			cout << "R is" << r << endl;

			if (r>9) {
				foo3[i + 1] = r % 10;
				flag = true;

			}
			else {

				foo3[i + 1] = r;
			}
			min++;
			z--;
		}


		if (flag == true) {
			foo3[0] = 1;
		}
		else {
			foo3[0] = 0;
		}


	}

	//Different length scenario 2
	if (counter2>counter) {
		int min = 0;
		int z = counter - 1;
		for (int i = counter2 - 1; i >= 0; i--) {
			int r;

			if (flag == false) {
				//if we are out of bound do not add foo2
				if (min >= counter) {
					r = foo2[i];
				}
				else {
					r = foo[z] + foo2[i];
				}
			}
			else {
				if (min >= counter) {
					r = foo2[i] + 1;
				}
				else {
					r = foo[z] + foo2[i] + 1;
				}

				//r = foo[i] + foo2[i] + 1;
				flag = false;
			}

			cout << "R is" << r << endl;

			if (r>9) {
				foo3[i + 1] = r % 10;
				flag = true;

			}
			else {

				foo3[i + 1] = r;
			}
			min++;
			z--;
		}


		if (flag == true) {
			foo3[0] = 1;
		}
		else {
			foo3[0] = 0;
		}


	}




	//Print

	if (flag == false) {
		for (int i = 1; i< counter + 1; i++) {

			cout << foo3[i] << " ";
		}
	}
	if (flag == true) {
		for (int i = 0; i< counter + 1; i++) {

			cout << foo3[i] << " ";
		}

	}

	//NOW PUT ON A LINKED LIST 
	node *start = new node();
	node *end = new node();
	start = NULL;
	end = NULL;

	//Insert into a  new List
	if (counter2 > counter) {
		counter = counter2;
	}
	for (int i = counter; i>0; i--) {
		node * temp = new node();
		temp->data = foo3[i];

		if (start == NULL) {
			start = temp;
			end = start;

		}
		else {
			end->next = temp;
			end = end->next;

		}

	}
	cout << " final result" << endl;

	//Print List   
	while (start != NULL) {
		cout << start->data;
		start = start->next;
	}

}
//SOLUTION PROVIDED ON CODE LEET
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

		//First element
		ListNode* head;
		head = l1;

		//Second element
		ListNode* head2;
		head2 = l2;

		//Place holder for last element 
		ListNode * tail;
		tail = l1;
		tail->next = l1->next;

		ListNode * tail2;
		tail2 = l2;
		tail2->next = l2->next;

		//Find size  l1
		//Find out number of nodes for list1
		int counter = 0;

		while (tail != NULL) {
			counter++;

			tail = tail->next;
		}

		ListNode * temp;
		temp = head;

		//Find out number of nodes for list2
		int counter2 = 0;


		while (tail2 != NULL) {
			counter2++;
			tail2 = tail2->next;
		}

		ListNode * temp2;
		temp2 = head2;
		temp2 = head2;

		//reverse contents
		int position = counter - 1;
		int keep = 0;
		int foo[100];

		for (int i = 0; i< counter; i++) {
			while (keep != position) {
				temp = temp->next;
				keep++;
			}

			foo[i] = temp->val;
			keep = 0;
			temp = head;
			position--;

		}

		//Reverse contents of list 2   
		int position2 = counter2 - 1;
		int keep2 = 0;
		int foo2[100];
		for (int i = 0; i< counter2; i++) {
			while (keep2 != position2) {
				temp2 = temp2->next;
				keep2++;
			}

			foo2[i] = temp2->val;
			keep2 = 0;
			temp2 = head2;
			position2--;
		}


		bool flag = false;
		int foo3[100];

		if (counter2> counter) {
			foo3[counter2 + 1];
		}

		//Same size 
		if (counter == counter2) {
			for (int i = counter - 1; i >= 0; i--) {
				int r;

				if (flag == false) {
					r = foo[i] + foo2[i];
				}
				else {
					r = foo[i] + foo2[i] + 1;
					flag = false;
				}
				if (r>9) {
					foo3[i + 1] = r % 10;
					flag = true;

				}
				else {
					foo3[i + 1] = r;
				}
			}
			if (flag == true) {
				foo3[0] = 1;
			}
			else {
				foo3[0] = 0;
			}

		}

		//different size (working on it)


		//Check if size is the same,but last addtion > 9 (carries a one)    


		///////////////////////
		//Different Length
		if (counter>counter2) {
			int min = 0;
			int z = counter2 - 1;
			for (int i = counter - 1; i >= 0; i--) {
				int r;

				if (flag == false) {
					//if we are out of bound do not add foo2
					if (min >= counter2) {
						r = foo[i];
					}
					else {
						r = foo[i] + foo2[z];
					}
				}
				else {
					if (min >= counter2) {
						r = foo[i] + 1;
					}
					else {
						r = foo[i] + foo2[z] + 1;
					}

					flag = false;
				}
				if (r>9) {
					foo3[i + 1] = r % 10;
					flag = true;

				}
				else {

					foo3[i + 1] = r;
				}
				min++;
				z--;
			}


			if (flag == true) {
				foo3[0] = 1;
			}
			else {
				foo3[0] = 0;
			}


		}

		//Different length scenario 2
		if (counter2>counter) {
			int min = 0;
			int z = counter - 1;
			for (int i = counter2 - 1; i >= 0; i--) {
				int r;

				if (flag == false) {
					//if we are out of bound do not add foo2
					if (min >= counter) {
						r = foo2[i];
					}
					else {
						r = foo[z] + foo2[i];
					}
				}
				else {
					if (min >= counter) {
						r = foo2[i] + 1;
					}
					else {
						r = foo[z] + foo2[i] + 1;
					}


					flag = false;
				}



				if (r>9) {
					foo3[i + 1] = r % 10;
					flag = true;

				}
				else {

					foo3[i + 1] = r;
				}
				min++;
				z--;
			}


			if (flag == true) {
				foo3[0] = 1;
			}
			else {
				foo3[0] = 0;
			}


		}

		//Insert into a  new List
		if (counter2 > counter) {
			counter = counter2;
		}
		//NOW PUT ON A LINKED LIST 
		ListNode *start;
		ListNode *end;
		start = NULL;

		if (flag == true) {
			//Insert into a  new List
			for (int i = counter; i >= 0; i--) {
				ListNode * temp = new ListNode(foo3[i]);

				if (start == NULL) {
					start = temp;
					end = start;

				}
				else {
					end->next = temp;
					end = end->next;

				}

			}
		}
		if (flag == false) {

			//Insert into a  new List
			for (int i = counter; i>0; i--) {
				ListNode * temp = new ListNode(foo3[i]);

				if (start == NULL) {
					start = temp;
					end = start;

				}
				else {
					end->next = temp;
					end = end->next;

				}

			}


		}

		return start;
	}

};
