#include <iostream>
#include <conio.h>
#include <cmath>
#include "ohmslaw.h"

using namespace std;

float f_l_C_Uncertainty, f_l_average, f_V_C_Uncertainty, f_V_average, f_I_C_Uncertainty, f_I_average;
string str_l_unit, str_V_unit, str_I_unit;

bool Length()
{
    int n_l_measurements, n_l_units;
    cout << "Number of measurements of quantity l: ";
    cin >> n_l_measurements;
    cout << "Units:" << endl;
    cout << "1.[m] | 2.[dm] | 3.[cm] | 4.[mm] | 5.[um] | 6[nm]" << endl;
    cin >> n_l_units;
    float a_l[n_l_measurements + 1], f_l_sum = 0, f_lA_sum = 0, f_l_A_Uncertainty, f_l_B_Uncertainty;

    switch(n_l_units)
    {
        case 1: a_l[0] = 1.0; str_l_unit = "[m]"; break;
        case 2: a_l[0] = -1.0; str_l_unit = "[dm]"; break;
        case 3: a_l[0] = -2.0; str_l_unit = "[cm]"; break;
        case 4: a_l[0] = -3.0; str_l_unit = "[mm]"; break;
        case 5: a_l[0] = -6.0; str_l_unit = "[um]"; break;
        case 6: a_l[0] = -7.0; str_l_unit = "[nm]"; break;
    }
    for (int i = 1; i <= n_l_measurements; i++)
    {
        cout << "l." << i << ": ";
        cin >> a_l[i];
        f_l_sum = f_l_sum + a_l[i];
    }
    cout << "Type B uncertainty for length: ";
    cin >> f_l_B_Uncertainty;
    f_l_average = f_l_sum / n_l_measurements;
    for (int i = 1; i <= n_l_measurements; i++)
    {
        f_lA_sum = f_lA_sum + (a_l[i] - f_l_average)*(a_l[i] - f_l_average);
    }
    f_l_A_Uncertainty = sqrt(f_lA_sum / (n_l_measurements - 1));
    f_l_C_Uncertainty = sqrt((f_l_A_Uncertainty*f_l_A_Uncertainty) + (sqrt(3) * f_l_B_Uncertainty)*(sqrt(3) * f_l_B_Uncertainty));
    return true;
}
bool Voltage()
{
    int n_V_measurements, n_V_units;
    cout << "Number of measurements of quantity V: ";
    cin >> n_V_measurements;
    cout << "Units:" << endl;
    cout << "1.[V] | 2.[mV] | 3.[uV] | 4.[kV]" << endl;
    cin >> n_V_units;
    float a_V[n_V_measurements + 1], f_V_sum = 0, f_VA_sum = 0, f_V_A_Uncertainty, f_V_B_Uncertainty;

    switch(n_V_units)
    {
        case 1: a_V[0] = 1.0; str_V_unit = "[V]"; break;
        case 2: a_V[0] = -3.0; str_V_unit = "[mV]"; break;
        case 3: a_V[0] = -6.0; str_V_unit = "[uV]"; break;
        case 4: a_V[0] = 3.0; str_V_unit = "[kV]"; break;
    }
    for (int i = 1; i <= n_V_measurements; i++)
    {
        cout << "V." << i << ": ";
        cin >> a_V[i];
        f_V_sum = f_V_sum + a_V[i];
    }
    cout << "Type B uncertainty for voltage: ";
    cin >> f_V_B_Uncertainty;
    f_V_average = f_V_sum / n_V_measurements;
    for (int i = 1; i <= n_V_measurements; i++)
    {
        f_VA_sum = f_VA_sum + (a_V[i] - f_V_average)*(a_V[i] - f_V_average);
    }
    f_V_A_Uncertainty = sqrt(f_VA_sum / (n_V_measurements - 1));
    f_V_C_Uncertainty = sqrt((f_V_A_Uncertainty*f_V_A_Uncertainty) + (sqrt(3) * f_V_B_Uncertainty)*(sqrt(3) * f_V_B_Uncertainty));
    return true;
}
bool Current()
{
    int n_I_measurements, n_I_units;
    cout << "Number of measurements of quantity I: ";
    cin >> n_I_measurements;
    cout << "Units:" << endl;
    cout << "1.[A] | 2.[mA] | 3.[uA] | 4.[nA]" << endl;
    cin >> n_I_units;
    float a_I[n_I_measurements + 1], f_I_sum = 0, f_IA_sum = 0, f_I_A_Uncertainty, f_I_B_Uncertainty;

    switch(n_I_units)
    {
        case 1: a_I[0] = 1.0; str_I_unit = "[A]"; break;
        case 2: a_I[0] = -3.0; str_I_unit = "[mA]"; break;
        case 3: a_I[0] = -6.0; str_I_unit = "[uA]"; break;
        case 4: a_I[0] = -9.0; str_I_unit = "[nV]"; break;
    }
    for (int i = 1; i <= n_I_measurements; i++)
    {
        cout << "I." << i << ": ";
        cin >> a_I[i];
        f_I_sum = f_I_sum + a_I[i];
    }
    cout << "Type B uncertainty for current: ";
    cin >> f_I_B_Uncertainty;
    f_I_average = f_I_sum / n_I_measurements;
    for (int i = 1; i <= n_I_measurements; i++)
    {
        f_IA_sum = f_IA_sum + (a_I[i] - f_I_average)*(a_I[i] - f_I_average);
    }
    f_I_A_Uncertainty = sqrt(f_IA_sum / (n_I_measurements - 1));
    f_I_C_Uncertainty = sqrt((f_I_A_Uncertainty*f_I_A_Uncertainty) + (sqrt(3) * f_I_B_Uncertainty)*(sqrt(3) * f_I_B_Uncertainty));
    return true;
}
