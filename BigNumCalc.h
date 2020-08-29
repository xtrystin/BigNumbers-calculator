#pragma once
#include <iostream>
using namespace std;

int FindLastDigit(char* number);
void Reverse(char* number);          //Reverse number
void CheckZeros(char* score, int nullPosition);      // for Sub()

void Add(char* numb1, char* numb2);
void Sub(char* numb1, char* numb2);

//MUL
string AddM(char* numb1, char* numb2);   //modified Adder for Mul()
void Mul(char* numb1, char* numb2);

//DIV
string AddD(char* numb1, char* numb2);   //modified Adder for Div()
string MulD(char* numb1, char* numb2);          // Mul for Div()
void Div(char* numb1, char* numb2);      //   numb1 / numb2       


