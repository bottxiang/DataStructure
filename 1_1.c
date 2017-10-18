#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50
typedef double ElementType;
typedef struct LNode *SqList;
struct LNode
{
    ElementType *Elem;
    int Length;
};
/*Creat a sequence list*/
void CreatList(SqList L);
/*Init list*/
void InitList(SqList L);
/*Destory list*/
void DestoryList(SqList L);
/*Clear list*/
void ClearList(SqList L);
int IsEmpty(SqList L);
int GetLength(SqList L);
void GetElem(SqList L, int i, ElementType *e);
int LocateElem(SqList L, ElementType e);
void PriorElem(SqList L, ElementType cur_e, ElementType *pre_e);
void NextElem(SqList L, ElementType curr_e, ElementType *next_e);
void ListInsert(SqList L, int i, ElementType e);
void ListDelete(SqList L, int i,ElementType *e);
void ListTraverse(SqList L);
int main()
{
    struct LNode Sql;
    InitList(&Sql);
    printf("empty? %d\n",IsEmpty(&Sql));
    ListInsert(&Sql, 1, 2.5);
    printf("empty? %d\n",IsEmpty(&Sql));
    printf("Length? %d\n",GetLength(&Sql));
    ListInsert(&Sql, 1, 2.8);
    printf("After inserting two element, lenth = %d \n",Sql.Length);
    ElementType e;
    GetElem(&Sql, 1, &e);
    printf("E1 = %f \n",e);
    GetElem(&Sql, 2, &e);
    printf("E1 = %f \n",e);


    return 0;
}

/*Creat a sequence list*/
// void CreatList(SqList L)
// {
//
// }
/*Init list*/
void InitList(SqList L)
{
    L->Elem = (ElementType *)malloc(sizeof(ElementType)*MAXSIZE);
    L->Length = 0;
}
/*Destory list*/
void DestoryList(SqList L)
{
    free(L->Elem);
    L->Elem = NULL; /*Avoiding error when free the second time*/
    L->Length = 0;
}
/*Clear list*/
void ClearList(SqList L)
{
    L->Length = 0;
}
/*Function to test whether the list is empty*/
int IsEmpty(SqList L)
{
    if(L->Length == 0)
        return 1;
    else
        return 0;
}
/*Getting the length of list*/
int GetLength(SqList L)
{
    return L->Length;
}
void GetElem(SqList L, int i, ElementType *e)
{
    *e = L->Elem[i-1];
}
int LocateElem(SqList L, ElementType e)
{
    int i;
    for(i = 1; i <= L->Length; i++)
        if(L->Elem[i-1] == e)
            return i;
    return -1; /*Not found*/
}
void PriorElem(SqList L, ElementType cur_e, ElementType *pre_e)
{
    int i;
    for(i = 1; i <= L->Length; i++)
        if(L->Elem[i-1] == cur_e)
        {
            *pre_e = L->Elem[i-2];
            return;/*Found! End the function*/
        }

}
void NextElem(SqList L, ElementType cur_e, ElementType *next_e)
{
    int i;
    for(i = 1; i <= L->Length; i++)
        if(L->Elem[i-1] == cur_e)
        {
            *next_e = L->Elem[i];
            return;/*Found! End the function*/
        }
}
void ListInsert(SqList L, int i, ElementType e)
{
    int j;
    for(j = L->Length; j >= i; j--)
        L->Elem[j] = L->Elem[j-1];
    L->Elem[i-1] = e;
    L->Length++;
}
void ListDelete(SqList L, int i,ElementType *e)
{
    int j;
    for(j = i+1; j <= L->Length; j++)
        L->Elem[j-2] = L->Elem[j-1];
    L->Length--;
}
//  0 1 .2 3 4 len=5  len/2=2
//  0 1 2 .3 4 5 len=6 len/2=3

void ListTraverse(SqList L)
{
    int i;
    int len = L->Length;
    int N = len / 2;
    for(i = 0; i < N; i++)
    {
        ElementType tmp = L->Elem[i];
        L->Elem[i] = L->Elem[len-1-i];
        L->Elem[len-1-i] = tmp;
    }
}
