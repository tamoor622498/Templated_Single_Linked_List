#include <iostream>
#include <string>
#include "LL.h"

using namespace std;

int main() {
    LL<int> *test = new LL<int>();
    for (int i = 0; i <= 10; ++i) {
        test->Push(i);
    }
    test->Display();
    delete test;
    return 0;
}
