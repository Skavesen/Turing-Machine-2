// ---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop
#include <ctime>
#include <iostream>
#include <fstream>
#include <vector>
#include "Thread2.h"
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
// void __fastcall MultiTape::UpdateCaption()
// {
// Form1->Caption = "Updated in a thread";
// }
// ---------------------------------------------------------------------------

__fastcall MultiTape::MultiTape(bool CreateSuspended) : TThread(CreateSuspended)
{
	MaxWordLength = StrToInt(Form1->Edit2->Text);
}

// ---------------------------------------------------------------------------
void __fastcall MultiTape::NewPoint() {
	Form1->Series2->Add(MaxCountOnThisLength, length);
}

void __fastcall MultiTape::Execute() {
	int Q, counter, position_on_tape_1, position_on_tape_2;
	String s;
	int k, j, i;
	length = 0;
	MaxCountOnThisLength = 0;
	char * tape_1 = new char[0 + 3];
	char * tape_2 = new char[0 + 3];
	std::ofstream vmdelet_out; // создаем поток
	vmdelet_out.open("logMULTI.txt", std::ios::trunc | std::ios::out);
	const string literals = "abc"; // любая последовательность символов, неважно
	const int literalslen = literals.length();
	i = 2;

	while (!Terminated && length <= MaxWordLength) {
		if (i == 3 || i == 9 || i == 27 || i == 81 || i == 243 || i == 729 ||
			i == 2187 || i == 6561 || i == 19683 || i == 59049 || i == 177147 ||
			i == 531441 || i == 1594323 || i == 4782969 || i == 14348907) {
			Synchronize(&NewPoint);
			MaxCountOnThisLength = 0;
			length = (int)(log((float)i) / log((float)literalslen));
			vmdelet_out << endl << "Len: " << length << endl;
			delete[]tape_1;
			tape_1 = new char[1 + 3];
			delete[]tape_2;
			tape_2 = new char[1 + 3];
			i = (int)(pow((float)literalslen,
				(int)(log((float)i) / log((float)literalslen)) + 1) -
				pow((float)literalslen,
				(int)(log((float)i) / log((float)literalslen))));
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
		copy(s.begin(), s.end(), tape_1);
		tape_1[s.Length()] = '\0';
		for (int i = 0; i < s.Length(); i++) {
			tape_2[i] = '_';
		}
		if (i == 2) {
			tape_1[0] = '_';
			tape_1[1] = '_';
			tape_1[2] = '\0';
		}
		vmdelet_out << endl << endl << tape_1 << endl;
		Q = 0;
		position_on_tape_1 = 1;
		position_on_tape_2 = 1;
		counter = 0;
		while (Q != -1) {

			s = "";
			// int temppos=position;
			for (int i = 0; i < length + 2; i++) {
				if (i != position_on_tape_1) {
					s += tape_1[i];
				}
				else {
					s += "(Q" + IntToStr(Q) + ")" + "" + (String)tape_1[i];
				}

			}
			vmdelet_out << (AnsiString(s)) << endl;

			s = "";
			// int temppos=position;
			for (int i = 0; i < length + 2; i++) {
				if (i != position_on_tape_2) {
					s += tape_2[i];
				}
				else {
					s += "(Q" + IntToStr(Q) + ")" + "" + (String)tape_2[i];
				}

			}
			vmdelet_out << (AnsiString(s)) << endl;
			vmdelet_out << "--------------------" << endl;

			switch (Q) {
			case 0:
				if (tape_1[position_on_tape_1] == 'a' && tape_2
					[position_on_tape_2] == '_') {
					tape_1[position_on_tape_1] = 'a';
					tape_2[position_on_tape_2] = 'a';
					position_on_tape_1++;
					position_on_tape_2++;
					Q = 0;

				}
				else if (tape_1[position_on_tape_1] == 'b' && tape_2
					[position_on_tape_2] == '_') {
					tape_1[position_on_tape_1] = 'b';
					tape_2[position_on_tape_2] = '_';
					position_on_tape_2--;
					Q = 1;

				}
                else if (tape_1[position_on_tape_1] == '_' && tape_2
					[position_on_tape_2] == '_') {
					tape_1[position_on_tape_1] = '_';
					tape_2[position_on_tape_2] = '_';
					position_on_tape_1--;
					Q = 7;

				}
				else if (tape_1[position_on_tape_1] == 'c' && tape_2
					[position_on_tape_2] == '_') {
					tape_1[position_on_tape_1] = 'c';
					tape_2[position_on_tape_2] = '_';
					Q = 6;

				}
				break;
			case 1:
				if (tape_1[position_on_tape_1] == 'b' && tape_2
					[position_on_tape_2] == 'a') {
					tape_1[position_on_tape_1] = 'b';
					tape_2[position_on_tape_2] = 'a';
					position_on_tape_1++;
					position_on_tape_2--;
					Q = 1;
				}
				else if (tape_1[position_on_tape_1] == 'a' && tape_2
					[position_on_tape_2] == 'a') {
					tape_1[position_on_tape_1] = 'a';
					tape_2[position_on_tape_2] = '_';
					Q = 6;
				}
				else if (tape_1[position_on_tape_1] == 'a' && tape_2
					[position_on_tape_2] == '_') {
					tape_1[position_on_tape_1] = 'a';
					tape_2[position_on_tape_2] = '_';
					Q = 6;
				}
				else if (tape_1[position_on_tape_1] == 'c' && tape_2
					[position_on_tape_2] == 'a') {
					tape_1[position_on_tape_1] = 'c';
					tape_2[position_on_tape_2] = '_';
					Q = 6;
				}
				else if (tape_1[position_on_tape_1] == 'c' && tape_2
					[position_on_tape_2] == '_') {
					tape_1[position_on_tape_1] = 'c';
					tape_2[position_on_tape_2] = '_';
					Q = 6;
				}
				else if (tape_1[position_on_tape_1] == '_' && tape_2
					[position_on_tape_2] == 'a') {
					tape_1[position_on_tape_1] = '_';
					tape_2[position_on_tape_2] = '_';
					position_on_tape_1--;
					Q = 7;
				}
				else if (tape_1[position_on_tape_1] == '_' && tape_2
					[position_on_tape_2] == '_') {
					tape_1[position_on_tape_1] = '_';
					tape_2[position_on_tape_2] = '_';
					position_on_tape_1--;
					Q = 7;
				}
				else if (tape_1[position_on_tape_1] == 'b' && tape_2
					[position_on_tape_2] == '_') {
					tape_1[position_on_tape_1] = 'b';
					tape_2[position_on_tape_2] = '_';
					position_on_tape_2++;
					Q = 2;
				}
				break;
			case 2:
				if (tape_1[position_on_tape_1] == 'b' && tape_2
					[position_on_tape_2] == 'a') {
					tape_1[position_on_tape_1] = 'b';
					tape_2[position_on_tape_2] = '_';
					position_on_tape_1++;
					position_on_tape_2++;
					Q = 2;

				}
				else if (tape_1[position_on_tape_1] == 'b' && tape_2
					[position_on_tape_2] == '_') {
					tape_1[position_on_tape_1] = 'b';
					tape_2[position_on_tape_2] = 'b';
					position_on_tape_1++;
					position_on_tape_2++;
					Q = 3;

				}
				else if (tape_1[position_on_tape_1] == 'c' && tape_2
					[position_on_tape_2] == 'a') {
					tape_1[position_on_tape_1] = 'c';
					tape_2[position_on_tape_2] = '_';
					Q = 6;
				}
				else if (tape_1[position_on_tape_1] == 'c' && tape_2
					[position_on_tape_2] == '_') {
					tape_1[position_on_tape_1] = 'c';
					tape_2[position_on_tape_2] = '_';
					Q = 6;
				}
				else if (tape_1[position_on_tape_1] == 'a' && tape_2
					[position_on_tape_2] == 'a') {
					tape_1[position_on_tape_1] = 'a';
					tape_2[position_on_tape_2] = '_';
					Q = 6;
				}
				else if (tape_1[position_on_tape_1] == 'a' && tape_2
					[position_on_tape_2] == '_') {
					tape_1[position_on_tape_1] = 'a';
					tape_2[position_on_tape_2] = '_';
					Q = 6;
				}
				else if (tape_1[position_on_tape_1] == '_' && tape_2
					[position_on_tape_2] == '_') {
					tape_1[position_on_tape_1] = '_';
					tape_2[position_on_tape_2] = '_';
					position_on_tape_1--;
					Q = 6;
				}
                else if (tape_1[position_on_tape_1] == '_' && tape_2
					[position_on_tape_2] == 'a') {
					tape_1[position_on_tape_1] = '_';
					tape_2[position_on_tape_2] = '_';
					position_on_tape_1--;
					Q = 7;
				}
				break;
			case 3:
				if (tape_1[position_on_tape_1] == 'b' && tape_2
					[position_on_tape_2] == '_') {
					tape_1[position_on_tape_1] = 'b';
					tape_2[position_on_tape_2] = 'b';
					position_on_tape_1++;
					position_on_tape_2++;
					Q = 3;
				}
				else if (tape_1[position_on_tape_1] == 'c' && tape_2
					[position_on_tape_2] == '_') {
					tape_1[position_on_tape_1] = 'c';
					tape_2[position_on_tape_2] = '_';
					position_on_tape_2--;
					Q = 4;
				}
				else if (tape_1[position_on_tape_1] == 'a' && tape_2
					[position_on_tape_2] == '_') {
					tape_1[position_on_tape_1] = 'a';
					tape_2[position_on_tape_2] = '_';
					Q = 6;
				}
					else if (tape_1[position_on_tape_1] == '_' && tape_2
					[position_on_tape_2] == '_') {
					tape_1[position_on_tape_1] = '_';
					tape_2[position_on_tape_2] = '_';
					position_on_tape_1--;
					Q = 7;
				}
				break;
			case 4:
				if (tape_1[position_on_tape_1] == 'c' && tape_2
					[position_on_tape_2] == 'b') {
					tape_1[position_on_tape_1] = 'c';
					tape_2[position_on_tape_2] = '_';
					position_on_tape_1++;
					position_on_tape_2--;
					Q = 4;
				}
				else if (tape_1[position_on_tape_1] == '_' && tape_2
					[position_on_tape_2] == '_') {
					tape_1[position_on_tape_1] = '_';
					tape_2[position_on_tape_2] = '_';
					position_on_tape_1--;
					Q = 5;
				}
				else if (tape_1[position_on_tape_1] == 'a' && tape_2
					[position_on_tape_2] == 'b') {
					tape_1[position_on_tape_1] = 'a';
					tape_2[position_on_tape_2] = '_';
					Q = 6;

				}
				else if (tape_1[position_on_tape_1] == 'b' && tape_2
					[position_on_tape_2] == 'b') {
					tape_1[position_on_tape_1] = 'b';
					tape_2[position_on_tape_2] = '_';
					Q = 6;

				}
                else if (tape_1[position_on_tape_1] == 'a' && tape_2
					[position_on_tape_2] == '_') {
					tape_1[position_on_tape_1] = 'a';
					tape_2[position_on_tape_2] = '_';
					Q = 6;

				}
				 else if (tape_1[position_on_tape_1] == 'b' && tape_2
					[position_on_tape_2] == '_') {
					tape_1[position_on_tape_1] = 'b';
					tape_2[position_on_tape_2] = '_';
					Q = 6;

				}
				else if (tape_1[position_on_tape_1] == 'c' && tape_2
					[position_on_tape_2] == '_') {
					tape_1[position_on_tape_1] = 'c';
					tape_2[position_on_tape_2] = '_';
					Q = 6;

				}
				else if (tape_1[position_on_tape_1] == '_' && tape_2
					[position_on_tape_2] == 'b') {
					tape_1[position_on_tape_1] = '_';
					tape_2[position_on_tape_2] = '_';
					position_on_tape_1--;
					Q = 7;

				}
				break;
			case 5:
				if (tape_1[position_on_tape_1] == 'c' && tape_2
					[position_on_tape_2] == '_') {
					tape_1[position_on_tape_1] = '_';
					tape_2[position_on_tape_2] = '_';
					position_on_tape_1--;
					Q = 5;

				}
				else if (tape_1[position_on_tape_1] == 'b' && tape_2
					[position_on_tape_2] == '_') {
					tape_1[position_on_tape_1] = '_';
					tape_2[position_on_tape_2] = '_';
					position_on_tape_1--;
					Q = 5;

				}
				else if (tape_1[position_on_tape_1] == 'a' && tape_2
					[position_on_tape_2] == '_') {
					tape_1[position_on_tape_1] = '_';
					tape_2[position_on_tape_2] = '_';
					position_on_tape_1--;
					Q = 5;

				}
				else if (tape_1[position_on_tape_1] == '_' && tape_2
					[position_on_tape_2] == '_') {
					tape_1[position_on_tape_1] = '+';
					tape_2[position_on_tape_2] = '_';
					Q = -1;

				}
				break;
			case 6:
				if (tape_1[position_on_tape_1] == 'c' && tape_2
					[position_on_tape_2] == '_') {
					tape_1[position_on_tape_1] = 'c';
					tape_2[position_on_tape_2] = '_';
					position_on_tape_1++;
					Q = 6;

				}
				else if (tape_1[position_on_tape_1] == 'b' && tape_2
					[position_on_tape_2] == '_') {
					tape_1[position_on_tape_1] = 'b';
					tape_2[position_on_tape_2] = '_';
					position_on_tape_1++;
					Q = 6;

				}
				else if (tape_1[position_on_tape_1] == 'a' && tape_2
					[position_on_tape_2] == '_') {
					tape_1[position_on_tape_1] = 'a';
					tape_2[position_on_tape_2] = '_';
					position_on_tape_1++;
					Q = 6;

				}
				else if (tape_1[position_on_tape_1] == '_' && tape_2
					[position_on_tape_2] == '_') {
					tape_1[position_on_tape_1] = '_';
					tape_2[position_on_tape_2] = '_';
					position_on_tape_1--;
					Q = 7;

				}
				break;
			case 7:
				if (tape_1[position_on_tape_1] == 'c' && tape_2
					[position_on_tape_2] == '_') {
					tape_1[position_on_tape_1] = '_';
					tape_2[position_on_tape_2] = '_';
					position_on_tape_1--;
					Q = 7;

				}
				else if (tape_1[position_on_tape_1] == 'b' && tape_2
					[position_on_tape_2] == '_') {
					tape_1[position_on_tape_1] = '_';
					tape_2[position_on_tape_2] = '_';
					position_on_tape_1--;
					Q = 7;

				}
				else if (tape_1[position_on_tape_1] == 'a' && tape_2
					[position_on_tape_2] == '_') {
					tape_1[position_on_tape_1] = '_';
					tape_2[position_on_tape_2] = '_';
					position_on_tape_1--;
					Q = 7;

				}
				else if (tape_1[position_on_tape_1] == '_' && tape_2
					[position_on_tape_2] == '_') {
					tape_1[position_on_tape_1] = '-';
					tape_2[position_on_tape_2] = '_';
					Q = -1;

				}
				break;
			}

			counter++;
		}

		if (counter > MaxCountOnThisLength) {
			MaxCountOnThisLength = counter;
		}
		vmdelet_out << tape_1 << "    ";
		vmdelet_out << counter << endl;
		vmdelet_out << tape_2 << endl;
		vmdelet_out <<
			"_______________________________________________" << endl;
		i++;
	}
	vmdelet_out.close();
	Form1->Button6->Enabled = true;
	Form1->Button7->Enabled = false;
	Form1->Button8->Enabled = false;
}
// ---------------------------------------------------------------------------
