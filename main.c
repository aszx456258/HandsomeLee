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
int main()
{
    int user,num,newnumber;
    listPointer head = NULL;
    do
    {
        printf("1:穝糤计 2:э计 3:础计 4:埃计 5:场 6:瞒秨\n");
        scanf("%d",&user);
        listPointer ptr = head;
        if(user == 1)
        {
            printf("input number");
            scanf("%d",&num);
            if(head!=NULL)
            {
                listPointer newptr = creatnode();
                while(ptr->link != NULL)
                {
                    ptr = ptr->link;
                }
                ptr->link = newptr;
                ptr->link->data = num;
            }
            else
            {
                listPointer newptr = creatnode();
                head = newptr;
                head->data = num;
            }
        }
        else if(user == 2)
        {
            printf("璶э计:\n");
            scanf("%d",&num);
            printf("穝计:\n");
            scanf("%d",&newnumber);
            while(ptr!=NULL)
            {
                if(ptr->data == num)
                {
                    ptr->data = newnumber;
                    break;
                }
                ptr = ptr->link;
            }
            if(ptr==NULL)
            {
                printf("计ぃ﹃ず\n");
            }
        }
        else if(user == 3)
        {
            printf("璶础计:\n");
            scanf("%d",&newnumber);
            printf("璶础计:\n");
            scanf("%d",&num);
            listPointer newptr = creatnode();
            while(ptr!=NULL)
            {
                if(ptr->data == num)
                {
                    listPointer ptr2 = ptr->link;
                    ptr->link = newptr;
                    newptr->link = ptr2;
                    newptr->data = newnumber;
                    break;
                }
                ptr = ptr->link;
            }
            if(ptr==NULL)
            {
                printf("计ぃ﹃ず\n");
            }
        }
        else if(user == 4)
        {
            int flag=0;
            printf("璶埃计:\n");
            scanf("%d",&num);
            listPointer ptr2 = NULL;
            if(num == head->data)
            {
                head = head->link;
                free(ptr);
                flag=1;
            }
            else
            {
                ptr = ptr->link;
                ptr2 = head;
                while(ptr!=NULL)
                {
                    if(ptr->data == num)
                    {
                        if(ptr->link == NULL)
                        {
                            ptr2->link = NULL;
                            free(ptr);
                        }
                        else
                        {
                            listPointer delptr = ptr;
                            ptr = ptr->link;
                            ptr2->link = ptr;
                            free(delptr);
                        }
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
        else if(user == 5)
        {
            while(ptr!=NULL)
            {
                printf("%d\n",ptr->data);
                ptr = ptr->link;
            }
        }
    }
    while(user!=6);
    return 0;
}
