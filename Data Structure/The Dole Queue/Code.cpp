#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <cstring>

using namespace std;

typedef struct DList{
    DList* prev;
    DList* next;
    int data;
}DList;

DList* initDList()
{
    return NULL;
}

DList* add(int x, DList* list)
{
    DList* p = new(DList);
    p->data = x;
    if(list == NULL)
    {
        p->next = p;
        p->prev = p;
        return p;
    }
    DList* last = list->prev;
    list->prev = p;
    last->next = p;
    p->next = list;
    p->prev = last;
    
    return list;
}
DList* first, *second;

DList* pop(DList* list, DList* victim)
{
    if(victim == NULL || list == NULL)
    {
        return NULL;
    }
    if(list->next == list && victim == list)
    {
        delete list;
        return NULL;        
    }
    
    DList* p = victim->prev, *t = victim->next;
    
    p->next = t;
    t->prev = p;
    
    if(victim == list)
        list = victim->next;
    if(first->next == victim)
        first->next = victim->next;
    if(second->prev == victim)
        second->prev = victim->prev;
    //delete victim;
    
    return list;
    
}

DList* remove(int k, int m, DList* list)
{
    for(int x = 0; x < k; x++)
    {
        first = first->next;
    }
    for(int y = 0; y < m; y++)
    {
        second = second->prev;
    }
    
    if(first->data == second->data)
    {
        if(first->data > 9)
            printf(" %d", first->data);
        else
            printf("  %d", first->data);
    }
    else
    {
        if(first->data > 9)
            printf(" %d", first->data);
        else
            printf("  %d", first->data);
        if(second->data > 9)
            printf(" %d", second->data);
        else
            printf("  %d", second->data);
    }
    
    DList* t1 = new(DList), *t2 = new(DList);
    t1->next = first->next;
    t2->prev = second->prev;
    list = pop(list, first);
    list = pop(list, second);
    
    
    if(list != NULL)
        printf(",");
    
    return list;
    
}                     

int main()
{
    
    int a , b ,c;
    while(1)
    {
        scanf("%d %d %d", &a , &b, &c);
        if(a == 0 && b == 0 && c == 0)
            break;
        
        DList* list = initDList();
        
        for(int x = 1; x <= a; x++)
        {
            list = add(x, list);
        }
        
        first = list->prev, second = list;
        while(list != NULL)
        {
            list = remove(b, c, list);
        }
        printf("\n");
        
    }
    
    
    return 0;
}
