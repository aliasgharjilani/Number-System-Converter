// BinaryConverter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

# include <conio.h>
# include <iostream>
# include <stdlib.h>
# include <fstream>
using namespace std;

struct Dec2All
{
	char* Binary;
	char* Octal;
	char* Hexa;
};

Dec2All DecimalToAll(int);
char* DecimalToBinary(int);
char* DecimalToOctal(int);
char* DecimalToHexadecimal(int);
int bin2dec(int ar[], int);
int oct2dec(int ar[], int);
int hex2dec(int ar[], int);

int main() {

	int bin[50], oct[50], hex[50], op, i = 0, num = 0;
	char repeat = ' ';
	do {
		system("CLS");
		int deci = 0, num = 0;
		ofstream file("///source/repos/BinaryConverter/Binary.txt");
		cout << endl;
		cout << "\tWelcome to Number System Converter" << endl;
		cout << "===========================================================" << endl;
		cout << "\t0\t Decimal to All(Binary, Octal, Hexadecimal) \n\t1\t Decimal to Binary \n\t2\t Decimal to Octal \n\t3\t Decimal to Hexadecimal \n\t4\t Binary to Decimal \n\t5\t Octal to Decimal \n\t6\t Hexadecimal to Decimal \n\t7\t Exit" << endl;
		cout << "===========================================================" << endl;
		cout << "\tSelect operation you want to perform: ";
		cin >> op;
		if (op >= 0 && op <= 7) {
			cout << endl;
			cout << "Enter the number to convert: ";
			if (op == 4) {
				while (true) {
					char input = _getche();
					if (input == '\r')
						break;
					if (input == '0' || input == '1') {
						bin[num] = input - 48;				//Converting character to numeric value 
						num++;
					}
					else {
						cout << "Invalid entry" << endl;
					} // end of if-else
				} // end of while (true)
			}// End of if (op==4)
			else if (op == 5) {
				while (true) {
					char input = _getche();
					if (input == '\r')
						break;
					if (input >= 48 && input <= 55) {
						oct[num] = input - 48;				//Ascii value of 0 is 48 
						num++;
					}
					else {
						cout << "Invalid entry" << endl;
					} // End of if-else
				} // End of While loop
			} // End of if(op==5)
			else if (op == 6) {
				while (true) {
					char input = _getche();
					if (input == '\r')
						break;
					if (input >= 48 && input <= 57) {
						hex[num] = input - 48;				//Ascii value of 0 is 48 
						num++;
					}
					else if (input >= 65 && input <= 70) {
						hex[num] = input - 55;
						num++;
					}
					else if (input >= 97 && input <= 102) {
						hex[num] = input - 87;
						num++;
					}
					else {
						cout << "Invalid entry" << endl;
					} // End of if-else statements
				} //End of while loop
			}
			else if (op == 7) {
				cout << "Thank You for using Number System Converter";
				break;
			}
			else {
				cin >> num;
			} // Closing input

			switch (op) {
			case 0: {
				Dec2All d2a = DecimalToAll(num);
				cout << "Binary = " << d2a.Binary << endl;
				cout << "Octal = " << d2a.Octal << endl;
				cout << "Hexadecimal = " << d2a.Hexa << endl;
			}
				  break;
			case 1: {			// Converting Decimal to Binary 
				cout << "Binary of given decimal is " << DecimalToBinary(num);
				cout << endl;
			}
				  break;			// Closing if Case 1
			case 2: {				// Converting Decimal to Octal
				cout << "Octal of given decimal is " << DecimalToOctal(num);
			}
				  break;				// Closing Case 2
			case 3: {				// Converting Decimal to Hexadecimal
				cout << "Hexadecimal of given decimal is " << DecimalToHexadecimal(num);
				cout << endl;
			}
				  break;			// Ending of Case 3
			case 4:				// Converting Binary to Decimal 
				deci = bin2dec(bin, num);
				cout << endl << "Decimal value of given binary is " << deci << endl;
				break;			// Closing of Case 4
			case 5:				// Converting Octal to Decimal
				deci = oct2dec(oct, num);
				cout << endl << "Decimal value of given Octale is " << deci << endl;
				break;			// Closing Case 5
			case 6:				// Converting Hexadecimal to Decimal
				deci = hex2dec(hex, num);
				cout << "Decimal value of given Hexadecimal is " << deci << endl;
				break;			// Closing of Case 6
			default:			// Opening Default
				cout << "Not a valid number" << endl;
				break;			// Closing Default
			} // end of switch
			cout << endl;
		}
		else {
			cout << "You selected an option which is not mentioned" << endl;
		}							// Closing if-else used on options
		cout << "Do you want to continue?(Y/N) ";
		repeat = _getche();
	} while (repeat == 'y' || repeat == 'Y');		// Closing do-while	loop			
}					// Closing of Main

