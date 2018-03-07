#include <iostream>
#include <stack>

int main(int argc, const char * argv[]) {
    std::stack<int> S;
    
    //push to the top of Stack
    S.push(5);
    S.push(6);
    S.push(10);
    
    while(!S.empty()) {
        printf("%s %d %s %lu\n", "S.top = ", S.top(), "S.size = ", S.size());
        //pop top of the Stack
        S.pop();
    }
    
    if(S.empty()) {
        printf("%s\n", "Stack is empty");
    }
    
    return 0;
}
