#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef double ElementType;
typedef struct LNode
{
	ElementType data;
	struct LNode *next;// LNode 写错成其他也可以??
}LNode, *LinkList;

/*Init LinkList*/
void InitList(LinkList *Head);
/*Creat a sequence LinkList*/
void CreatList(LinkList *Head, int n);
/*Print list*/
void Print(LinkList Head);
/*Destory LinkList*/
void DestoryList(LinkList Head);
/*Clear LinkList*/
void ClearList(LinkList Head);
int IsEmpty(LinkList Head);
int GetLength(LinkList Head);
void GetElem(LinkList Head, int i, ElementType *e);
int LocateElem(LinkList Head, ElementType e);
void PriorElem(LinkList Head, ElementType cur_e, ElementType *pre_e);
void NextElem(LinkList Head, ElementType curr_e, ElementType *next_e);
void LinkListInsert(LinkList Head, int i, ElementType e);
void LinkListDelete(LinkList Head, int i, ElementType *e);
void LinkListTraverse(LinkList Head);
int main()
{
	LinkList Head = NULL;
	CreatList(&Head,4);
	Print(Head);
	Print(Head);
	LinkListTraverse(Head);
	Print(Head);

	system("pause");
	return 0;
}


/*Init LinkList*/                        /*??????*/
void InitList(LinkList *PtrHead)/*因为要修改头指针，所以要传指向头指针的指针*/
{
	*PtrHead = (LinkList)malloc(sizeof(struct LNode));
	(*PtrHead)->next = NULL;

}

/*Creat a Headink LinkList*/
void CreatList(LinkList *PtrHead, int n)
{
	struct LNode *p, *q;
	ElementType e;
	int i;
	InitList(PtrHead);
	if ((*PtrHead)->next == NULL) {
		printf("初始化成功!）\n");
	}
	else
		printf("初始化失败...\n");
	q = *PtrHead;
	for (i = 0; i < n; i++)
	{
		scanf("%lf", &e);
		p = (struct LNode *)malloc(sizeof(struct LNode));
		p->data = e;
		q->next = p; q = p;
	}
	q->next = NULL;

}
void Print(LinkList Head)
{
	struct LNode *p;
	p = Head->next;
	while (p)
	{
		printf(" %.2f", p->data);
		p = p->next;
	}
	printf("\n");

}
/*Destory LinkList*/
void DestoryList(LinkList Head)
{
	struct LNode *p,*s;
	p = Head;
	while (p != NULL) {
		s = p;
		p = p->next;
		free(s);
	}
	Head = NULL;
}
/*Clear LinkList*/
void ClearList(LinkList Head)
{
	struct LNode *p, *s;
	p = Head->next;
	Head->next = NULL;
	while (p != NULL) {
		s = p;
		p = p->next;
		free(s);
	}
}
int IsEmpty(LinkList Head)
{
	if (Head->next == NULL)
		return 1; //empty
	else
		return 0;
}
int GetLength(LinkList Head)
{
	struct LNode *p;
	p = Head->next;
	int cnt = 0;
	while (p) {
		cnt++;
		p = p->next;
	}
	return cnt;
}
void GetElem(LinkList Head, int i, ElementType *e)
{
	struct LNode *p;
	p = Head->next;
	int j = 1;
	while (p && j < i) {
		p = p->next;
		j++;
	}
	if (p && j == i)
		//   if(j == i)  wrong !!! because when p == NULL, maybe j == i
		//   if(p) is OK. if(p&&j==i) is also OK.
		*e = p->data;
}
int LocateElem(LinkList Head, ElementType e)
{
	struct LNode *p;
	p = Head->next;
	int j = 1;
	while (p && p->data != e) {
		p = p->next;
		j++;
	}
	if (p && p->data == e)
		return j;
}
void PriorElem(LinkList Head, ElementType cur_e, ElementType *pre_e)
{
	struct LNode *p, *q;
	q = Head->next;
	p = q->next;
	while (p && p->data != cur_e){
		q = p;
		p = p->next;
	}
	if (p && p->data == cur_e)
		*pre_e = q->data;
}

void NextElem(LinkList Head, ElementType cur_e, ElementType *next_e)
{
	struct LNode *p;
	p = Head->next;
	while (p && p->data != cur_e)
		p = p->next;
	if (p && p->next && p->data == cur_e) {
		p = p->next;          //合起来写为啥报错？？
		*next_e = p->data;	  //
	}

}
void LinkListInsert(LinkList Head, int i, ElementType e)
{
	struct LNode *p, *s;
	p = Head->next;
	int j = 1;
	while (p && j < i - 1) {
		p = p->next;
		j++;
	}
	if (p && j == i - 1) {
		s = (struct LNode *)malloc(sizeof(struct LNode));
		s->data = e;
		s->next = p->next;
		p->next = s;
	}
}
void LinkListDelete(LinkList Head, int i, ElementType *e)
{
	struct LNode *p,*q;
	q = Head;
	p = Head->next;
	int j = 1;
	while (p && j < i) {
		q = p;
		p = p->next;
	}
	if (p && j == i) {
		q->next = p->next;
		free(p);
	}
}
void LinkListTraverse(LinkList Head)
{
	struct LNode *p, *q;
	p = Head->next; //p point to the head of the remaining list, which hasn't been inserted to the list whose head is "Head".
	Head->next = NULL;
	while (p) {
		q = p;
		p = p->next; //q指向p后，p马上向后移动。不然q修改了和p共同指向的节点里的next后，会导致p不能正确向后移动。
		q->next = Head->next;
		Head->next = q;

	}
}