Dec2All DecimalToAll(int num) {
	Dec2All All;
	All.Binary = DecimalToBinary(num);
	All.Octal = DecimalToOctal(num);
	All.Hexa = DecimalToHexadecimal(num);
	return All;
}

//**************** Function for Decimal to Binary 
char* DecimalToBinary(int num) {
	int bin[50];
	int i = 0;
	ofstream result("C:\\Users\\Jilaniz\\Desktop\\PF\\Binary.txt", ios::app);
	result << "Input = " << num << " Converted Binary Value = ";
	while (num > 0) {
		bin[i] = num % 2;
		num = num / 2;
		i++;
	}
	static char binary[50];
	int k = 0;

	for (int j = i - 1; j >= 0; j--) {
		binary[k] = bin[j] + 48;
		result << binary[k];
		k++;

	}
	result << endl;
	binary[k] = '\0';
	return binary;
	result.close();
}

//**************** Function for Decimal to Octal
char* DecimalToOctal(int num) {
	int oct[50];
	static char octal[50];
	int i = 0;
	ofstream result("C:\\Users\\Jilaniz\\Desktop\\PF\\Octal.txt", ios::app);
	result << "Input = " << num << " Converted Octal Value = ";
	while (num > 0) {
		oct[i] = num % 8;
		num = num / 8;
		i++;
	} // End of While loop
	//cout<<"Octale of the given number = ";   
	int k = 0;
	for (int j = i - 1; j >= 0; j--) {
		octal[k] = oct[j] + 48;
		result << octal[k];
		k++;
	}
	octal[k] = '\0';
	result << endl;
	result.close();
	cout << endl;
	return octal;
}

//**************** Function for Decimal to Hexadecimal
char* DecimalToHexadecimal(int num) {
	int i = 0;
	int hex[50];
	static char Hexa[50];
	ofstream result("C:\\Users\\Jilaniz\\Desktop\\PF\\Hexadecimal.txt", ios::app);
	result << "Input = " << num << " Converted Hexadecimal Value = ";
	while (num > 0) {
		hex[i] = num % 16;
		num = num / 16;
		i++;
	}				// End of While loop
	int k = 0;
	for (int j = i - 1; j >= 0; j--) {
		if (hex[j] == 10) {
			Hexa[k] = 10 + 55;
			result << Hexa[k];
			k++;
		}
		else if (hex[j] == 11) {
			Hexa[k] = 11 + 55;
			result << Hexa[k];
			k++;
		}
		else if (hex[j] == 12) {
			Hexa[k] = 12 + 55;
			result << Hexa[k];
			k++;
		}
		else if (hex[j] == 13) {
			Hexa[k] = 13 + 55;
			result << Hexa[k];
			k++;
		}
		else if (hex[j] == 14) {
			Hexa[k] = 14 + 55;
			result << Hexa[k];
			k++;
		}
		else if (hex[j] == 15) {
			Hexa[k] = 15 + 55;
			result << Hexa[k];
			k++;
		}
		else {
			Hexa[k] = hex[j];
			result << Hexa[k];
			k++;
		}
		Hexa[k] = '\0';
		result << endl;
		result.close();
		return Hexa;
	}
}

//**************** Function for Binary to Decimal 
int bin2dec(int bin[], int num) {
	double a = 2;
	int deci = 0;
	for (int m = 0; m < num; m++) {
		deci = deci + (int)(bin[(num - 1) - m] * pow(a, m));
	}
	return deci;
}

//**************** Function for Octal to Decimal
int oct2dec(int oct[], int num) {
	double a = 8;
	int deci = 0;
	for (int m = 0; m < num; m++) {
		deci = deci + (int)(oct[(num - 1) - m] * pow(a, m));
	}
	return deci;
}

//**************** Function for Hexadecimal to Decimal
int hex2dec(int hex[], int num) {
	double a = 16;
	int deci = 0;
	for (int m = 0; m < num; m++) {
		deci = deci + (int)(hex[(num - 1) - m] * pow(a, m));
	}
	return deci;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
