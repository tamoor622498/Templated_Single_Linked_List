#include <iostream>
#include <string>
#include "LL.h"

using namespace std;

int main() {
    LL<string> *test = new LL<string>();
    test->Push("one");
    test->Push("Two");
    test->Push("Three");
    test->Display();
    delete test;
    return 0;
}
