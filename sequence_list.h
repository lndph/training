#define __SEQUENCE_LIST_H__
    #define __SEQUENCE_LIST_H__

#define TRUE            1
#define FALSE           (!TRUE)
#define OK              1
#define ERROR           (!OK)
#define INFEASIBLE      -1
#define OVERFLOW        -2
typedef int Status;     //���庯���������ֵ���͡�
typedef int ElemType;   //�������Ա�����Ԫ��ռ������,���������Ϳɸ���ʵ��Ӧ�ø���Ϊ�κνṹ�������µĽṹ��

#define LIST_INIT_SIZE  100     //���Ա�ĳ�ʼ����ռ��С
#define LISTINCREMENT   10      //�ռ��������
//˳���Ľṹ��
typedef struct{
    ElemType    *elem;      //���Ա�Ļ���ַ
    int         length;     //���Ա�ĵ�ǰ����
    int         listsize;   //���Ա�ĵ�ǰ����洢����
}SqList;

void Display_Sq(SqList *L);
Status InitList_Sq(SqList *L);
Status ListInsert_Sq(SqList *L,int i,ElemType e);
Status ListDelete_Sq(SqList *L,int i,ElemType *e);
Status LocateElem_Sq(SqList *L,ElemType e);
Status MergeList_Sq(SqList *La,SqList *Lb,SqList *Lc);

//������Ľṹ��
typedef struct Lnode
{
    ElemType        data;
    struct Lnode    *next;
}LNode,*LinkList;

Status GetElem_L(LinkList L,int i, ElemType *e);
Status LinkInsert_L(LNode *L,int i, ElemType e);
Status LinkDelete_L(LNode *L,int i, ElemType *e);
void CreateList_L(LNode *L,int n);
void Sq_Test(void);
#endif
