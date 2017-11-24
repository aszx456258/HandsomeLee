#include <stdio.h>
#include <stdlib.h>
typedef struct listNode *listPointer;//設置環境
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
listPointer head = NULL,ptr;//使用全域變數 這樣就不用傳值給副函式
int user,num,newnumber;
void add(int *num)//做新增的動作
{
    if(head!=NULL)//判斷是否為空
    {
        listPointer newptr = creatnode();//新增一個ptr
        ptr = ptr->link;
        listPointer ptr2 = head;
        if(ptr==NULL)//判斷是否只有一個
        {
            if(*num>ptr2->data)//比頭大的話新增在後
            {
                ptr2->link = newptr;
                ptr2->link->data = *num;
            }
            else if(*num<ptr2->data)//比頭小時新增在前
            {
                listPointer newptr = creatnode();
                newptr->link = head;
                head = newptr;
                head->data = *num;
            }
            else//一樣時顯示錯誤
            {
                printf("error\n");
            }
        }
        else
        {
            while(ptr!= NULL)//跑回圈
            {
                if(*num>ptr->data&&ptr->link == NULL)//如果比最後一個數字大 新增在尾
                {
                    ptr->link = newptr;
                    ptr->link->data = *num;
                    break;
                }
                else if(*num>ptr2->data&&*num<ptr->data)//如果在兩數之間 插入數字
                {
                    ptr2->link = newptr;
                    ptr2->link->link = ptr;
                    ptr2->link->data=*num;
                    break;
                }
                else if(*num<ptr2->data&&ptr2== head)//如果比頭小 新增在頭
                {
                    listPointer newptr = creatnode();
                    newptr->link = head;
                    head = newptr;
                    head->data = *num;
                    break;
                }
                else if(*num == ptr->data || *num == ptr2->data)//如果重複顯示錯誤
                {
                    printf("error\n");
                    break;
                }
                ptr = ptr->link;
                ptr2 = ptr2->link;
            }
        }
    }
    else//如果為空 新增在頭
    {
        listPointer newptr = creatnode();
        head = newptr;
        head->data = *num;
    }
}
void del(int *num)//做刪除的動作
{
    if(*num == head->data)//如果要刪除的數字為頭 刪除頭
    {
        head = head->link;
        free(ptr);
    }
    else
    {
        ptr = ptr->link;
        listPointer ptr2 = head;
        while(ptr!=NULL)//跑回圈
        {
            if(ptr->data == *num && ptr->link == NULL)//如果要刪除的數字在尾 刪除尾
            {
                ptr2->link = NULL;
                free(ptr);
                break;
            }
            else if(ptr->data == *num)//如果在中間 刪除中間
            {
                listPointer delptr = ptr;
                ptr2 -> link = ptr->link;
                free(delptr);
                break;
            }
            ptr = ptr->link;
            ptr2 = ptr2->link;
        }
    }
}
void check(int *turn,int num)//檢查數字是否在內
{
    while(ptr!=NULL)
    {
        if(ptr->data == num)
        {
            *turn = 1;//在內的話turn為1
            break;
        }
        ptr = ptr->link;
    }
}
int main()
{
    do
    {
        printf("1:新增數字 2:修改數字 3:刪除數字 4:全部印出 5:離開\n");//選擇功能
        scanf("%d",&user);
        ptr = head;
        if(user == 1)
        {
            printf("要新增的數字");//新增數字
            scanf("%d",&num);
            add(&num);
        }
        else if(user == 2)
        {
            int flag = 0,num2,turn = 0;
            if(head!=NULL)//判斷是否為空
            {
                printf("要修改的數字:");//選擇要修改的數字
                scanf("%d",&num);
                check(&turn,num);//檢查是否在內
                if(turn == 0)
                {
                    printf("數字不在串列內\n");
                    continue;//如果不在內不做之後的程序
                }
                turn = 0;
                ptr = head;//把ptr在設為頭做後面的動作
                printf("新數字:");//輸入要修改為哪個數字
                scanf("%d",&num2);
                check(&turn,num2);//檢查是否在內
                if(turn==1)
                {
                    printf("error\n");//在內的話就顯示錯誤
                    continue;
                }
                ptr = head;//重設ptr
                del(&num);//先刪除要修改的數字
                ptr = head;
                add(&num2);//再新增要修改成怎樣的數
            }
            else
            {
                printf("empty\n");
            }
        }
        else if(user == 3)
        {
            int turn = 0;
            if(head!=NULL)//判斷是否為空
            {
                printf("要刪除的數字:");//輸入要刪除的數字
                scanf("%d",&num);
                check(&turn,num);//檢查是否在內
                if(turn == 1)//在的話就進行刪除的動作
                {
                    del(&num);
                }
                else//不在的話印出不在串列內
                {
                    printf("數字不在串列內\n");
                }

            }
            else
            {
                printf("empty\n");
            }
        }
        else if(user == 4)
        {
            if(head==NULL)//判斷是否為空
            {
                printf("empty");
            }
            else
            {
                while(ptr!=NULL)//印出串列內的東西
                {
                    printf("%d ",ptr->data);
                    ptr = ptr->link;
                }
            }
            printf("\n");
        }
    }
    while(user!=5);//為5時離開
    return 0;
}
