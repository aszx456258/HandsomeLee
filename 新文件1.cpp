#include <stdio.h>
#include <stdlib.h>
typedef struct listNode *listPointer;
typedef struct listNode{
    int data;
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
listPointer insert(listPointer n,int number)
{
    if(number < n->data)  // number小於data往左走
	{
    	if(n->left != NULL)
        {
        	insert(n->left, number);
		}		
      	else
      	{                                 // 走到最底的地方新增node
	    	listPointer newnode = createnode();
	    	newnode->data = number;
	    	n->left = newnode;
	    	newnode->parent = n;
      	}
	}
	else if(number > n->data)
	{
		if(n->right != NULL)
        {
        	insert(n->right, number);
		}		
      	else
      	{                                 // 走到最底的地方新增node
	    	listPointer newnode = createnode();
	    	newnode->data = number;
	    	n->right = newnode;
	    	newnode->parent = n;
      	}
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
    else if(root->right!=NULL)
	{
		listPointer rightc = finddata(root->right,data);
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
void print2(listPointer root)
{
	if(root->left!=NULL)
    {
        print2(root->left);
    }
    printf("%d\t",root->data);
	if(root->right!=NULL)
    {
        print2(root->right);
	}
    
}
int main()
{
    listPointer temp,head=NULL,root = NULL;
    int user,data,index = 0;
    do
    {
    	root = head;
        printf("1:add,2:del,3:print number,4:print tree,5:exit\n");
        scanf("%d",&user);
        if(user == 1)
        {
            printf("input number");
            scanf("%d",&data);
            if(root == NULL)
            {
                root = createnode();
                root -> data = data;
                //root -> index = ++index;
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
	                //newnode->index = ++index;
	                temp = insert(root,data);
				}
				else
				{
					printf("error\n");
				}
            }
        }
        else if(user == 2)
        {
            if(root == NULL)
            {
                printf("empty");
            }
            else
            {
            	int flag=0,turn=0;
                printf("input number");
                scanf("%d",&data);
                temp = finddata(root,data); 
                if(temp == NULL)
                {
                    printf("not find number");
                }
                else
                {
                	if(temp->right == NULL && temp->left == NULL && temp!=root)
                	{
                		if(temp->parent->left == temp)
                		{
                			temp->parent->left = NULL;
						}
						else
						{
							temp->parent->right = NULL;
						}
						free(temp);
					}
                	else if(temp->left!=NULL)
                	{
                		root = temp;
                		root = root->left;
                		while(root->right!=NULL)
                		{
                			root = root->right;
                			flag=1;
						}
						if(flag==0)
						{
							temp->data = root->data;
							root->parent->left = root->left;
							root->left->parent = root->parent;
							free(root);
						}
						else if(root->left==NULL)  
						{
							temp->data = root->data;
							root->parent->right = NULL;
							free(root);
						}
						else
						{
							temp->data = root->data;
							root->parent->right = root->left;
							root->left->parent = root->parent;
							free(root);
						} 
					}
					else if(root->right!=NULL)
					{
						root = temp;
						root = root->right;
						while(root->left!=NULL)
                		{
                			root = root->left;
                			flag = 1;
						}
						if(flag==0)
						{
							temp->data = root->data;
							root->parent->right = root->right;
							root->right->parent = root->parent;
							free(root);
						} 
						else if(root->right == NULL)
						{
							temp->data = root->data;
							root->parent->left = NULL;
							free(root);
						}
						else
						{
							temp->data = root->data;
							root->parent->left = root->right;
							root->right->parent = root->parent;
							free(root);
						}
						
					}
					else
					{
						listPointer root = NULL;
						head = root;
					}
					printf("done");
                }
            }
            printf("\n");
        }
        else if(user==3)
        {
        	if(root == NULL)
            {
                printf("empty");
            }
            else
            {
                print2(root);
            }
            printf("\n");
		}
        else if(user == 4)
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
    while(user!=5);
    return 0;
}
/*
1
50
1
40
1
60
1
45
1
44
1
43
1
30
1
46
4


*/
