#include <stdio.h>
#include <stdlib.h>
typedef struct listNode *listPointer;
typedef struct listNode{
    int data;
    int index;
    listPointer right;
    listPointer left;
}node;
listPointer createnode()
{
    listPointer ptr = NULL;
    ptr=(listPointer)malloc(sizeof(node));
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}
listPointer root = NULL;
listPointer insert(listPointer root,int index)
{
    if(index/2 !=1)
    {
        listPointer ptr = insert(root,index / 2);
        if(index%2!=0)
        {
            if(ptr->right != NULL)
            {
                ptr = ptr->right;
            }
        }
        else
        {
            if(ptr->left != NULL)
            {
                ptr = ptr->left;
            }
        }
        return ptr;
    }
    else
    {
        if(index%2!=0)
        {
            if(root->right != NULL)
            {
                root = root->right;
            }
        }
        else
        {
            if(root->left != NULL)
            {
                root = root->left;
            }
        }
        return root;
    }
}
listPointer finddata(listPointer root,int data)
{
    if(root->data == data)
    {
        return root;
    }
    if(root->left != NULL && root->right != NULL)
    {
        listPointer leftc = finddata(root->left,data);
        listPointer rightc = finddata(root->right,data);
        if(leftc != NULL)
        {
            return leftc;
        }
        else if(rightc != NULL)
        {
            return rightc;
        }
        else
        {
            return NULL;
        }
    }
    else if(root->left != NULL)
    {
        listPointer leftc = finddata(root->left,data);
        if(leftc != NULL)
        {
            return leftc;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        return NULL;
    }
}
void print(listPointer root,int level)
{
    if(root->right!=NULL)
    {
        print(root->right,level+1);
    }
    printf("%*s%d\n",4*level,"",root->data);
    if(root->left!=NULL)
    {
        print(root->left,level+1);
    }
}
int main()
{
    listPointer temp,head;
    int user,data,index = 0;
    do
    {
        printf("0:add,1:find,2:print,3:exit\n");
        scanf("%d",&user);
        if(user == 0)
        {
            printf("input number");
            scanf("%d",&data);
            if(root == NULL)
            {
                root = createnode();
                root -> data = data;
                root -> index = ++index;
                head = root;
            }
            else
            {
            	temp = finddata(root,data);
            	if(temp == NULL)
            	{
            		root = head;
	                listPointer newnode = createnode();
	                newnode->data = data;
	                newnode->index = ++index;
	                temp = insert(root,newnode->index);
	                if(index%2==0)
	                {
	                    temp->left = newnode;
	                }
	                else
	                {
	                    temp->right = newnode;
	                }
				}
				else
				{
					printf("error\n");
				}
                
            }
        }
        else if(user == 1)
        {
            if(root == NULL)
            {
                printf("empty");
            }
            else
            {
                printf("input number");
                scanf("%d",&data);
                temp = finddata(root,data);
                if(temp == NULL)
                {
                    printf("not found");
                }
                else
                {
                    printf("find %d index:%d",data,temp->index);
                }
            }
            printf("\n");
        }
        else if(user == 2)
        {
            if(root == NULL)
            {
                printf("empty\n");
            }
            else
            {
                print(root,0);
            }
        }
    }
    while(user!=3);
    return 0;
}
