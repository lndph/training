#define __SEQUENCE_LIST_H__
    #define __SEQUENCE_LIST_H__

#define TRUE            1
#define FALSE           (!TRUE)
#define OK              1
#define ERROR           (!OK)
#define INFEASIBLE      -1
#define OVERFLOW        -2
typedef int Status;     //定义函数结果返回值类型。
typedef int ElemType;   //定义线性表数据元素占用类型,此数据类型可根据实际应用更改为任何结构，例如新的结构体

#define LIST_INIT_SIZE  100     //线性表的初始分配空间大小
#define LISTINCREMENT   10      //空间分配增量
//顺序表的结构体
typedef struct{
    ElemType    *elem;      //线性表的基地址
    int         length;     //线性表的当前长度
    int         listsize;   //线性表的当前分配存储容量
}SqList;

void Display_Sq(SqList *L);
Status InitList_Sq(SqList *L);
Status ListInsert_Sq(SqList *L,int i,ElemType e);
Status ListDelete_Sq(SqList *L,int i,ElemType *e);
Status LocateElem_Sq(SqList *L,ElemType e);
Status MergeList_Sq(SqList *La,SqList *Lb,SqList *Lc);

//单链表的结构体
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
