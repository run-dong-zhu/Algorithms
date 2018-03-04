//
//  main.cpp
//  algorithms
//
//  Created by 朱润东 on 3/3/18.
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


ListNode* find_intersection_set(ListNode* l1, ListNode* l2) {
    std::set<ListNode*> node_set;
    while(l1) {
        node_set.insert(l1);
        l1 = l1->next;
    }
    
    while(l2) {
        if(node_set.find(l2) != node_set.end()) {
            return l2;
        }
        l2 = l2->next;
    }
    
    return NULL;
}

int get_list_len(ListNode* list) {
    int length = 0;
    while(list) {
        length++;
        list = list->next;
    }
    return length;
}

ListNode* list_alignment(int long_len, int short_len, ListNode *list) {
    int delta = long_len - short_len;
    //printf("%d", delta);
    while (delta) {
        list = list->next;
        delta--;
    }
    return list;
}

ListNode* find_intersection(ListNode *l1, ListNode *l2) {
    int l1_len = get_list_len(l1);
    int l2_len = get_list_len(l2);
    
    if(l1_len > l2_len) {
        l1 = list_alignment(l1_len, l2_len, l1);
    }
    
    if(l2_len > l1_len) {
        l2 = list_alignment(l2_len, l1_len, l2);
    }
    
    while(l1 && l2) {
        if(l1 == l2)
            return l1;
        //printf("%d", l1->val);
        l1 = l1->next;
        //printf("%d", l2->val);
        l2 = l2->next;
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

    //connect list 1
    a.next = &b;
    b.next = &c;
    c.next = &f;
    
    //connect list 2
    d.next = &e;
    e.next = &f;
    
    f.next = &g;
    
    printf("%s\n", "list 1:");
    print_list(&a);
    printf("%s\n", "list 2:");
    print_list(&d);
    
    printf("%s\n", "find_list:");
    print_list(find_intersection(&a, &d));
    
    return 0;
}
