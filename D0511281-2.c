#include <stdio.h>
#include <stdlib.h>
typedef struct listNode *listPointer;
typedef struct listNode{
    int data;
    listPointer link;
};
listPointer creatnode()
{
    struct listNode a;
    listPointer ptr = NULL;
    ptr=(listPointer)malloc(sizeof(a));
    ptr->link = NULL;
    return ptr;
}
listPointer head = NULL,ptr;
int user,num,newnumber;
void add(int *num)
{
    if(head!=NULL)
    {
        listPointer newptr = creatnode();
        ptr = ptr->link;
        listPointer ptr2 = head;
        if(ptr==NULL)
        {
            if(*num>ptr2->data)
            {
                ptr2->link = newptr;
                ptr2->link->data = *num;
            }
            else if(*num<ptr2->data)
            {
                listPointer newptr = creatnode();
                newptr->link = head;
                head = newptr;
                head->data = *num;
            }
            else
            {
                printf("error\n");
            }
        }
        else
        {
            while(ptr!= NULL)
            {
                if(*num>ptr->data&&ptr->link == NULL)
                {
                    ptr->link = newptr;
                    ptr->link->data = *num;
                    break;
                }
                else if(*num>ptr2->data&&*num<ptr->data)
                {
                    ptr2->link = newptr;
                    ptr2->link->link = ptr;
                    ptr2->link->data=*num;
                    break;
                }
                else if(*num<ptr2->data&&ptr2== head)
                {
                    listPointer newptr = creatnode();
                    newptr->link = head;
                    head = newptr;
                    head->data = *num;
                    break;
                }
                else if(*num == ptr->data || *num == ptr2->data)
                {
                    printf("error\n");
                    break;
                }
                ptr = ptr->link;
                ptr2 = ptr2->link;
            }
        }
    }
    else
    {
        listPointer newptr = creatnode();
        head = newptr;
        head->data = *num;
    }
}
void del(int *num)
{
	int flag=0;
	if(head!=NULL)
	{
	    if(*num == head->data)
        {
            head = head->link;
            free(ptr);
            flag=1;
        }
        else
        {
            ptr = ptr->link;
            listPointer ptr2 = head;
            while(ptr!=NULL)
            {
                if(ptr->data == *num && ptr->link == NULL)
                {
                    ptr2->link = NULL;
                    free(ptr);
                    flag=1;
                    break;
                }
                else if(ptr->data == *num)
                {
                    listPointer delptr = ptr;
                    ptr2 -> link = ptr->link;
                    free(delptr);
                    flag=1;
                    break;
                }
                ptr = ptr->link;
                ptr2 = ptr2->link;
            }
            if(flag==0)
            {
                printf("计ぃ﹃ず\n");
            }
        }
	}
	else
	{
		printf("empty\n");
	}
}
int main()
{
    do
    {
        printf("1:穝糤计 2:э计 3:埃计 4:场 5:瞒秨\n");
        scanf("%d",&user);
        ptr = head;
        if(user == 1)
        {
        	printf("璶穝糤计");
        	scanf("%d",&num);
            add(&num);
        }
        else if(user == 2)
        {
            int flag = 0,num2,turn = 0;
            if(head!=NULL)
            {
                printf("璶э计:");
                scanf("%d",&num);
                printf("穝计:");
                scanf("%d",&num2);
                while(ptr!=NULL)
	            {
	                if(ptr->data == num2)
	                {
	                	turn = 1;
	                	break;
					}
	                ptr = ptr->link;
	            }
	            ptr = head;
	            if(turn==1)
	            {
	            	printf("error\n");
	            	continue;
				}
				del(&num);
				ptr = head;
				add(&num2);
	    	}
	    	else
	    	{
	    		printf("empty\n");
			}
        }
        else if(user == 3)
        {
        	printf("璶埃计:");
        	scanf("%d",&num);
            del(&num);
    	}
        else if(user == 4)
        {
        	if(head==NULL)
        	{
        		printf("empty");
			}
			else
			{
				while(ptr!=NULL)
	            {
	                printf("%d ",ptr->data);
	                ptr = ptr->link;
	            }
			}
			printf("\n");
        }
    }
    while(user!=5);
    return 0;
}
