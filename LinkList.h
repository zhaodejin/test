//
// Created by zhaodejin on 2021/8/3.
//

#ifndef TEST_LINKLIST_H
#define TEST_LINKLIST_H

typedef  struct node{
    int data;
    struct node *next;
}NODE;

class LinkList {
private:
    NODE *head;
public:
    LinkList();
    ~LinkList();
    bool clearSqList();
    bool isEmpty();
    int Length();
    bool GetElem(int i,int *e);
    int LocateElem(int e);
    bool PriorElem(int cur_e,int *pre_e);
    bool NextElem(int cur_e,int *next_e);
    bool Insert(int i,int e);
    bool Delete(int i,int *e);
    NODE * Reverse();
};

#endif //TEST_LINKLIST_H
