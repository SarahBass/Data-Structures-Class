/************************************************************
 ------------------------------------------------------------
Sarah Bass
Lab Sort
CS 41 Data Structures
-------------------------------------------------------------
Description: write a program, which will calculate the 
results of Reverse Polish expressions that are provided by 
the user.

-----------Objectives------------------------ 
-Linked list to maintain stack
-Pushing/Popping operands
-Handles Errors:
    *Too many operators (+ - / *)
    *Too many operands (doubles)
    *Division by zero
-No array implementations of stack allowed
----------------------------------------------
Program logic: 
The program will take in a Polish expression
that separates the operators and operands by a single space, 
and terminates the expression with an equals sign.

The program will continue to take and evaluate expressions 
until the user enters a zero (0) on a line by itself 
followed by a new line.

-------------------------------------------------------------
************************************************************/
#include <stdio.h> 
#include <iostream> 
#include <string>
#include <sstream>
#include <iterator> 
#include <cstring>
#include <stdlib.h>
//#include <math.h> power^ functions
#include<climits>

using namespace std;
class doubleNode 
{
public:

    double info;				// Our data
    class doubleNode *next;	// Our Link
	
	    doubleNode(double data, doubleNode *ptr = 0) 
	{
        info = data; 
		next = ptr;
    }
};

class linkedStack
{
private:
	doubleNode *top;
	

public:

	linkedStack()
	{
		top = 0;
		
	}

	bool isEmpty()
	{
		return top == false;
	}

	void push(double data)
	{
		
		doubleNode *temp = new doubleNode(data);
		
		if (isEmpty())
			top = temp;
		else
		{
			temp->next = top;
			top = temp;
		}
	}

	double pop()
	{
			if (isEmpty()){
			return -999;
			}else{
				
		double doubleReturn = top->info;
		
		
		doubleNode *temp;
		temp = top;

		top = top->next;
		
		delete temp;
		
			
		return doubleReturn;}
	}

double peak (){
return top->info;
}

double convertNumber (string word){
double number;
std::string::size_type sz;
number = stod (word.substr(sz));
return number;
}

string identifyInput (string word){
    string identify;
    
    if (word.find('0') != std::string::npos ||
        word.find('1') != std::string::npos ||
       word.find('2') != std::string::npos ||
        word.find('3') != std::string::npos ||
        word.find('4') != std::string::npos ||
        word.find('5') != std::string::npos ||
        word.find('6') != std::string::npos ||
        word.find('7') != std::string::npos ||
        word.find('8') != std::string::npos ||
        word.find('9') != std::string::npos){
        identify = "number";
        
    }else if(word.find('+') != std::string::npos ||
         word.find('-') != std::string::npos ||
         word.find('x') != std::string::npos ||
         word.find('X') != std::string::npos ||
         word.find('/') != std::string::npos ||
         word.find('^') != std::string::npos ||
         word.find('*') != std::string::npos){
      identify = "operator"; 
        
    }else if (word.find('=') != std::string::npos){
       identify = "equals";
    }else{
        identify = "string";
    }
    return identify;
}
 
void counter (string word, int& numberCount, int& operatorCount){
    
    if (word.find('0') != std::string::npos ||
        word.find('1') != std::string::npos ||
        word.find('2') != std::string::npos ||
        word.find('3') != std::string::npos ||
        word.find('4') != std::string::npos ||
        word.find('5') != std::string::npos ||
        word.find('6') != std::string::npos ||
        word.find('7') != std::string::npos ||
        word.find('8') != std::string::npos ||
        word.find('9') != std::string::npos){
        
        numberCount++;
    }else if(word.find('+') != std::string::npos ||
         word.find('-') != std::string::npos ||
         word.find('x') != std::string::npos ||
         word.find('X') != std::string::npos ||
         word.find('/') != std::string::npos ||
       //word.find('^') != std::string::npos ||
         word.find('*') != std::string::npos){
      operatorCount++;   
    }

}


  double pemdas (double LHS, double RHS, string mathOperator){
    double answer;
    if(mathOperator == "+"){
      answer= LHS+RHS;}
   else if(mathOperator == "-"){
      answer = LHS-RHS;}
   else if(mathOperator == "*" || mathOperator == "x"|| mathOperator == "X"){
      answer = LHS*RHS;}
   else if(mathOperator == "/" &&  RHS!= 0){
      answer=  LHS/RHS;}
    else if (mathOperator == "/" && RHS == 0){
    cout << " ERROR: Numbers are not divisible by 0" << endl;
    answer = 0;
    }
   //else if(mathOperator == "^"){
    //answer=  pow(LHS,RHS);}
    else{cout << " Operation ERROR" << endl;}
    return answer;
    }

    bool errorMessage(int count, int numberCount, int operatorCount){
        if (count < 4 ){
            cout << " Error: Too Few Arguments" << endl;
            return true;}
        else if (operatorCount >= numberCount){
            cout << " Error : Too many operators" << endl;
            return true;}
        else if (numberCount > (count/2)){
            cout << " Error: Too many Operands" << endl;
             return true;}
        else{
        return false;
        }
    }
 
	 
};


	int main(){
    //----------------------
    double LHS = 0; 
    double RHS= 0; 
    string mathOperator;
    double answer= 0;
    //----------------------
    int numberCount =0;
    int operatorCount =0;
    int count = 0;
    string identify;
    bool error = false;    
    //---------------------
    linkedStack myStack;
    string sentence;
    string word;
    //---------------------
    cout << "--------------Start Reverse Polish Calculator---------------------" << endl;
    
    cout<< "To Stop ENTER 0. Enter RPN Equations ending with '=' :" << endl; 
    
    while (sentence != "0"){
        getline(cin, sentence);
        stringstream stream;
        stream.str(sentence);
    
        while (stream >> word)
    {
        
            myStack.counter(word, numberCount, operatorCount);
            identify = myStack.identifyInput(word);
            count++;

            if (identify == "string"){
                cout << " Error: Entered Invalid Input" << endl;}

            else if (identify == "number"){
                myStack.push(myStack.convertNumber(word));}

            else if(identify == "operator" && numberCount > 1){
                mathOperator = word;
                RHS = myStack.peak();
                myStack.pop();
        
                LHS = myStack.peak();
                myStack.pop();
        
                answer = myStack.pemdas (LHS, RHS, mathOperator);
        
                myStack.push(answer);}

            else if (identify == "equals"){
                error = myStack.errorMessage(count, numberCount, operatorCount);
                if (error == false){
                    cout << "Answer: " << answer << endl;}
                    myStack.pop();}
    }
    
    
    //reset for next loop
    for (int i = 0; i < (numberCount - (operatorCount*2)); i++) 
    {
        myStack.pop();
    }
    numberCount = 0;
    operatorCount = 0;
    count = 0; 
    answer = 0;
    LHS = 0;
    RHS = 0;
    error = false;

}//end of while loop
    
    cout <<endl;
    
    return 0;
}
/*---------Program Input and Output----------
10 10 + =
Answer: 20
100 10 50 25 / * - -2 / = -40
Answer: -40
10 15 - = -5
Answer: -5
2.5 3.5 + =
Answer: 6
10 0 / =
 ERROR: Numbers are not divisible by 0
Answer: 0
10 20 * / =
 Error : Too many operators
12 20 30 / =
 Error: Too many Operands
-10 -30 - = 20
Answer: 20
100 10 50 25 / * - -2 / = -40
Answer: -40
0
---------------------------------------------*/