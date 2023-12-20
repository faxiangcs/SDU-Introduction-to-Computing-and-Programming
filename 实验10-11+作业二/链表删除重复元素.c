#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void deleteDuplicates(struct ListNode *head);

int main() {
    int amount;
    struct ListNode *head, *temp;
    scanf("%d", &amount);
    for (int i = 0; i < amount; i++) {
        struct ListNode *input = (struct ListNode *) malloc(sizeof(struct ListNode));
        scanf("%d", &(input->val));

        if (i == 0) {
            head = input;
            temp = head;
        } else {
            temp->next = input;
            temp = temp->next;
        }

        if (i == amount - 1)
            temp->next = NULL;
    }

    deleteDuplicates(head);

    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
}

void deleteDuplicates(struct ListNode *head)
 { 
    struct ListNode *p1=head,*p2=head->next; 
	while(p2->next!=NULL) 
	{ if(p1->val==p2->val)       
	    {   p2=p2->next; 
		    p1->next=p2; 
		} 
		else if(p1->val!=p2->val) 
		{   p1=p2; 
		    p2=p2->next;
		} 	 
	} 
	if(p2!=NULL) 
	{ 
	    if(p2->val==p1->val) 
	        p1->next=NULL; 
	} 
}
    
    
