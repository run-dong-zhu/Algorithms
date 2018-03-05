//
//  main.cpp
//  algorithms
//
//  Created by 朱润东 on 3/4/18.
//  Copyright © 2018 Rundong Zhu. All rights reserved.
//

#include <iostream>
#include <set>

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

/*
void print_list(ListNode* head) {
    printf("%d %p\n", head->val, head);
}
*/

ListNode* partition(ListNode *head, int x) {
    ListNode small(0);
    ListNode *small_ptr = &small;
    ListNode large(0);
    ListNode *large_ptr = &large;
    
    while(head) {
        if(head->val < x) {
            small_ptr->next = head;
            small_ptr = head;
        }
        else {
            large_ptr->next = head;
            large_ptr = head;
        }
        head = head->next;
    }
    large_ptr->next = NULL;
    small_ptr->next = large.next;
    return small.next;
}

int main(int argc, const char * argv[]) {
    // init 7 nodes
    ListNode a(1);
    ListNode b(4);
    ListNode c(3);
    ListNode d(2);
    ListNode e(5);
    ListNode f(6);
    ListNode g(2);

    //connect node
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    f.next = &g;
    
    
    printf("%s\n", "before partition::");
    print_list(&a);
   
    printf("%s\n", "after partition:");
    print_list(partition(&a, 3));
    
    return 0;
}
