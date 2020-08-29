#include <iostream>
#include <Windows.h>
#include "menu.h"
#include "BigNumCalc.h"
#define TEST 0          // 0 menu   1 Add()   2 Sub()   3 Mul()   4 Div()
#define SIZE 4090   // 100 000 // max 4090 digits because of std::cin??
using namespace std;



int main()
{
    system("cls");
    GameLogo();
    Sleep(1000);
    system("cls");

    char numb1[SIZE];
    char numb2[SIZE];

    for (int i = 0; i < SIZE; i++)      //change all chars to '0'
    {
        numb1[i] = '0';
        numb2[i] = '0';

    }



#if (TEST == 0)

    while (true)
    {
        for (int i = 0; i < SIZE; i++)      //clear before each operation
        {
            numb1[i] = '0';
            numb2[i] = '0';

        }


        system("cls");
        menu();
        int choice;
        cin >> choice;

        system("cls");
        switch (choice)
        {
        case 1:
            cout << "*************************************************" << endl;
            cout << "*                    Adder                      *" << endl;
            cout << "*************************************************" << endl;
            cout << "Maximum number's length: " << SIZE << " digits!" << endl;
            cout << "Be careful, score CAN'T have more than " << SIZE << " digits!!" << endl;
            cout << "*************************************************" << endl;
            cout << "Number 1:  ";
            cin >> numb1;
            cout << "Number 2:  ";
            cin >> numb2;

            Reverse(numb1);
            Reverse(numb2);

            Add(numb1, numb2);
            break;
        case 2:
            cout << "*************************************************" << endl;
            cout << "*                  Subtractor                   *" << endl;
            cout << "*************************************************" << endl;
            cout << "Maximum number's length: " << SIZE << " digits!" << endl;
            cout << "Be careful, score CAN'T have more than " << SIZE << " digits!!" << endl;
            cout << "*************************************************" << endl;
            cout << "Number 1:  ";
            cin >> numb1;
            cout << "Number 2:  ";
            cin >> numb2;

            Reverse(numb1);
            Reverse(numb2);

            Sub(numb1, numb2);      //todo  message that numb1 must be >= numb2 !!!!!!!!!!   &&   numb1, numb2 > 0      && only integers
            break;
        case 3:
            cout << "*************************************************" << endl;
            cout << "*                   Multipler                   *" << endl;
            cout << "*************************************************" << endl;
            cout << "Maximum number's length: " << SIZE << " digits!" << endl;
            cout << "Be careful, score CAN'T have more than " << SIZE << " digits!!" << endl;
            cout << "*************************************************" << endl;
            cout << "Number 1:  ";
            cin >> numb1;
            cout << "Number 2:  ";
            cin >> numb2;

            Reverse(numb1);
            Reverse(numb2);

            Mul(numb1, numb2);
            break;
        case 4:
            cout << "*************************************************" << endl;
            cout << "*                    Divider                    *" << endl;
            cout << "*************************************************" << endl;
            cout << "Maximum number's length: " << SIZE << " digits!" << endl;
            cout << "Be careful, score CAN'T have more than " << SIZE << " digits!!" << endl;
            cout << "*************************************************" << endl;
            cout << "Number 1:  ";
            cin >> numb1;
            cout << "Number 2:  ";
            cin >> numb2;

            Reverse(numb1);
            Reverse(numb2);

            cout << "Computing..." << endl;
            cout << "If numbers are long it can take a few minutes" << endl << endl;
            Reverse(numb1);                             //reverse reversion
            Div(numb1, numb2);                          // score is down rounded
            break;
        case 5:
            Credits();

            break;
        case 6:
            GameLogo();
            Sleep(1000);
            exit(0);
            break;
        default:
            break;
        }
        cout << "Click enter to return";
        getchar(); getchar();
    }


#endif // (TEST == 0)    

#if (TEST == 1)
    cout << "Number 1:  ";
    cin >> numb1;
    cout << "Number 2:  ";
    cin >> numb2;

    Reverse(numb1);
    Reverse(numb2);

    Add(numb1, numb2);                          // only integers > 0
#endif // (TEST == 1)

#if (TEST == 2)
    cout << "Number 1:  ";
    cin >> numb1;
    cout << "Number 2:  ";
    cin >> numb2;

    Reverse(numb1);
    Reverse(numb2);

    Sub(numb1, numb2);                              //numb1 >= numb2  &&   numb1, numb2 > 0
#endif // (TEST == 2)

#if  (TEST == 3)
    cout << "Number 1:  ";
    cin >> numb1;
    cout << "Number 2:  ";
    cin >> numb2;

    Reverse(numb1);
    Reverse(numb2);

    Mul(numb1, numb2);                          // only integers > 0
#endif //  (TEST == 3)

#if (TEST == 4)
    cout << "Number 1:  ";
    cin >> numb1;
    cout << "Number 2:  ";
    cin >> numb2;

    Reverse(numb1);
    Reverse(numb2);

    cout << "Computing..." << endl;
    cout << "If numbers are long it can take a few minutes" << endl;
    Reverse(numb1);                             //reverse reversion
    Div(numb1, numb2);                          // score is down rounded
#endif // (TEST == 4)




    return 0;
}

