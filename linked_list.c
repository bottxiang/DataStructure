#include <stdio.h>
#include <stdlib.h>
typedef double ElementType;
typedef struct LNode *List;
struct LNode{
    ElementType Data;
    List next;
};
struct LNode L;
List PtrL;
// 函数声明
int Length (List PtrL);
List FindKth(int K, List PtrL);
List Find(ElementType X, List PtrL);
List Insert(ElementType X, int i, List PtrL);
List Delete(int i, List PtrL);
void Print(List PtrL);
//主函数
int main(){
    List head = NULL;
    printf("head0 = %p\n",head);
    printf("Length = %d\n",Length(head));

    head = Insert(2.5,1,head);
    printf("head1 = %p\n",head);
    printf("Length = %d\n",Length(head));
    Print(head);

    head = Insert(2.8,1,head);
    printf("head2 = %p\n",head);
    printf("head2->next = %p\n",head->next);
    printf("Length = %d\n",Length(head));
    Print(head);

    head = Insert(3.2,1,head);
    printf("head3 = %p\n",head);
    printf("head3->next = %p\n",head->next);
    printf("Length = %d\n",Length(head));
    Print(head);


    printf("Find 1 th = %.2f\n",FindKth(1,head)->Data);
    printf("Find 2 th = %.2f\n",FindKth(2,head)->Data);
    printf("Find 3 th = %.2f\n",FindKth(3,head)->Data);

    printf("Find (X = 2.5): %p\n",Find(2.5,head));
    printf("Find (X = 2.8): %p\n",Find(2.8,head));
    printf("Find (X = 3.2): %p\n",Find(3.2,head));

    head = Delete(2,head);
    printf("After deleting the 2th one:");
    Print(head);
    head = Delete(1,head);
    printf("After deleting the 1st one:");
    Print(head);
    return 0;
}
//打印链表各节点的值
void Print(List PtrL){
    List p;
    p = PtrL;
    printf("Datas:");
    while(p != NULL){ //刚开始错写成if，结果只能打印第一个节点的数据。。。！！！
        printf(" %.2f",p->Data);
        p = p->next;
    }
    printf("\n");

}
//求表长
int Length (List PtrL){
    List p;
    p = PtrL;
    int j=0; //计数器
    while(p){
        j++;
        p = p->next;
    }
    return j;
}
//根据序号查找：FindKth
List FindKth(int K, List PtrL){
    List p;
    p = PtrL;
    int i = 1; //序号计数器
    while(p != NULL && i < K){
        p = p->next;
        i++;
    }
    if(p != NULL && i == K) return p;
    else return NULL;
}
//根据值查找：Find
List Find(ElementType X, List PtrL){
    List p;
    p=PtrL;
    while(p != NULL && p->Data != X)
        p = p->next;
    if(p != NULL && p->Data == X) return p;
    else return NULL;
}
//在序号为i(1 ≤ i ≤ n+1)的节点前插入一个节点
List Insert(ElementType X, int i, List PtrL){
    List p,s;
    s = (List)malloc(sizeof(struct LNode));
    s->Data = X; //忘记！！
    if(i == 1){
        s->next = PtrL;
        PtrL = s;
    }
    else{
        p = FindKth(i-1, PtrL); //找到序号为i的前一个节点的地址
        s->next = p->next;
        p->next = s;
    }
    return PtrL;
}
//删除序号为i(1 ≤ i ≤ n)的节点
List Delete(int i, List PtrL){
    List p,s;
    if(i == 1){
        s = PtrL; //将第一个节点保存下来，方便free
        PtrL = PtrL->next; //将链表头指针改指向第二个节点
        free(s);
        return PtrL;
    }
    else{
        p = FindKth(i-1, PtrL); //找到序号为i的前一个节点的地址
        s = p->next;
        p->next = s->next;
        free(s);
        return PtrL;
    }
}
