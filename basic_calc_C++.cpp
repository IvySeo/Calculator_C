// Ivy Seo, Rupesh Bhuju, Benjamin Jacob, Sapin Dahal, Kyle Preusser
// CSCI 330
// Project 2
// Due 04-13-2018


/* This is the program that mimics the basic functions of a calculate, adding
		subtracting, multiplying, dividing, telling if a number is an even or odd
		and if the number is prime. One of the main requirements for this project
		is to have a menu like system for operations. With having a menu like system,
		the project will require the user that is operating it to key in the numbers
		and the operations by hand. */

#include <iostream>
#include <limits>
using namespace std;

// Function prototypes
void menu();
void basic_calculator();
double Addition(double, double);
double Subtraction(double, double);
double Multiplication(double, double);
double Division(double, double);
int modular(int, int);
bool isEven(int);
bool isPrime(int);
void help();

// main function
int main()
{
	basic_calculator();

	return 0;
}

// the main "meat" of the program
// There is a loop where the program will run until the user tells it to stop
// the loop will take in a user input and will do the requested operations
// on he number that the user also enters
void basic_calculator()
{
	// User input choice
	char choice;

	// For do-while loop for selecting more than 1 operations
	char again;

	// Input values to be calculated
	double operand_A, operand_B, result;
	int integer_operand_A, integer_operand_B;
	bool valid;

	do
	{
		// Display a welcome message with a brief description of
		// all operations and a list of them

		// call menu void function to display menu
		menu();
		valid = false;

		cout << "Your choice : ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
			// Addition choice
			case 'a':
			case 'A':

				while (!valid)
				{
					valid = true;
					cout << "This function adds 2 rational number values ."<< endl;
					cout << "Enter two rational number values for adding up. Separate by space.\n";
					cin >> operand_A >> operand_B;

					//cin.fail() checks to see if the value in the cin
					//stream is the correct type, if not it returns true,
					//false otherwise.
					if(cin.fail())
					{
						cin.clear(); //This corrects the stream.
						cin.ignore(); //This skips the left over stream data.
						cout << "Please enter two rational number values." << endl;
						valid = false;
					}
				}

				result = Addition(operand_A , operand_B);
				cout << "\n\n\t\t" << operand_A << " + " << operand_B << " = " << result << endl;
				break;

			// Subtraction choice
			case 'b':
			case 'B':

				while (!valid)
				{
					valid = true;

					cout << "This function calculate substract with 2 integer values."<< endl;
					cout << "Enter two rational number values for taking off. Separate by space.\n";
					cin >> operand_A >> operand_B;

					//cin.fail() checks to see if the value in the cin
					//stream is the correct type, if not it returns true,
					//false otherwise.
					if(cin.fail())
					{
						cin.clear(); //This corrects the stream.
						cin.ignore(); //This skips the left over stream data.
						cout << "Please enter two rational number values." << endl;
						valid = false;
					}
				}

				result = Subtraction(operand_A,  operand_B);
				cout << "\n\n\t\t" << operand_A << " - " << operand_B << " = " << result << endl;
				break;

			// Multiplication choice
			case 'c':
			case 'C':

				while (!valid)
				{
					valid = true;

					cout << "This function multiplies 2 integer values."<< endl;
					cout << "Enter two rational number values for multiplying. Separate by space.\n";
					cin >> operand_A >> operand_B;

					//cin.fail() checks to see if the value in the cin
					//stream is the correct type, if not it returns true,
					//false otherwise.
					if(cin.fail())
					{
						cin.clear(); //This corrects the stream.
						cin.ignore(); //This skips the left over stream data.
						cout << "Please enter two rational number values." << endl;
						valid = false;
					}
				}
				result = Multiplication(operand_A, operand_B);
				cout << "\n\n\t\t" << operand_A << " * " << operand_B << " = " << result << endl;
				break;

			// Division choice
			case 'd':
			case 'D':

				while (!valid)
				{
					valid = true;

					cout << "This function divides 2 integer values."<< endl;
					cout << "Enter two rational number values for dividing. Separate by space.\n";
					cin >> operand_A >> operand_B;

					//cin.fail() checks to see if the value in the cin
					//stream is the correct type, if not it returns true,
					//false otherwise.
					if(cin.fail())
					{
						cin.clear(); //This corrects the stream.
						cin.ignore(); //This skips the left over stream data.
						cout << "Please enter two rational number values." << endl;
						valid = false;
					}
				}

				if (operand_B != 0)
				{
					result = Division(operand_A, operand_B);
					cout << "\n\n\t\t" << operand_A << " / " << operand_B << " = " << result << endl;
				}
				else
					cout <<"Division by zero error"<<endl;
				break;

			// Even/Odd choice
			case 'e':
			case 'E':


				while (!valid)
				{
					valid = true;

					cout << "This function tells whether the value is even or odd."<< endl;
					cout << "Enter one integer value.\n";
					cin >> integer_operand_A;
					cout << "the values that was entered was : " << integer_operand_A << endl;

					//cin.fail() checks to see if the value in the cin
					//stream is the correct type, if not it returns true,
					//false otherwise.
					if(cin.fail())
					{
						cin.clear(); //This corrects the stream.
						cin.ignore(); //This skips the left over stream data.
						cout << "Please enter one integer number values." << endl;
						valid = false;
					}
				}
				if (isEven(integer_operand_A))
						cout << "The number is even.\n\n";
				else
						cout << "The number is odd.\n\n";

				break;

			// Prime
			case 'f':
			case 'F':
				while (!valid)
				{
					valid = true;
					cout << "This function tells whether the value is prime or not."<< endl;
					cout << "Enter one integer value.\n";
					cin >> integer_operand_A;

					//cin.fail() checks to see if the value in the cin
					//stream is the correct type, if not it returns true,
					//false otherwise.
					if (cin.fail())
					{
						cin.clear();  //This corrects the stream.
						cin.ignore(); //This skips the left over stream data.
						cout << "Please enter one integer number values." << endl;
						valid = false;
					}
				}

				if (integer_operand_A != 1 && isPrime(integer_operand_A))
					cout << "This is a prime number. \n\n";
				else
					cout << "This is a either 1s or not prime number.\n\n";
				break;

			// Modular choice
			case 'g':
			case 'G':

				while (!valid)
				{
					valid = true;

					cout << "This function returns the remainder"<< endl;
					cout << "Enter two  integer value.\n";
					cin >> integer_operand_A;
					cin.clear(); //This corrects the stream.
					cin.ignore(99999999, '\n'); //This skips the left over stream data.
					cin >> integer_operand_B;

					//cin.fail() checks to see if the value in the cin
					//stream is the correct type, if not it returns true,
					//false otherwise.
					if (cin.fail())
					{
						cin.clear();  //This corrects the stream.
						cin.ignore(); //This skips the left over stream data.
						cout << "Please enter two integer number values." << endl;
						valid = false;
					}
				}

				cout << "The remainder is " << modular(integer_operand_A, integer_operand_B) << endl;

				break;

			// Help choice
			case 'h':
			case 'H':

				help();
				break;

			// Quit choice
			case 'q':
			case 'Q':
				cout << "\n-----Thank you for using it. Good-bye!:) ------\n" << endl;
				break;

			// When user put invalid input.
			default:
				cout << "**Enter the valid choice please." << endl;

		}
	cin.clear(); //This corrects the stream.
	cin.ignore(99999999, '\n'); //This skips the left over stream data.

	// Ask user whether to use the function again or not
	cout << "Do you want to continue using calculator function?\n";
	cout << "Put Y for yes or N for no." << endl;
	cin >> again;
	cout << "the again var is :" << again << endl;

	} while (again == 'y' || again == 'Y');

	cout << "\n-----Thank you for using it. Good-bye!:) ------\n" << endl;
}

