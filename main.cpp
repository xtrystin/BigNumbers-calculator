#include <iostream>

#define TEST 0          // 0 run normally   1 Add()   2 Sub()
#define SIZE 4090   // 100 000 // max 4090 digits
using namespace std;

void menu()
{
    cout << endl;
    cout << "Operation: " << endl;
    cout << "!. Add" << endl;
    cout << "2. Subtract" << endl;
}


int FindLastDigit(char* number)
{
    for (int i = SIZE - 1; i >= 0; i--)
    {
        if (number[i] != '0')       //search NULL
            return i;
    }
}


void Reverse(char* number)
{
    int lastDigit = FindLastDigit(number) - 1;       // least important digit index     NULL - 1

    for (int i = 0; i < (lastDigit+1) / 2; i++)
    {
        swap(number[i], number[lastDigit - i]);
    }

}


void Add(char* numb1, char* numb2)
{
    int a;
    int carry = 0;
    int lastDigit1 = FindLastDigit(numb1) - 1;                                  // last digit in reversed number  (array position)
    int lastDigit2 = FindLastDigit(numb2) - 1;  
    int lastDigit = (lastDigit1 > lastDigit2) ? lastDigit1 : lastDigit2;
    cout << endl << "Your longest number length: " << lastDigit+1 << endl;

    char score[SIZE];
    for (int i = 0; i < SIZE; i++)
        score[i] = '0';
   
   // for (int i = 0; i < SIZE - 1; i++)
   //     cout << numb1[i] << endl;
 //   cout << endl << endl;
   // for (int i = 0; i < SIZE - 1; i++)
   //     cout << numb2[i] << endl;



    numb1[lastDigit1 + 1] = '0';      // change string NULL to '0'
    numb2[lastDigit2 + 1] = '0';
    //cout << lastDigit;
    

    for (int i = 0; i <= lastDigit; i++)
    {
        a = (numb1[i] - '0') + (numb2[i] - '0') + carry;
        //cout << numb1[i]  << "   " << numb2[i]  << endl;
        if (a >= 10)
        {
            carry = 1;
            a -= 10;
        }
        else
            carry = 0;

        score[i] = (char) (a + '0');                // still reversed
    }
  
    if (carry == 1)
    {
        score[lastDigit + 1] = '1';
        score[lastDigit + 2] = NULL;				// create string
    }
    else
        score[lastDigit + 1] = NULL;
        

   // cout << score;
    Reverse(score);

    cout << "Score: \n" << score << endl;


}





void CheckZeros(char* score, int nullPosition)
{
    int i = nullPosition - 1;
    while (score[i] == '0')
    {
        score[i] = NULL;
        score[i + 1] = '0';
        i--;
    }

}

void Sub(char* numb1, char* numb2)
{
    int a;
    int lastDigit1 = FindLastDigit(numb1) - 1;                                  // last digit in reversed number  (array position)
    int lastDigit2 = FindLastDigit(numb2) - 1;
    int lastDigit = (lastDigit1 > lastDigit2) ? lastDigit1 : lastDigit2;
    cout << endl << "Your longest number length: " << lastDigit + 1 << endl;

    char score[SIZE];
    for (int i = 0; i < SIZE; i++)
        score[i] = '0';

    numb1[lastDigit1 + 1] = '0';      // change string NULL to '0'
    numb2[lastDigit2 + 1] = '0';



    for (int i = 0; i <= lastDigit; i++)
    {
        a = (numb1[i] - '0') - (numb2[i] - '0');
                                                                                 //cout << numb1[i]  << "   " << numb2[i]  << endl;
        if (a < 0)
        {
            a += 10;
            
            int k = 1;
            while (numb1[i + k] <= 0)       // search for BORROW
            {
                numb1[i + k] = '9';
                k++;
            }
            numb1[i + k]--;

        }
                                                                                // cout << a << " ";
        score[i] = (char)(a + '0');                // still reversed
                                                                                // cout << score[i] << endl;
    }

    score[lastDigit + 1] = NULL;     

    CheckZeros(score, lastDigit+1);                          // check if there are zeros before NULL   (number is reversed, example: 100 NULL -> 001 NULL)
    Reverse(score);                        //                                                                      ^reversed    ^normal 
    cout << "Score: \n" << score << endl;

}





int main()
{
    char numb1[SIZE];
    char numb2[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        numb1[i] = '0';
        numb2[i] = '0';

    }

    cout << "HUGE NUMBERS CALCULATOR" << endl;
    cout << "Maximum number's lenght: " << SIZE << " digits!" << endl << endl;
    cout << "Number 1:  ";
    cin >> numb1;
    cout << "Number 2:  ";
    cin >> numb2;

    Reverse(numb1);
    Reverse(numb2);

#if (TEST == 0)

    menu();
    int choice;
    cout << "Choose option: ";
    cin >> choice;


    
    switch (choice)
    {
    case 1:
       
        Add(numb1, numb2);
        break;
    case 2:
        Sub(numb1, numb2);      //todo  message that numb1 must be >= numb2 !!!!!!!!!!   &&   numb1, numb2 > 0
        break;
    default:
        break;
    }

#endif // (TEST == 0)    

#if (TEST == 1)
    Add(numb1, numb2);
#endif // (TEST == 1)

#if (TEST == 2)
    Sub(numb1, numb2);
#endif // (TEST == 2)

    

   

    return 0;
}

