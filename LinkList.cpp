//
// Created by zhaodejin on 2021/8/3.
//
#include "LinkList.h"
#include <iostream>
//析构函数
LinkList::LinkList() {
    head = NULL;
}
LinkList::~LinkList()//和清空一样
{
    NODE *p = head;
    while (head)
    {
        p = head;
        head = head->next;
        delete(p);
    }
}
bool LinkList::clearSqList()//清空函数，和析构一样
{
    NODE *p = head;
    while (head)
    {
        p = head;
        head = head->next;
        delete(p);
    }
}
int LinkList::Length()
{
    NODE *p = head;
    int len = 0;
    while (p != NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}
bool LinkList::GetElem(int i, int *e)//*e是返回的元素
{
    NODE *p = head;
    int j = 0;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    if (p == NULL) return false;
    *e = p->data;
    return true;

}
bool LinkList::PriorElem(int cur_e, int *pre_e) {
    NODE *p = head;
    if (p->data == cur_e) return false;//是头结点，不存在上一个元素
    while (p->next != NULL) {
        if (p->next->data == cur_e) {
            *pre_e = p->data;
            return true;
        } else
            p = p->next;
    }
    return false;//遍历完不存在或者只有一个头结点

}
bool LinkList::NextElem(int cur_e, int *next_e) {
    NODE *p = head;
    if (head == NULL || head->next == NULL) return false;
    while (p->next != NULL) {
        if (p->data == cur_e) {
            *next_e = p->next->data;
            return true;
        } else
            p = p->next;
    }
    return false;
}
bool LinkList::Insert(int i, int e)
{
    NODE *p = head,*s;
    int j = 0;
    if (i == 0)
    {
        s = (NODE *)new NODE[1];
        s->data = e;
        s->next = p;
        head = s;
        return true;
    }
    while (p&&j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return false;//到队尾了
    s= (NODE *)new NODE[1];
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
bool LinkList::Delete(int i, int *e)
{
    NODE *p = head, *s;
    if (p == NULL) return false;
    int j = 0;
    if (i == 0)
    {
        head = head->next;
        *e = p->data;
        delete p;
        p = NULL;
        return true;
    }
    while (p&&j < i - 1)
    {
        j++;
        p = p->next;
    }
    if (p == NULL)
        return false;
    s = p->next;
    p->next = p->next->next;
    *e = s->data;
    delete s;
    s = NULL;
    return true;
}
NODE* LinkList::Reverse() {
    if (head == NULL || head->next == NULL) return head;
    NODE *p = head, *q = head->next, *r;
    head->next = NULL;
    while (q) {
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    head = p;
    return head;
}
bool LinkList::isEmpty() {
    return  head == NULL;
}
