#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
	char data;
	struct node* next;
};
void reverse(struct node **);
bool compareLists(struct node *, struct node *);


void push(struct node** head_ref,char data)
{
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node-> data = data;
	new_node-> next = *head_ref;
	*head_ref = new_node;
}

void printList(struct node* ptr)
{
	while(ptr)
	{
		printf("%c",ptr->data);
		ptr= ptr->next;
	}
	printf("NULL\n");
}

bool isPalindrome(struct node* head)
{
	struct node* fast_ptr = head;
	struct node* slow_ptr = head;
	struct node *mid_ptr =head,*second_half, *prev_of_slow_ptr = head;
	struct node* mid_node =NULL;
	bool res;
	if(head!=NULL && head->next !=NULL)
	{
		while(fast_ptr!=NULL && fast_ptr->next!=NULL)
		{
			fast_ptr = fast_ptr->next->next;
			prev_of_slow_ptr = slow_ptr;
			slow_ptr = slow_ptr->next;
		}
		char c = slow_ptr->data ;
		printf("The middle element is [%c]\n\n",c );
	
		if(fast_ptr !=NULL)
		{
			/* case of odd number of characters : store mid element for future 
			and increment slow_ptr*/
			mid_node = slow_ptr;
			slow_ptr = slow_ptr->next;
		}
	 	// Now reverse the second half and compare it with first half
        second_half = slow_ptr;
        prev_of_slow_ptr->next = NULL; // NULL terminate first half
        reverse(&second_half);  // Reverse the second half
        res = compareLists(head, second_half); // compare
        printf("%d\n",res );
	}
    return res;
}

bool compareLists(struct node* head,struct node* prev_of_slow_ptr)
{
	struct node *temp1 = head,*temp2 = prev_of_slow_ptr;
	while (temp1 && temp2)
    {
        if (temp1->data == temp2->data)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else return 0;
    }
 
    /* Both are empty reurn 1*/
    if (temp1 == NULL && temp2 == NULL)
        return 1;
 
    /* Will reach here when one is NULL
      and other is not */
    return 0;
}

void reverse(struct node **start)
{
	struct node * temp = *start,*prev = NULL;
	struct node* next;

	while(temp!= NULL)
	{
		next = temp->next;
		temp->next = prev;
		prev = temp;
		temp = next;
	}
	*start = prev;
}

int main()
{
	char str[] = "harshihsrah";
	struct node* head =NULL;
	int i;
	for(i=0;str[i]!='\0';i++)
	{
		push(&head,str[i]);
	}
	printList(head);
	isPalindrome(head);

	return 0;
}