// @Pre condition: Ask the user to enter two rational number
// @Post condition: Adds those two numbers and returns the result
double Addition(double x, double y)
{
	return (x+y);
}

// Pre condition: Ask the user to enter two rational number
// Post condition:Subtracts those two numbers and returns the result
double Subtraction(double x, double y)
{
	return (x-y);
}

// Pre condition : Ask the user to enter two rational number
// Post condition : it takes the product of those two numbers and returns the result
double Multiplication(double x, double y)
{
	return (x*y);
}

// Pre condition: Ask the user to enter two rational number
// Post condition :it divides those two numbers and returns the result
double Division(double x, double y)
{
	return (x/y);
}


// Pre condition : Ask the user to put the one valid number
// Post condition: The function "isEven" check if that number is even or odd and return the result.
bool isEven(int x)
{
	if (x % 2 == 0)
		return true;
	else
		return false;
}

// Pre condition : Ask the user to insert one valid number
// Post condition: The function " isPrime" returns if the given number is prime number or not.
bool isPrime(int x)
{
	for(int i = 2; i <= x / 2; ++i)
			{
				if(x % i == 0)
				{
					return false;
				}
			}
	return true;
}

//pre condition: Ask the user to input two rational numbers
// post condition: The modular function return the remainder of those two numbers
int modular(int x,int y)
{
	return (x % y);
}

// Display a welcome message with a brief description of
	// all operations and a list of them
void menu()
{

	cout << "\n\t-------------------------------------------------\n";
	cout << " \n\t|\tWelcome to the mini calculator\t\t|\n\n";
	cout << " \n\t| Enter 'h' for help 'q' for quit. Enjoy :)|\n\n";
	cout << "\t-------------------------------------------------\n\n";
	cout << "Enter the function Character you want to operate. \n";
	cout << "1. Addition (Type 'A' or'a' )\n";
	cout << "2. Subtraction (Type 'B' or 'b')\n";
	cout << "3. Multiplication (Type 'C' or 'c' )\n";
	cout << "4. Division (Type 'D' or 'd' )\n";
	cout << "5. Even/Odd (Type 'E' or 'e')\n";
	cout << "6. Prime (Type 'F' or 'f')\n";
	cout << "7. Modular function (Type 'G' or 'g')\n";
	cout << "*Help (Type 'H' or 'h')\n";
	cout << "*Quit the programm (Type 'Q' or 'q')\n\n";
}

// Guide the user by telling what each function does
void help()
{
	cout << "\n-----------HELP MENU----------------- \n";
	cout << "1. Addition : Add up two rational numbers" << endl;
	cout << "2. Subtraction : Subtract two rational numbers" << endl;
	cout << "3. Multiplication : multiply two rational numbers" << endl;
	cout << "4. Division : Divide two rational numbers" << endl;
	cout << "5. Even/Odd : Tells whether the number is even or odd" << endl;
	//cout << "	** Type 1 integer number for Even/Odd " << endl;
	cout << "6. Prime : Tells whether the number is prime or not" << endl;
	cout << "7. Modular function returns the remainder \n";
	cout << "---------------------------------------\n";

}





