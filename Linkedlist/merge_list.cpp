//
//  main.cpp
//  algorithms
//
//  Created by 朱润东 on 3/3/18.
//  Copyright © 2018 Rundong Zhu. All rights reserved.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print_list(ListNode* head) {
    while(head) {
        if(head->next) {
            printf("%d %s", head->val, "->");
        }
        else {
            printf("%d\n", head->val);
        }
        head = head->next;
    }
}


ListNode* merge_list(ListNode* l1, ListNode* l2) {
    //create temp node
    ListNode temp(0);
    ListNode *pre_head = &temp;
    while(l1 && l2) {
        if(l1->val < l2->val) {
            pre_head->next = l1;
            pre_head = l1;
            l1 = l1->next;
        }
        else {
            pre_head->next = l2;
            pre_head = l2;
            l2 = l2->next;
        }
    }
    
    if(l1) {
        pre_head->next = l1;
    }
    
    if(l2) {
        pre_head->next = l2;
    }
    
    return temp.next;
}

int main(int argc, const char * argv[]) {
    // init 5 nodes
    ListNode a(1);
    ListNode b(5);
    ListNode c(9);
    ListNode d(2);
    ListNode e(4);
    
    //connect list 1
    a.next = &b;
    b.next = &c;
    
    //connect list 2
    d.next = &e;
    
    printf("%s\n", "list 1:");
    print_list(&a);
    printf("%s\n", "list 2:");
    print_list(&d);
    
    printf("%s\n", "after merge:");
    print_list(merge_list(&a, &d));
    
    
    return 0;
}
