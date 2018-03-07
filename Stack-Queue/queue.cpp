#include <iostream>
#include <queue>

int main(int argc, const char * argv[]) {
    std::queue<int> Q;
    
    //push to the back of Queue
    Q.push(5);
    Q.push(6);
    Q.push(10);
    
    while(!Q.empty()) {
        printf("%s %d %s %d %s %lu\n", "Q.front = ", Q.front(), "Q.back = ", Q.back(), "Q.size = ", Q.size());
        //pop the front of Queue
        Q.pop();
    }
    
    if(Q.empty()) {
        printf("%s\n", "Queue is empty");
    }

    return 0;
}
