#include <iostream>
#define TEST 0          // 0 menu   1 Add()   2 Sub()   3 Mul()   4 Div()
#define SIZE 4090   // 100 000 // max 4090 digits because of std::cin??
using namespace std;

void menu()
{
    cout << endl;
    cout << "Operation: " << endl;
    cout << "!. Add" << endl;
    cout << "2. Subtract" << endl;
    cout << "3. Multiply" << endl;
    cout << "4. Divide" << endl;

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


bool CompareGreaterThan(string a, string b)     // a > b ?      a, b CANT BE reversed
{
    int nullPositionA = a.size();
    int nullPositionB = b.size();

    if (nullPositionA > nullPositionB)
        return true;
    else if (nullPositionA < nullPositionB)
        return false;
    else if (nullPositionA == nullPositionB)
    {
        for (int i = 0; i < nullPositionA; i++)
        {
            if (a[i] > b[i])
                return true;
            else if (a[i] < b[i])
                return false;
            else if (a[i] == b[i])
                continue;
        }
        return false;
    }

}

bool CompareEqual(string a, string b)      // a == b ?      a, b CANT BE reversed
{
    int nullPositionA = a.size();
    int nullPositionB = b.size();

    if (nullPositionA > nullPositionB)
        return true;
    else if (nullPositionA < nullPositionB)
        return false;
    else if (nullPositionA == nullPositionB)
    {
        for (int i = 0; i < nullPositionA; i++)
        {
            if (a[i] > b[i])
                return true;
            else if (a[i] < b[i])
                return false;
            else if (a[i] == b[i])
                continue;
        }
        return true;
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


string Add2(char* numb1, char* numb2)   //modified Adder for Mul()
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

void Mul(char* numb1, char* numb2)          // 7h           // todo:  33 * 4  77 * 15  15 * 77  does not work   4 * 33 WORK
{
    int a;
    int carry = 0;
    int lastDigit1 = FindLastDigit(numb1) - 1;                                  // last digit in reversed number  (array position)
    int lastDigit2 = FindLastDigit(numb2) - 1;                                  
    int lastDigit = (lastDigit1 > lastDigit2) ? lastDigit1 : lastDigit2;
    cout << endl << "Your longest number length: " << lastDigit + 1 << endl;    // number length = lastDigit+1
    //cout << lastDigit1 << " " << lastDigit2 << endl;
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
            //cout << tmp[j+i] << endl;


            if (j == lastDigit1 && carry > 0)               // carry  on last digit -> create new digit
            {
               // cout << tmp[2] << endl;
                if (tmp[lastDigit1 + 1 + i] == NULL)        //if its first time is can be NULL  because of else  tmp[lastDigit1 + 1 + i] = NULL;
                {
                    tmp[lastDigit1 + 1 + i] = (char)(carry + '0');
                    tmp[lastDigit1 + 2 + i] = NULL;
                }
                else
                {
                    tmp[lastDigit1 + 1 + i] = (char)(int(tmp[lastDigit1 + 1 + i] - '0' + carry) + '0');      //tmp -> number is char   carry -> number is int
                    tmp[lastDigit1 + 2 + i] = NULL;			                                            // create string

                }
               
                
            }
            else
                tmp[lastDigit1 + 1 + i] = NULL;

            //cout << j << " " << tmp[2] << endl;
        }
       // cout << tmp[0] << " " << tmp[1] << " " <<tmp[2] << endl;
        string s;
        s = Add2(scoreM, tmp);                   
        scoreSize = s.size();
        for (int i = 0; i < s.size(); i++)      //strcpy doesnt work
        {
            scoreM[i] = s[i];
           // cout << scoreM[i] << endl;
        }
        scoreM[s.size()] = NULL;            //create string
       // cout <<scoreM <<endl;


        for (int i = 0; i < SIZE; i++)          // reset tmp
            tmp[i] = '0';

        carry = 0;
    }
   
 
    cout << endl << "Score has " << scoreSize << " digits! " << endl;
    Reverse(scoreM);
    cout << "Score: \n" << scoreM << endl;

}










string AddD(char* numb1, char* numb2)   //modified Adder for Mul()
{
    // cout << numb1 << endl;
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
        //cout << i << endl;
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



    //numb1[lastDigit1 + 1] = NULL;      // create string   needed in Mul()                  ??????????????????????????????????????????????????????? 
    numb2[lastDigit2 + 1] = NULL;



    //strcpy_s(numb1, score);
   // cout << "In func Add2: " << numb1 << endl;


    //for (int i = 0; i < SIZE; i++)
    //    cout << score[i] << " ";

    string h = score;
    //  cout << h << endl;
     // cout << score << endl;
    return h;


}




string MulD(char* numb1, char* numb2)          // Mul for Div()
{
    int a;
    int carry = 0;
    int lastDigit1 = FindLastDigit(numb1) - 1;                                  // last digit in reversed number  (array position)
    int lastDigit2 = FindLastDigit(numb2) - 1;                                  // number length = lastDigit+1
    int lastDigit = (lastDigit1 > lastDigit2) ? lastDigit1 : lastDigit2;
   // cout << endl << "Your longest number length: " << lastDigit + 1 << endl;

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
            a = (numb2[i] - '0') * (numb1[j] - '0') + carry;
            if (a >= 10)
            {
                carry = a / 10;
                a = a % 10;

            }
            else
                carry = 0;


            tmp[j + i] = (char)(a + '0');     // +i  -> next numb2                                           its like:      111
            //cout << tmp[i] << endl;                                                                                     *  12
                                                                                                              //          ------
                                                                                                              //            222
            if (j == lastDigit1 && carry > 0)               // carry  on last digit -> create new digit                    1110<-------this 0
            {

                if (tmp[lastDigit1 + 1 + i] == NULL)        //if its first time is can be NULL  because of else  tmp[lastDigit1 + 1 + i] = NULL;
                {
                    tmp[lastDigit1 + 1 + i] = (char)(carry + '0');
                    tmp[lastDigit1 + 2 + i] = NULL;
                }
                else
                {
                    tmp[lastDigit1 + 1 + i] = (char)(int(tmp[lastDigit1 + 1 + i] - '0' + carry) + '0');      //tmp -> number is char   carry -> number is int
                    tmp[lastDigit1 + 2 + i] = NULL;			                                            // create string

                }		                                     // create string


            }
            else
                tmp[lastDigit1 + 1 + i] = NULL;


        }

        string s;
        s = Add2(scoreM, tmp);
        scoreSize = s.size();
        for (int i = 0; i < s.size(); i++)      //strcpy doesnt work
        {
            scoreM[i] = s[i];
            // cout << scoreM[i] << endl;
        }
        scoreM[s.size()] = NULL;            //create string
       // cout <<scoreM <<endl <<endl;


        for (int i = 0; i < SIZE; i++)          // reset tmp
            tmp[i] = '0';
       
        carry = 0;
    }

    numb1[lastDigit1 + 1] = NULL;      // change '0' to string NULL
    numb2[lastDigit2 + 1] = NULL;



   // cout << endl << "Score has " << scoreSize << " digits! " << endl;
    //Reverse(scoreM);
    Reverse(scoreM);
    //cout << "Mul: " << scoreM << endl;                                      //scoreM is NOT reversed
    string h = scoreM;
    return scoreM;

}

