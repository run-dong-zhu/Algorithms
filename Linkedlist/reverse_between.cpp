//
//  main.cpp
//  algorithms
//
//  Created by 朱润东 on 3/2/18.
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

//partial reverse from m node to n node
ListNode* reverse_between(ListNode* head, int m, int n) {
    ListNode* result = head;
    
    int change_len = n - m + 1;
    
    ListNode* pre_head = NULL;
    
    while(head && --m) {
        pre_head = head;
        head = head->next;
    }
    
    ListNode* modify_list_tail = head;
    ListNode* new_head = NULL;
    
    while(head && change_len) {
        ListNode *next = head->next;
        head->next = new_head;
        new_head = head;
        head = next;
        change_len--;
    }
    
    modify_list_tail->next = head;
    
    if(m != 1) {
        pre_head->next = new_head;
    }
    else {
        result = new_head;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    // init six nodes
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    ListNode f(6);
    
    //connect nodes by pointer
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    
    printf("%s\n", "before reverse:");
    print_list(&a);
    
    printf("%s\n", "after reverse:");
    print_list(reverse_between(&a, 2, 4));
    
    return 0;
}
