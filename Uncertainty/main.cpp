#include <iostream>
#include <cmath>
#include <conio.h>
#include <string>

using namespace std;

int main()
{
    string strQuantity, strUnit, strUnit_2;
    int nChoise, nUnitOrderOfMagnitude, nNumberOfMeasurements;
    float fBUncertainty, fAverage, fSum = 0.0, fAUncertainty, fCUncertainty, fSum_2 = 0.0;
    //Get name for the quantity and basic unit
    cout << "Quantity: ";
    cin >> strQuantity;
    cout << "Basic unit (if measured in cm, write m): ";
    cin >> strUnit;
    cout << endl;
    //Get unit multiplier
    cout << "1.[" << strUnit << "] | 2.[d" << strUnit << "] | 3.[c" << strUnit << "] | 4.[m"<< strUnit << "] | ";
    cout << "5.[u" << strUnit << "] | 6.[n" << strUnit << "] |7.[da"<< strUnit << "] | 8.[h"<< strUnit << "] | ";
    cout << "9.[k" << strUnit << "] | 10.[M" << strUnit << "] | 11.[G" << strUnit << "]" << endl;
    do
    {
        cin >> nChoise;
        switch (nChoise)
        {
            case 1:
                nUnitOrderOfMagnitude = 0;
                strUnit_2 = "[" + strUnit + "]"; break;
            case 2:
                nUnitOrderOfMagnitude = -1;
                strUnit_2 = "[d" + strUnit + "]"; break;
            case 3:
                nUnitOrderOfMagnitude = -2;
                strUnit_2 = "[c" + strUnit + "]"; break;
            case 4:{
                nUnitOrderOfMagnitude = -3;
                strUnit_2 = "[m" + strUnit + "]"; break;}
            case 5:{
                nUnitOrderOfMagnitude = -6;
                strUnit_2 = "[u" + strUnit + "]"; break;}
            case 6:{
                nUnitOrderOfMagnitude = -9;
                strUnit_2 = "[n" + strUnit + "]"; break;}
            case 7:{
                nUnitOrderOfMagnitude = 1;
                strUnit_2 = "[da" + strUnit + "]"; break;}
            case 8:{
                nUnitOrderOfMagnitude = 2;
                strUnit_2 = "[c" + strUnit + "]"; break;}
            case 9:{
                nUnitOrderOfMagnitude = 3;
                strUnit_2 = "[k" + strUnit + "]"; break;}
            case 10:{
                nUnitOrderOfMagnitude = 6;
                strUnit_2 = "[M" + strUnit + "]"; break;}
            case 11:{
                nUnitOrderOfMagnitude = 9;
                strUnit_2 = "[G" + strUnit + "]"; break;}
            default: {cout << "Unavailable option! Try again: "; break;}
        }
    } while (nChoise < 1 || nChoise > 11);
    cout << endl;
    //Get total number of measurement and a list of them
    cout << "What is the total number of measurements of " << strQuantity << "?: ";
    cin >> nNumberOfMeasurements;
    float f_aMeasurements[nNumberOfMeasurements];
    for (int i = 0; i < nNumberOfMeasurements; i++)
    {
        cout << strQuantity << " " << i + 1 << strUnit_2 << ": ";
        cin >> f_aMeasurements[i];
    }
    cout << endl;
    //Get type B uncertainty
    cout << "Type B uncertainty " << strUnit_2 << ": ";
    cin >> fBUncertainty;
    //Calculate average
    for (int i = 0; i < nNumberOfMeasurements; i++)
    {
        fSum = fSum + f_aMeasurements[i];
    }
    fAverage = fSum / nNumberOfMeasurements;
    //Calculate type A uncertainty
    for (int i = 0; i < nNumberOfMeasurements; i++)
    {
        fSum_2 = (f_aMeasurements[i] - fAverage)*(f_aMeasurements[i] - fAverage);
    }
    fAUncertainty = sqrt(fSum_2 / (nNumberOfMeasurements - 1));
    //Calculate type C uncertainty
    fCUncertainty = sqrt(pow(fAUncertainty, 2) + pow(fBUncertainty * sqrt(3), 2));
    cout << "Total uncertainty = ";
    cout << fCUncertainty << strUnit_2;
    cout << " = " << fCUncertainty << "*10^(" << nUnitOrderOfMagnitude << ") ["  << strUnit << "]" <<endl;
    cout << "Press any key to exit...";
    getch();
    return 0;
}
