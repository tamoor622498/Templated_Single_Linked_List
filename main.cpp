#include <iostream>
#include <string>
#include "LL.h"

using namespace std;

int main() {
    LL<int> *test = new LL<int>();
    for (int i = 0; i <= 2; ++i) {
        test->Push(i);
    }
    test->PushFront(99);
    test->Display();
    delete test;
    return 0;
}
