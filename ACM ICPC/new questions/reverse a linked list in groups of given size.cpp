/*Reverse a Linked List in groups of given size
Given a linked list, write a function to reverse every k nodes (where k is an input to the function). 

Example:
Inputs:  1->2->3->4->5->6->7->8->NULL and k = 3 
Output:  3->2->1->6->5->4->8->7->NULL. 


Algorithm: reverse(head, k)
1) Reverse the first sub-list of size k. While reversing keep track of the next node and previous node. 
Let the pointer to the next node be next and pointer to the previous node be prev. See this post for reversing a linked list.
2) head->next = reverse(next, k) // Recursively call for rest of the list and link the two sub-lists 
3) return prev // prev becomes the new head of the list (see the diagrams of iterative method of this post) */

void reverse(Node *head, int K) {

	Node *curr = head;
	Node *next = NULL, *prev = NULL;
	int cnt = 0;

	while(curr != NULL and cnt < K) {

		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	if(next != NULL)
		head->next = reverse(next, K);

	return prev;
}