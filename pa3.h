#ifndef PA3_H_
#define PA3_H_
#include<iostream>
#include <fstream>
#include <string>
#include<stack>
using namespace std;
#define maxSize 1000

class Stack
{
    int top=-1;
public:
    string A[maxSize];
    void push(string x);
    void pop();
    bool isEmpty();
    int size();
};

class Check {
public:
	void loopDepth(string code);
	void keyWords(string code);
	void Identifier(string code);
	void Constant(string code);
	void Operators(string code);
	void Delimiter(string code);
	void syntaxError(string code);

	Check() {}
};


#endif /* PA3_H_ */
