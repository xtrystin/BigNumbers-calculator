#include <iostream>

#define TEST 0          // 0 run normally   1 Add()   2 Sub()   3 Mul()
#define SIZE 4090   // 100 000 // max 4090 digits because of std::cin??
using namespace std;

void menu()
{
    cout << endl;
    cout << "Operation: " << endl;
    cout << "!. Add" << endl;
    cout << "2. Subtract" << endl;
    cout << "3. Multiply" << endl;
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


string Add2(char* numb1, char* numb2)
{
    int a;
    int carry = 0;
    int lastDigit1 = FindLastDigit(numb1) - 1;                                  // last digit in reversed number  (array position)
    int lastDigit2 = FindLastDigit(numb2) - 1;
    int lastDigit = (lastDigit1 > lastDigit2) ? lastDigit1 : lastDigit2;
   // cout << endl << "Your longest number length: " << lastDigit + 1 << endl;

    char score[SIZE];
    for (int i = 0; i < SIZE; i++)
        score[i] = '0';

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

        score[i] = (char)(a + '0');                // still reversed
    }

    if (carry == 1)
    {
        score[lastDigit + 1] = '1';
        score[lastDigit + 2] = NULL;				// create string
    }
    else
        score[lastDigit + 1] = NULL;



    numb1[lastDigit1 + 1] = NULL;      // create string   needed in Mul()
    numb2[lastDigit2 + 1] = NULL;

 
    
    //strcpy_s(numb1, score);
   // cout << "In func Add2: " << numb1 << endl;
    

    //for (int i = 0; i < SIZE; i++)
    //    cout << score[i] << " ";

    string h = score;

    // cout << h << endl;
    // cout << score << endl;
    return h;

    
}

void Mul(char* numb1, char* numb2)          // 7h
{
    int a;
    int carry = 0;
    int lastDigit1 = FindLastDigit(numb1) - 1;                                  // last digit in reversed number  (array position)
    int lastDigit2 = FindLastDigit(numb2) - 1;                                  // number length = lastDigit+1
    int lastDigit = (lastDigit1 > lastDigit2) ? lastDigit1 : lastDigit2;
    cout << endl << "Your longest number length: " << lastDigit + 1 << endl;

    char scoreM[SIZE];
    for (int i = 0; i < SIZE; i++)
        scoreM[i] = '0';
    scoreM[1] = NULL;                
    
    int scoreSize;


    char tmp[SIZE];
    for (int i = 0; i < SIZE; i++)
        tmp[i] = '0';


    numb1[lastDigit1 + 1] = '0';      // change string NULL to '0'
    numb2[lastDigit2 + 1] = '0';



    for (int i = 0; i < lastDigit2 + 1; i++)    //numb2 digits
    {

        for (int j = 0; j < lastDigit1 + 1; j++)    //numb1 digits
        {
            a = ( numb2[i] - '0' ) * ( numb1[j] - '0' ) + carry;
            if (a >= 10)
            {
                carry = a / 10;
                a = a % 10;

            }
            else
                carry = 0;


            tmp[j+i] = (char)(a + '0');     // +i  -> next numb2 
            //cout << tmp[i] << endl;


            if (j == lastDigit1 && carry > 0)               // carry  on last digit -> create new digit
            {
               
               tmp[lastDigit1 + 1 + i] = tmp[lastDigit1 + 1 + i] + (char) (carry + '0');
               tmp[lastDigit1 + 2 + i] = NULL;				                                     // create string
                
                
            }
            else
                tmp[lastDigit1 + 1 + i] = NULL;


        }
        
        string p;
        p = Add2(scoreM, tmp);                   
        scoreSize = p.size();
        for (int i = 0; i < p.size(); i++)      //strcpy doesnt work
        {
            scoreM[i] = p[i];
           // cout << scoreM[i] << endl;
        }
        scoreM[p.size()] = NULL;            //create string
       // cout <<scoreM <<endl <<endl;


        for (int i = 0; i < SIZE; i++)          // reset tmp
            tmp[i] = '0';

        carry = 0;
    }
   
 
    cout << endl << "Score has " << scoreSize << " digits! " << endl;
    Reverse(scoreM);
    cout << "Score: \n" << scoreM << endl;

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
    cout << "Maximum number's lenght: " << SIZE << " digits!" << endl;
    cout << "Be careful, score CAN'T have more than " << SIZE << " digits!!" << endl << endl;
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
        Sub(numb1, numb2);      //todo  message that numb1 must be >= numb2 !!!!!!!!!!   &&   numb1, numb2 > 0      && only integers
        break;
    case 3:
        Mul(numb1, numb2);
    default:
        break;
    }

#endif // (TEST == 0)    

#if (TEST == 1)
    Add(numb1, numb2);                          // only integers > 0
#endif // (TEST == 1)

#if (TEST == 2)
    Sub(numb1, numb2);                              //numb1 >= numb2  &&   numb1, numb2 > 0
#endif // (TEST == 2)

#if  (TEST == 3)
    Mul(numb1, numb2);                          // only integers > 0
#endif //  (TEST == 3)


   

    return 0;
}

