// ---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop
#include <ctime>
#include <iostream>
#include <fstream>
#include <vector>
#include "Thread1.h"
#include "Unit1.h"
#pragma package(smart_init)

using namespace std;
// ---------------------------------------------------------------------------

// Important: Methods and properties of objects in VCL can only be
// used in a method called using Synchronize, for example:
//
// Synchronize(&UpdateCaption);
//
// where UpdateCaption could look like:
//
// void __fastcall CalculateThread::UpdateCaption()
// {
// Form1->Caption = "Updated in a thread";
// }
// ---------------------------------------------------------------------------

__fastcall CalculateThread::CalculateThread(bool CreateSuspended)
	: TThread(CreateSuspended) {
	MaxWordLength = StrToInt(Form1->Edit2->Text);
}

void __fastcall CalculateThread::NewPoint() {
	Form1->Series1->Add(MaxCountOnThisLength, length);
}

// ---------------------------------------------------------------------------
void __fastcall CalculateThread::Execute() {
	int Q, counter, position;
	String s;
	int k, j, i;
	length = 0;
	MaxCountOnThisLength = 0;
	char * word = new char[0 + 3];
	std::ofstream vmdelet_out;
	vmdelet_out.open("logONE.txt", std::ios::trunc | std::ios::out);
	i = 2;
	const string literals = "abc"; // любая последовательность символов, неважно
	const int literalslen = literals.length();

	while (!Terminated && length <= MaxWordLength) {

		if (i == 3 || i == 9 || i == 27 || i == 81 || i == 243 || i == 729 ||
			i == 2187 || i == 6561 || i == 19683 || i == 59049 || i == 177147 ||
			i == 531441 || i == 1594323 || i == 4782969 || i == 14348907) {
			Synchronize(&NewPoint);
			MaxCountOnThisLength = 0;
			delete[]word;
			length = (int)(log((float)i) / log((float)literalslen));
			vmdelet_out << endl << "Len: " << length << endl;
			word = new char[length + 3];
			i = (int)(pow((float)literalslen,
				(int)(log((float)i) / log((float)literalslen)) + 1) -
				pow((float)literalslen,
				(int)(log((float)i) / log((float)literalslen))));
		}
		if (length == 8) {
			s = "";
		}

		s = "";

		k = i;

		do {
			s = s + literals[k % literalslen];
			k /= literalslen;

		}
		while (k - literalslen > 0);
		// -3 чтобы не брать наибольший разряд для того чтобы не терять комбинации начинающиеся с 0
		s = "_" + s + "_";
		copy(s.begin(), s.end(), word);
		word[s.Length()] = '\0';

		if (i == 2) {
			word[0] = '_';
			word[1] = '_';
			word[2] = '\0';
		}
		vmdelet_out << endl << endl << word << endl;
		Q = 1;
		position = 1;
		counter = 0;
		while (Q != -1) {
			// vmdelet_out << endl << endl << word << endl;
			s = "";
			// int temppos=position;
			for (int i = 0; i < length + 2; i++) {
				if (i != position) {
					s += word[i];
				}
				else {
					s += "(Q" + IntToStr(Q - 1) + ")" + "" + (String)word[i];
				}

			}
			vmdelet_out << (AnsiString(s)) << endl;

			switch (Q) {
			case 1:
				switch (word[position]) {
				case 'a':
					word[position] = '0' ;
					position++;
					Q = 2;
					break;
				case 'b':
					word[position] = 'b';
					position++;
					Q = 12;
					break;
				case 'c':
					word[position] = 'c';
					position++;
					Q = 12;
					break;
				case '0':
					word[position] = '0';
					position++;
					Q = 12 ;
					break;
				case '*':
					word[position] = '*';
					position++;
					Q = 4;
					break;
				case '1':
					word[position] = '1';
					position++;
					Q = 12  ;
					break;
				case '_':
					word[position] = '-';
					Q = -1;
					break;
				}
				break;
			case 2:
				switch (word[position]) {
				case 'a':
					word[position] = 'a';
					position++;
					Q = 2;
					break;
				case 'b':
					word[position] = '*';
					position--;
					Q = 3;
					break;
				case 'c':
					word[position] = 'c';
					position++;
					Q = 12;
					break;
				case '0':
					word[position] = '0';
					position++;
					Q = 12;
					break;
				case '*':
					word[position] = '*';
					position++;
					Q = 2;
					break;
				case '1':
					word[position] = '1';
					position++;
					Q = 2;
					break;
				case '_':
					word[position] = '_';
					position--;
					Q = 13;
					break;
				}
				break;
			case 3:
				switch (word[position]) {
				case 'a':
					word[position] = 'a';
					position--;
					Q = 3;
					break;
				case 'b':
					word[position] = 'b';
					position++;
					Q = 12;
					break;
				case 'c':
					word[position] = 'c';
					position++;
					Q = 12;
					break;
				case '0':
					word[position] = '0';
					position++;
					Q = 1;
					break;
				case '*':
					word[position] = '*';
					position--;
					Q = 3;
					break;
				case '1':
					word[position] = '1';
					position++;
					Q = 12;
					break;
				case '_':
					word[position] = '_';
					position--;
					Q = 13;
					break;
					 }
				break;
			case 4:
				switch (word[position]) {
				case 'a':
					word[position] = 'a';
					position++;
					Q = 12;
					break;
				case 'b':
					word[position] = 'b';
					position++;
					Q = 4;
					break;
				case 'c':
					word[position] = '0';
					position--;
					Q = 5;
					break;
				case '0':
					word[position] = '0';
					position++;
					Q = 12;
					break;
				case '*':
					word[position] = '*';
					position++;
					Q = 4;
					break;
				case '1':
					word[position] = '1';
					position++;
					Q = 12;
					break;
				case '_':
					word[position] = '_';
					position--;
					Q = 13;
					break;
					}
				break;
			case 5:
				switch (word[position]) {
				case 'a':
					word[position] = 'a';
					position++;
					Q = 12;
					break;
				case 'b':
					word[position] = '*';
					position++;
					Q = 6;
					break;
				case 'c':
					word[position] = 'c';
					position++;
					Q = 12;
					break;
				case '0':
					word[position] = '0';
					position--;
					Q = 5;
					break;
				case '*':
					word[position] = '*';
					position--;
					Q = 5;
					break;
				case '1':
					word[position] = '1';
					position++;
					Q = 12;
					break;
				case '_':
					word[position] = '_';
					position++;
					Q = 13;
					break;
				}
				break;
			case 6:
				switch (word[position]) {
				case 'a':
					word[position] = 'a';
					position++;
					Q = 12;
					break;
				case 'b':
					word[position] = 'b';
					position++;
					Q = 12;
					break;
				case 'c':
					word[position] = '0';
					position--;
					Q = 5;
					break;
				case '0':
					word[position] = '0';
					position++;
					Q = 6;
					break;
				case '*':
					word[position] = '*';
					position++;
					Q = 6;
					break;
				case '1':
					word[position] = '1';
					position++;
					Q = 12;
					break;
				case '_':
					word[position] = '_';
					position--;
					Q = 7;
					break;
				}
				break;
			case 7:
				switch (word[position]) {
				case 'a':
					word[position] = '_';
					position--;
					Q = 11;
					break;
				case 'b':
					word[position] = '1';
					position--;
					Q = 8;
					break;
				case 'c':
					word[position] = 'c';
					position++;
					Q = 12;
					break;
				case '0':
					word[position] = '_';
					position--;
					Q = 7;
					break;
				case '*':
					word[position] = '_';
					position--;
					Q = 7;
					break;
				case '1':
					word[position] = '_';
					position--;
					Q = 7;
					break;
				case '_':
					word[position] = '_';
					position++;
					Q = 13;
					break;
				}
				break;
			case 8:
			switch (word[position]) {
				case 'a':
					word[position] = 'a';
					position--;
					Q = 8;
					break;
				case 'b':
					word[position] = 'b';
					position--;
					Q = 8;
					break;
				case 'c':
					word[position] = 'c';
					position++;
					Q = 12;
					break;
				case '0':
					word[position] = 'a';
					position++;
					Q = 9;
					break;
				case '*':
					word[position] = '*';
					position--;
					Q = 8;
					break;
				case '1':
					word[position] = '1';
					position++;
					Q = 12;
					break;
				case '_':
					word[position] = '_';
					position++;
					Q = 10;
					break;
				}
				break;
			case 9:
				switch (word[position]) {
				case 'a':
					word[position] = 'a';
					position++;
					Q = 9;
					break;
				case 'b':
					word[position] = 'b';
					position++;
					Q = 9;
					break;
				case 'c':
					word[position] = 'c';
					position++;
					Q = 12;
					break;
				case '0':
					word[position] = '0';
					position++;
					Q = 12;
					break;
				case '*':
					word[position] = '*';
					position++;
					Q = 9;
					break;
				case '1':
					word[position] = '1';
					position++;
					Q = 6;
					break;
				case '_':
					word[position] = '_';
					position--;
					Q = 13;
					break;
				}
				break;
			case 10:
				switch (word[position]) {
				case 'a':
					word[position] = 'a';
					position++;
					Q = 10;
					break;
				case '*':
					word[position] = '*';
					position++;
					Q = 10;
					break;
				case '1':
					word[position] = '1';
					position++;
					Q = 10;
					break;
				case 'b':
					word[position] = 'b';
					Q = 12;
					break;
				case '0':
					word[position] = '0';
					Q = 12;
					break;
				case '_':
					word[position] = '_';
					position--;
					Q = 11;
					break;
				}
				break;
			case 11:
				switch (word[position]) {
				case 'a':
					word[position] = '_';
					position--;
					Q = 11;
					break;
				case '*':
					word[position] = '_';
					position--;
					Q = 11;
					break;
				case '1':
					word[position] = '_';
					position--;
					Q = 11;
					break;
                case '0':
					word[position] = '0';
					Q = 12;
					break;
				case '_':
					word[position] = '+';
					Q = -1;
					break;
				}
				break;
			case 12:
				switch (word[position]) {
				case 'a':
					word[position] = 'a';
					position++;
					Q = 12;
					break;
				case 'b':
					word[position] = 'b';
					position++;
					Q = 12;
					break;
				case 'c':
					word[position] = 'c';
					position++;
					Q = 12;
					break;
				case '0':
					word[position] = '0';
					position++;
					Q = 12;
					break;
				case '*':
					word[position] = '*';
					position++;
					Q = 12;
					break;
				case '1':
					word[position] = '1';
					position++;
					Q = 12;
					break;
				case '_':
					word[position] = '_';
					position--;
					Q = 13;
					break;
				}
				break;
			case 13:
				switch (word[position]) {
				case 'a':
					word[position] = '_';
					position--;
					Q = 13;
					break;
				case 'b':
					word[position] = '_';
					position--;
					Q = 13;
					break;
				case 'c':
					word[position] = '_';
					position--;
					Q = 13;
					break;
				case '0':
					word[position] = '_';
					position--;
					Q = 13;
					break;
				case '*':
					word[position] = '_';
					position--;
					Q = 13;
					break;
				case '1':
					word[position] = '_';
					position--;
					Q = 13;
					break;
				case '_':
					word[position] = '-';
					Q = -1;
					break;
				}
				break;
			}

			counter++;
		}
		if (counter > MaxCountOnThisLength) {
			MaxCountOnThisLength = counter;
		}
		vmdelet_out << word << "    ";
		vmdelet_out << counter << endl;
		i++;
	}

	vmdelet_out.close();
	Form1->Button6->Enabled = true;
	Form1->Button7->Enabled = false;
	Form1->Button8->Enabled = false;
}

// ---------------------------------------------------------------------------
