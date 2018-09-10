#include <iostream>
#include "Funcs.h"

using namespace std;

int main()
{
    string expression = "(5-2)*(4-2)";
    cout << calculateExpression(expression) << endl;

    expression = "(2-(3+6)/3)";
    cout << calculateExpression(expression) << endl;

    expression = "-3-4-5";
    cout << calculateExpression(expression) << endl;
    return 0;
}



