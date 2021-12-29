#include <iostream>
#include <conio.h>
#include <cmath>
#include "ohmslaw.h"

using namespace std;

int main()
{
    Length();
    cout << "Total uncertainty for length: " <<f_l_C_Uncertainty << str_l_unit << endl;
    Voltage();
    cout << "Total uncertainty for voltage: " << f_V_C_Uncertainty << str_V_unit << endl;
    Current();
    cout << "Total uncertainty for current: " << f_I_C_Uncertainty << str_I_unit << endl;
    return 0;
}
