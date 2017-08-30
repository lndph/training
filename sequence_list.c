#include "sequence_list.h"
#include <stdlib.h>
/*
*�������ܣ���ӡ�����Ա������
*
*/
void Display_Sq(SqList *L)
{
    int i;
    for (i = 0;i < L->length;i++)
    {
        printf("L %d elem is %d \n",(i + 1),L->elem[i]);
    }
}

/*
*�������ܴ������Ա�
*/
Status InitList_Sq(SqList *L)
{
    //����һ���յ����Ա�L
    if (0 == (L->elem = (ElemType*) malloc ( LIST_INIT_SIZE * sizeof(ElemType))) )
    {
        return -1;
    }
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;

    return OK;
}

/*
*��������:��˳�����Ա�L�е�i��λ�ò����µ�Ԫ��e
*/
Status ListInsert_Sq(SqList *L,int i,ElemType e)
{
    if(i < 1 || i > (L->length + 1))
    {
        return ERROR;
    }

    if(L->length >= L->listsize)
    {
        ElemType *new_base_addr;
        new_base_addr = (ElemType *)realloc(L->elem,(L->listsize + LISTINCREMENT)*sizeof(ElemType));
        if(!new_base_addr)
        {
            return OVERFLOW;
        }
        L->elem = new_base_addr;
        L->listsize += LISTINCREMENT;
    }

    ElemType *q = &(L->elem[i-1]);    //qΪeҪ�����λ��
    ElemType *p;
    for(p = (&L->elem[L->length] - 1); p >= q; --p)
    {
        *(p + 1) = *p;  //��qλ�ú��Ԫ�ض�������
    }

    *q = e;
    L->length++;
    return OK;
}

/*
*��������:ɾ��˳������L�еĵ�i��Ԫ�أ�����e����
*/
Status ListDelete_Sq(SqList *L,int i,ElemType *e)
{
    if(L->length < 1 || i > L->length)
    {
        return ERROR;
    }

    ElemType *q = &(L->elem[i-1]);    //qΪҪɾ����λ��
    *e = *q;
    for (;q < (L->elem + L->length - 1);q++)
    {
        *q = *(q + 1);
    }

    L->length--;
    return OK;
}

/*
*��������;�����һ����e��ȵ�ֵ,����չ������������������ı�ȽϹ�ϵ
*/
Status LocateElem_Sq(SqList *L,ElemType e)
{
    int i = 0;
    ElemType *p = L->elem;

    while(++i <= L->length && e != *p++ );

    return (i <= L->length) ? i : 0;
}
/*
*��������:��˳��ϲ�2��˳�����Ա�LaLb.���洢��Lc
*/
Status MergeList_Sq(SqList *La,SqList *Lb,SqList *Lc)
{
    ElemType *pa = La->elem, *pb = Lb->elem,*pc;
    ElemType *pa_last = La->elem + La->length - 1;
    ElemType *pb_last = Lb->elem + Lb->length - 1;

    Lc->length = La->length + Lb->length;
    pc = Lc->elem = (ElemType *)malloc(Lc->length*sizeof(ElemType));
    if (!Lc->elem)
    {
        return OVERFLOW;
    }
    while(pa <= pa_last && pb <= pb_last)//�鲢
    {
        *pc++ = (*pa <= *pb) ? *pa++ : *pb++;
    }
    while(pa <= pa_last)//����Laʣ���Ԫ��
    {
        *pc++ = *pa++;
    }
    while(pb <= pb_last)//����Lbʣ���Ԫ��
    {
        *pc++ = *pb++;
    }
    return OK;
}
/*
*��������: �ڵ������еõ���i��Ԫ�أ������ظ�e
*/
Status GetElem_L(LNode *L,int i, ElemType *e)
{
    LNode *p = L->next;
    int j = 1;

    while(j < i && p)
    {
        j++;
        p = p->next;
    }
    if(!p && j > i)
    {
        return ERROR;
    }
    *e = p->data;
    return OK;
}

Status LinkInsert_L(LNode *L,int i, ElemType e)
{
    LNode *p = L->next;
    LNode *s;
    int j = 1;

    while(j < i && p)
    {
        j++;
        p = p->next;
    }
    if(!p && j > i)
    {
        return ERROR;
    }
    s = (LNode *)malloc(sizeof(LNode));
    s->next = p->next;
    p->next = s;
    s->data = e;

    return OK;
}

Status LinkDelete_L(LNode *L,int i, ElemType *e)
{
    LNode *p = L;
    LNode *q;
    int j = 1;

    while(j < i && p->next)
    {
        j++;
        p = p->next;
    }
    if(!(p->next) && j > i)
    {
        return ERROR;
    }
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);

    return OK;
}
/*
*����n���ڵ�ĵ�����
*/
void CreateList_L(LNode *L,int n)
{
    int i;
    LNode *p;

    L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL;
    for (i = n;i > 0;i--)
    {
        p = (LNode *)malloc(sizeof(LNode));
        scanf("%d",&p->data);
        p->next = L->next;
        L->next = p;
    }
}
/*
*�ϲ�������������Ϊһ������
*/
void MergeList_L(LNode *La,LNode *Lb,LNode *Lc)
{
    LNode *pa,*pb,*pc;
    pa = La->next;
    pb = Lb->next;

    Lc = pc = (LNode *)malloc(sizeof(LNode));
    pc->next = NULL;
    while(pa && pb)
    {
        if(pa->data <= pb->data)
        {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else
        {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa ? pa : pb;
}

void Sq_Test(void)
{
    LNode *L;
    CreateList_L(L,3);
}

