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
    printf("%d %p\n", head->val, head);
}

ListNode* find_cycle_set(ListNode* head) {
    std::set<ListNode*> node_set;
    while(head) {
        if(node_set.find(head) != node_set.end()) {
            return head;
        }
        node_set.insert(head);
        head = head->next;
    }
    return NULL;
}

ListNode* find_cycle(ListNode *head) {
    ListNode *fast = head;
    ListNode *slow = head;
    ListNode *meet = NULL;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            meet = slow;
            break;
        }
    }
    while(head && meet) {
        if(head == meet) {
            return head;
        }
        head = head->next;
        meet = meet->next;
    }
    return NULL;
}

int main(int argc, const char * argv[]) {
    // init 7 nodes
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    ListNode f(6);
    ListNode g(7);

    //connect node
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    f.next = &g;
    g.next = &d;
    
    printf("%s\n", "find_node:");
    print_list(find_cycle(&a));
    
    return 0;
}
