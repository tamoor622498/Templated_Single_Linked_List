#include <iostream>
#include <string>
#include "LL.h"

using namespace std;

int main() {
    LL<string> *test = new LL<string>();
    test->PushFront("One");
    test->Push("Two");
    test->Push("Three");
    test->Display();
    cout << test->operator[](0) << endl;
    cout << test->GetSize() << endl;
    delete test;
    return 0;
}
