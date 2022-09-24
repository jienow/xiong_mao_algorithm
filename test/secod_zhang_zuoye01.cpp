#include <iostream>
using namespace std;
typedef struct node{
    int data;
    struct node *next;
}LinkNode;

void func(LinkNode* q){
    //O(m+n)
    LinkNode *p = q->next;
    LinkNode *pre = nullptr;
    while(p!=nullptr){
        if(p->data >= 0 || pre == nullptr){
            pre = p;
            p = p->next;
        }
        else{
            pre->next = pre->next->next;
            p->next = q->next;
            q->next = p;
            p = pre->next;
        }
    }
}


void half_sort(LinkNode* q){
    //p拥有头节点不需要判定
    //p等于第一个节点
    LinkNode *p = q->next;
    //pre等于p指向的节点的前一个节点
    LinkNode *pre = nullptr;
    while(p){
        //当前节点大于0 或者 第一个节点小于0直接移动
        if(p->data >= 0 || pre == nullptr){
            //pre和p向下一个移动
            pre = p;
            p = p->next;
        }
        //如果当前节点小于0
        else{
            //将当前节点从原来的地方删除
            pre->next = pre->next->next;
            //q是头节点，使用头插法
            p->next = q->next;
            q->next = p;
            //p指向pre的下一个
            p = pre->next;
        }
        
    }
}




int main(){
    node *head = new node;
    head->data = -1;
    head->next = nullptr;



    return 0;
}
