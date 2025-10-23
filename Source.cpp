#include "Headline.h"
#include <iostream>

using std::cout;
using std::endl;

namespace MyNameSpace {
    void processNumber(int x) {
        static int staticVar = 0;
        int result = SUM_MACRO(x, staticVar);
        cout << "x + staticVar = " << result << endl;
        staticVar = x;
    }
}