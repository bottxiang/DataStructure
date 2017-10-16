#include <stdio.h>

typedef struct LNode *List
struct LNode{
    ElementType Data[MAXSIZE];
    int last; //数组下标最后一位
}
struct LNode L;

//初始化（建立空的顺序表）
List MakeEmpty{
    List PtrL;
    PtrL = (List)malloc(sizeof(struct LNode));
    PtrL->last = -1;
    return PtrL;
}

//查找元素X的下标
int Find(ElementType X, List PtrL){
    int i = 0;
    while(i <= PtrL->last && PtrL->Data[i] != X)
        i++;
    if(i > PtrL->last) return -1;
    else return i;
}

//插入（在第i（1≤i≤n+1）个位置上插入元素X） last为最后一个元素下标，n为位置(第几个)
void Insert(ElementType X, int i, List PtrL){
    int j;
    if(PtrL->last == MAXSIZE-1){
        printf("已满\n");
        return;
    }
    if(i < 1 || i > PtrL->last + 2){
        printf("位置不合法\n");
        return;
    }
    for(j = PtrL->last; j >= i-1; i--)
        PtrL->Data[j+1] = PtrL->Data[j];
    PtrL->Data[i-1] = X;
    PtrL->last++;
}
// 删除（删除表的第 i (1≤i≤n)个位置上的元素)
void Delete(int i, List PtrL){
    int j;
    if(i < 1 || i > PtrL->last + 1){
        printf("位置不合法\n");
        return;
    }
    for(j = i; j <= PtrL->last; j++)
        PtrL->Data[i-1] = PtrL->Data[i];
    PtrL->last--;
}
int main(){

    return 0;
}
