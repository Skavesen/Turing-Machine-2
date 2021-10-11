// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <ctime>
#include <iostream>
#include <fstream>
#include <vector>
#include "Unit1.h"
#include <math.h>
#include "Thread1.h"
#include "Thread2.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
using namespace std;
TForm1 *Form1;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender) {
	Memo1->Lines->Clear();
	String s = "_" + Edit1->Text + "_";
	char* word = new char[s.Length() + 1];
	copy(s.begin(), s.end(), word);
	word[s.Length()] = '\0';
	int length = s.Length();
	int Q, counter, position;
	Q = 1;
	position = 1;
	counter = 0;
	while (Q != -1) {
		Memo1->Lines->Add(IntToStr(counter) + ":");

		s = "";
		for (int i = 0; i < length + 2; i++) {
			if (i != position) {
				s += word[i];
			}
			else {
				s += "(Q" + IntToStr(Q - 1) + ")" + "" + (String)word[i];
			}

		}
		Memo1->Lines->Add(s);

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
	Memo1->Lines->Add(word);
	Memo1->Lines->Add(IntToStr(counter));
	Memo1->Lines->SaveToFile("WordOnOneTapeMT.txt");
}

// ---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender) {
	Memo1->Lines->Clear();
	String s = "_" + Edit1->Text + "_";
	char* tape_1 = new char[s.Length() + 1];
	char* tape_2 = new char[s.Length() + 1];
	copy(s.begin(), s.end(), tape_1);
	tape_1[s.Length()] = '\0';
	for (int i = 0; i < s.Length(); i++) {
		tape_2[i] = '_';
	}
	int length = s.Length();
	int Q, counter, position_on_tape_1, position_on_tape_2;
	Q = 0;
	position_on_tape_1 = 1;
	position_on_tape_2 = 1;
	counter = 0;
	while (Q != -1) {

		Memo1->Lines->Add(IntToStr(counter) + ":");

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
		Memo1->Lines->Add(AnsiString(s));

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
		Memo1->Lines->Add(AnsiString(s));

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
	Memo1->Lines->Add(tape_1);
	Memo1->Lines->Add(tape_2);
	Memo1->Lines->Add(IntToStr(counter));
	Memo1->Lines->SaveToFile("WordOnMultiTapeMT.txt");

}
// ---------------------------------------------------------------------------

CalculateThread * Thread1;

MultiTape *Thread2;

void __fastcall TForm1::Button6Click(TObject *Sender) {
	Series1->Clear();
	Series2->Clear();
	Thread1 = new CalculateThread(false);
	Thread1->FreeOnTerminate = true;
	Thread2 = new MultiTape(false);
	Thread2->FreeOnTerminate = true;
	Button6->Enabled = false;
	Button7->Enabled = true;
	Button8->Enabled = true;
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender) {
	Thread1->Terminate();
	Thread2->Terminate();
	Button6->Enabled = true;
	Button7->Enabled = false;
	Button8->Enabled = false;

}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender) {

	if (Thread1 != NULL) {
		switch (Thread1->Suspended) {

		case true:
			Thread1->Resume();
			Button8->Caption = (wchar_t)0x23F8;
			break;

		case false:
			Thread1->Suspend();
			Button8->Caption = (wchar_t)0x23EF;
			break;
		}
		switch (Thread2->Suspended) {

		case true:
			Thread2->Resume();
			break;

		case false:
			Thread2->Suspend();
			break;
		}

	}
}

// ---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action) {
	Application->Terminate();
	RemoveFontResource((wchar_t*)"BOYAR.TTF");
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Edit2Change(TObject *Sender) {
	try {
		if (StrToInt(Edit2->Text) > 13 || StrToInt(Edit2->Text) < 1) {
			Edit2->Text = "1";
		}
	}
	catch (...) {
		if (Edit2->Text != "") {
			Edit2->Text = "1";
		}
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Edit1Change(TObject *Sender) {
	String s = Edit1->Text;
	char * word = new char[s.Length() + 1];
	copy(s.begin(), s.end(), word);
	word[s.Length()] = '\0';

	for (int i = 0; i < s.Length(); i++) {
		if (!(word[i] == 'a' || word[i] == 'b' || word[i] == 'c')) {
			Edit1->Text = "";
			i = 99999;
		}
	}

}
// ---------------------------------------------------------------------------

const string literals = "abc"; // любая последовательность символов, неважно
const int literalslen = literals.length();

static string ConvertFrom(int num) {
	// размер буфера можно вычислить по логарифму
	// длина literals - это основание твоей системы счисления
	int bufflen;
	if (num == 0) {
		bufflen = 1;
	}
	else {
		bufflen = (log((float)num) / log((float)literalslen));
	}
	char* buffer = new char[bufflen];
	// далее, обычный способ преобразования, комментировать не нужно я думаю
	int i = bufflen - 1;
	do {
		buffer[i--] = literals[num % literals.length()];
		num /= literals.length();
	}
	while (num > 0);
	return string(buffer);
}


void __fastcall TForm1::FormCreate(TObject *Sender)
{
AddFontResource((wchar_t*)"BOYAR.TTF");
}
//---------------------------------------------------------------------------