//For algorithm see file: div_algorithm.txt
void Div(char* numb1, char* numb2)      //   numb1 / numb2           numb1 numb2  Reversed!!!!!!!!!!!!!!
{

    char x[SIZE];
    for (int i = 0; i < SIZE; i++)         
        x[i] = '0';
    x[1] = NULL;

    char one[SIZE];
    for (int i = 0; i < SIZE; i++)
        one[i] = '0';
    one[0] = '1';
    one[1] = NULL;
    //cout << one << endl << endl;

   while(true)
    {
        string s;
        s = AddD(x, one);
        
        for (int i = 0; i < s.size(); i++)      //strcpy 
        {
            x[i] = s[i];
            // cout << scoreM[i] << endl;
        }
        x[s.size()] = NULL;                                 //x IS reversed
       // cout << "x(reversed): " << x << endl;
       // cout << "numb2(reversed): " << numb2 << endl;
        string MulScore;
        MulScore = MulD(numb2, x);                           // MulScore NOT reversed
      //  cout << "Mul score: " << MulScore << endl;
        if (CompareGreaterThan(MulScore, numb1))
        {
            Reverse(x);
            cout << x << " - 1";
            return;
        }
        else if ( CompareEqual(MulScore, numb1) )         // MulScore, numb1 CANT BE reversed
        {
            Reverse(x);
            cout << x;
            return;
        }
        else
        {
            //cout << x <<endl;
            continue;
        }
            

     }
   

}





int main()
{
    char numb1[SIZE];
    char numb2[SIZE];

    for (int i = 0; i < SIZE; i++)      //change all chars to '0'
    {
        numb1[i] = '0';
        numb2[i] = '0';

    }

    cout << "HUGE NUMBERS CALCULATOR" << endl;
    cout << "Maximum number's length: " << SIZE << " digits!" << endl;
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
        break;
    case 4:
        cout << "Computing..." << endl;
        cout << "If numbers are long it can take a few minutes" << endl;
        Reverse(numb1);                             //reverse reversion
        Div(numb1, numb2);                          // score is down rounded
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

#if (TEST == 4)
    //Reverse(numb1);
    //Reverse(numb2);
    cout << "Computing..." << endl;
    cout << "If numbers are long it can take a few minutes" << endl;
    Reverse(numb1);                             //reverse reversion
    Div(numb1, numb2);                          // score is down rounded
#endif // (TEST == 4)

    
   

    return 0;
}

