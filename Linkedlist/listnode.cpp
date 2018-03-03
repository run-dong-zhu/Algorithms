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
    
    //print lists
    while(head) {
        printf("%d %p %p\n", head->val, head, head->next);
        head = head->next;
    }
    
    return 0;
}
