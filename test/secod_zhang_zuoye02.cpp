#include <iostream>
using namespace std;
typedef struct node
{
    int data;
    struct node *next;
} LinkNode;

void func(LinkNode *A, LinkNode *B, LinkNode *&c)
{
    LinkNode *p = A->next, *q = B->next, *wai, *nei;
    c = new LinkNode();
    nei = c;
    while(p!=nullptr&&q!=nullptr){
        if(p->data == q->data){
            wai = new LinkNode();
            wai->data = p->data;
            nei->next = wai;
            nei = wai;
            p = p->next;
            q = q->next;
        }else if(p->data < q->data)
            p = p->next;
        else
            q = q->next;
    }
    nei->next = nullptr;
    //复杂度O(m+n)
}

int main()
{

    return 0;
}