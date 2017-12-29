#include <stdio.h>
#include <stdlib.h>
typedef struct listNode *listPointer;
typedef struct listNode{
    int data;
    int index;
    listPointer right;
    listPointer left;
    listPointer parent;
}node;
listPointer createnode()
{
    listPointer ptr = NULL;
    ptr=(listPointer)malloc(sizeof(node));
    ptr->left = NULL;
    ptr->right = NULL;
    ptr->parent = NULL;
    return ptr;
}
void check(listPointer root)
{
    if(root->parent != NULL) //���W�ˬd
    {
        listPointer p = root->parent;
        if(root->data > p->data) //�W���root�p
        {
            int temp = root->data;
            root->data = p->data;
            p->data = temp;
            check(p);
        }
    }
    if(root->left != NULL && root->right != NULL) //���U�ˬd ���l�k�l����
    {
        listPointer leftc = root->left;
        listPointer rightc = root->right;
        if(leftc->data > rightc->data) //���l��k�l�j
        {
            if(root->data < leftc->data) //�U���root�j
            {
                int temp = root->data;
                root->data = leftc->data;
                leftc->data = temp;
            }
        }
        else//���l��k�l�p
        {
            if(root->data < rightc->data) //�U���root�j
            {
                int temp = root->data;
                root->data = rightc->data;
                rightc->data = temp;
            }
        }
    }
    else if(root->left != NULL && root->right == NULL) //�u�����l
    {
        listPointer leftc = root->left;
        if(root->data < leftc->data) //�U���root�j
        {
            int temp = root->data;
            root->data = leftc->data;
            leftc->data = temp;
        }
    }
}
void delet(listPointer root, listPointer lastnode)
{
    root->data = lastnode->data;
    check(root);
    if(lastnode->parent != NULL) //�٦��`�I
    {
        listPointer p = lastnode->parent;
        if(p->left == lastnode)
        {
            p->left = NULL;
        }
        else if(p->right == lastnode)
        {
            p->right = NULL;
        }
        free(lastnode);
    }
    else//�u�ѤUroot
    {
        free(root);
    }
}
listPointer insert(listPointer root,int index)
{
    if(index/2 !=1)
    {
        listPointer ptr = insert(root,index/2);
        if(index%2!=0)
        {
            if(ptr->right != NULL)
            {
                ptr = ptr->right;
            }
        }
        else if(index%2 == 0)
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
    //else if(root->right != NULL)
    //{
    //    listPointer rightc = finddata(root->right,data);
    //    if(rightc != NULL)
    //    {
    //        return rightc;
     //   }
    //    else
    //    {
    //        return NULL;
    //    }
   // }
    else
    {
        return NULL;
    }
}
listPointer findindex(listPointer root,int index) //�j�M����
{
    if(root->index == index)
    {
        return root;
    }
    if(root->left != NULL && root->right != NULL)
    {
        listPointer leftc = findindex(root->left,index);
        listPointer rightc = findindex(root->right,index);
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
        listPointer leftc = findindex(root->left,index);
        if(leftc != NULL)
        {
            return leftc;
        }
        else
        {
            return NULL;
        }
    }
    else if(root->right != NULL)
    {
        listPointer rightc = findindex(root->right,index);
        if(rightc != NULL)
        {
            return rightc;
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
    listPointer temp,root=NULL;
    int user,data,index=0;
    do
    {
        printf("0:add,1:find,2:delete,3:print,4:exit\n");
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
            }
            else
            {
            	temp = finddata(root,data);
            	if(temp == NULL)
            	{
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
	                newnode->parent = temp;
	                check(newnode);
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
                temp = findindex(root,index);
                index--;
                delet(root,temp);
                if(index == 0)
                {
                    root = NULL;  //main�̪�root�����אּNULL
                }
            }
        }
        else if(user == 3)
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
    while(user!=4);
    return 0;
}
/*
0
15
0
7
0
11
0
3
0
8
0
6
0
14
*/
