#ifndef OHMSLAW_H_INCLUDED
#define OHMSLAW_H_INCLUDED

using namespace std;

bool Length();
bool Current();
bool Voltage();
bool Resistance();

extern float f_l_A_Uncertainty; extern float f_l_B_Uncertainty; extern float f_l_average;
extern int n_l_measurements; extern int n_l_units; extern float f_l_C_Uncertainty;
extern string str_l_unit;

extern float f_V_A_Uncertainty; extern float f_V_B_Uncertainty; extern float f_V_average;
extern int n_V_measurements; extern int n_V_units; extern float f_V_C_Uncertainty;
extern string str_V_unit;

extern float f_I_A_Uncertainty; extern float f_I_B_Uncertainty; extern float f_I_average;
extern int n_I_measurements; extern int n_I_units; extern float f_I_C_Uncertainty;
extern string str_I_unit;

#endif // OHMSLAW_H_INCLUDED
