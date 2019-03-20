#include<iostream>
#include <fstream>
#include <string>
#include<stack>
using namespace std;
#include"pa3.h"
#define maxSize 1000

void Stack::push(string x){
if(top==maxSize-1){
	cout<<"Stack overflow!"<<endl;
	return;
}
      A[++top]=x;
}

void Stack::pop(){
if(top==-1){
	cout<<"Stack underflow! No element to pop."<<endl;
	return;
}
     top--;
}

bool Stack::isEmpty(){
	if(top==-1){
		return true;
	}
	else{
		return false;
	}
}

int Stack::size(){
	int a=top+1;
	return a;
}

void Check::loopDepth(string code){
	    int a=0;
		struct Stack s;
		int count = 0;

		for (int temp=0;temp < code.size() - 1;temp++)
		{
			int initialPoint = temp;
			while (code.at(temp) >= 'A'&& code.at(temp) <= 'Z')
			{
				count++;
				temp++;
			}
			if (count!=0)
			{
				string test = code.substr(initialPoint, count);
				if (test.compare("BEGIN") == 0||test.compare("BEGAN")==0)
				{
					s.push(test);
				}
				if (test.compare("END") == 0)
				{

					if (s.isEmpty() == false)
					{
						s.push(test);
					}
				}
				count = 0;
			}
		}
		if(s.size()%2==0){
		if(code.find("BEGAN")!=-1){
			a=(s.size()-2)/2-1;
		}
		else{ a=s.size()/2-1;}
		}
		else{a=0;}
		cout << "The depth of nested loop(s) is: "<<endl;
		cout << a << endl;
}

void Check::keyWords(string code){
	    string W = "";

		if (code.find("BEGIN") != code.npos) {
			W = W + "BEGIN" + ' ';
		}
		if (code.find("END") != code.npos) {
			W = W + "END" + ' ';
		}
		if (code.find("FOR") != code.npos) {
			W = W + "FOR" + ' ';
		}
		cout << "Keyword: "<<endl;
		cout << W << endl;

		return;
}

void Check::Identifier(string code){
	    int c = 0;
		string identifier;
        string str;

		for (int a = 0; a<code.size() - 1; a++)
		{
			int b = a;
			while(code.at(a) >= 'a' && code.at(a) <= 'z')
			{
				c++;
				a++;
			}
			if (c!= 0)
			{
				str = code.substr(b, c);
				if (identifier.find(str) == identifier.npos)
				{
					identifier += "  ";
					identifier += str;
				}
				c = 0;
			}
		}
		cout << "Identifier: "<<endl;
		cout << identifier << endl;

		return;

}

void Check::Constant(string code){
		string C;
        string str;
		int b = 0;

		for (int a = 0; a<code.size() - 1; a++)
		{
			int initialPoint = a;
			while (code.at(a) >= '0' && code.at(a) <= '9')
			{
				b++;
				a++;
			}
			if (b!=0)
			{
				str = code.substr(initialPoint, b);
				if (C.find(str) == C.npos)
				{
					C += "  ";
					C += str;
				}
				b = 0;
			}
		}
		cout << "Constant: "<<endl;
		cout << C << endl;
}

void Check::Operators(string code){
	    string operators = "";
		if (code.find("+") != code.npos) {
			operators = operators + "+" + ' ';
		}
		if (code.find("-") != code.npos) {
			operators = operators + "-" + ' ';
		}
		if (code.find("*") != code.npos) {
			operators = operators + "*" + ' ';
		}
		if (code.find("/") != code.npos) {
			operators = operators + "/" + ' ';
		}
		if (code.find("++") != code.npos) {
			operators = operators + "++" + ' ';
		}
		if (code.find("=") != code.npos) {
			operators = operators + "=" + ' ';
		}
		if (code.find("--") != code.npos) {
			operators = operators + "--" + ' ';
		}
		if (code.find("==") != code.npos) {
			operators = operators + "==" + ' ';
		}
		if (code.find("<") != code.npos) {
			operators = operators + "<" + ' ';
		}
		if (code.find(">") != code.npos) {
			operators = operators + ">" + ' ';
		}

		cout << "Operators: "<<endl;
		cout << operators << endl;

		return;
}

void Check::Delimiter(string code){
	    string delimiter = "";

		if (code.find(";") != code.npos) {
			delimiter = delimiter + ";" + ' ';
		}
		if (code.find(",") != code.npos) {
			delimiter = delimiter + "," + ' ';
		}

		cout << "Delimiter: "<<endl;
		cout << delimiter << endl;

		return;
}

void Check::syntaxError(string code){
	    string error;
		int start = 0;
		string test;
		struct Stack s1;
		int c = 0;
		char  keywords[10][10] = { "FOR","BEGIN","END" };

		for (int i = 0; i < code.size() - 1; i++)
		{
			start = i;
			while (code.at(i) >= 'A' && code.at(i) <= 'Z')
			{
				c++;
				i++;
			}
			if (c != 0)
			{
				test = code.substr(start, c);

				if (test.compare("BEGIN") == 0)
				{
					s1.push(test);
				}

				if (s1.isEmpty() == false) {
			         if (test.compare("END") == 0)
					{
						s1.pop();
					}
                 }
				     else if (s1.isEmpty() == true) {
						if (test.compare("END") == 0){
					 	error += "BEGIN";
				          }
			          }

					string str = code.substr(start, c);
					bool f = true;
					for (int i = 0; i<3; i++)
					{
						if (str.compare(keywords[i]) == 0)
						{
							f = false;
							break;
						}
					}
						if (f)
						{
							string temp;
							temp.append(str);
							temp.append(" ");
							error += temp;
						}
				c = 0;
			}
		}

		if (s1.isEmpty() == false)
		{
			error += "END";
		}

		stack<char>s2;
		int count =0;
		char left = '(';
		char right=')';
		while(count<code.size()){
			if(code.at(count)==left){
				s2.push(left);
			}
			if(code.at(count)==right){
				if(s2.empty()==false){
					s2.pop();
				}
			    if(s2.empty()==true && code.at(count+1)==right){
				error+=")";
			     }
			}
			count++;
		}
		if(s2.empty()==false){
			error+="(";
		}

		cout << "Syntax Error(s): "<<endl;
		if (error == " ")
		{
			error == "NA";
		}
	    if (error.find_first_not_of(" ") == string::npos)
		{
			error += "NA";
		}
		cout << error << endl;

		return;
}

int main(){

	cout<<"Please enter the name of the input file:"<<endl;
	string fileName;
	cin>>fileName;

	string t;
	string code;
	ifstream myfile (fileName);
	if (!myfile){
	cout<<"Sorry, file can't open."<<endl;}
	while ( getline (myfile,t) ) {
		code += t + " ";
	}
	myfile.close();

	Check *output=new Check();

			output->loopDepth(code);
			output->keyWords(code);
			output->Identifier(code);
			output->Constant(code);
			output->Operators(code);
			output->Delimiter(code);
			output->syntaxError(code);

	return 0;
}
