/*
 *  Arithmetic.cpp
 *  Usage: Arithmetic num1 num2 operator
 */
#include <iostream>
#include <cstdlib>
using namespace std;
 
int main(int argc, char *argv[]) {
 	
   if (argc != 4) {
      cout << "Usage: Arithmetic num1 num2 operator" << endl;
      exit(1);
   }
 
   int operand1 = atoi(argv[1]);  // Parse string to int
   int operand2 = atoi(argv[2]);  // Parse string to int
   char op = argv[3][0];          // Extract first character only
 
   switch (op) {
      case '+':
         cout << operand1 << " + " << operand2 << " = " << operand1 + operand2 << endl;
         break;
      case '-':
         cout << operand1 << " - " << operand2 << " = " << operand1 - operand2 << endl;
         break;
      case '*':
         cout << operand1 << " * " << operand2 << " = " << operand1 * operand2 << endl;
         break;
      case '/':
         cout << operand1 << " / " << operand2 << " = " << operand1 / operand2 << endl;
         break;
      default:
         cout << "Unknown operator" << endl;
         exit(1);
   }
 
   return 0;
}
