//
//  main.cpp
//  algorithms
//
//  Created by 朱润东 on 3/1/18.
//  Copyright © 2018 Rundong Zhu. All rights reserved.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
void print_list(ListNode* head) {
    while(head) {
        printf("%d %p %p\n", head->val, head, head->next);
        head = head->next;
    }
}

ListNode reverse_list_1(ListNode* head) {
    //create new_head node
    ListNode *new_head = NULL;
    
    while(head) {
        ListNode *next = head->next;
        head->next = new_head;
        new_head = head;
        head = next;
    }
    
    return *new_head;
}
*/

int main(int argc, const char * argv[]) {
    // init five nodes
    ListNode a(10);
    ListNode b(20);
    ListNode c(30);
    ListNode d(40);
    ListNode e(50);
    
    //connect nodes by pointer
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    
    
    ListNode *head = &a;
    ListNode *new_head = NULL;
    //print_list(reverse_list_1(head));
    
    
    while(head) {
        ListNode *next = head->next;
        head->next = new_head;
        new_head = head;
        //printf("%d %p %p\n", head->val, head, head->next);
        head = next;
    }
    
    
    while(new_head) {
        printf("%d %p %p\n", new_head->val, new_head, new_head->next);
        new_head = new_head->next;
    }
    return 0;
}
