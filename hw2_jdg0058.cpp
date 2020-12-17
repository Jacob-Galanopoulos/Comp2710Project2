//Jacob Galanopoulos
//JDG0058
//hw2_jdg0058.cpp
//The program calculates the amortized table for a loan. 
//I used ./a.out for testing
//I talked with Karl Sprayberry for the precision stuff.

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double loanAmount = 0.0, interestRate = 0.0, monthlyPayments = 0.0;
	cout << "Loan Amount:";
	cin >> loanAmount;
	cout << "Interest Rate:";
	cin >> interestRate;
	cout << "Monthly Payments:";
	cin >> monthlyPayments;
	double rate = (interestRate / 12);
	cout.precision(2);
	double balance = loanAmount, payment = monthlyPayments, interest = 0.0, principle = 0.0, totalInterest = 0.0;
	int months = 0;
	cout << "**************************************************" << endl;
	cout << "           Amortized Table" << endl;
	cout << "**************************************************" << endl;
	cout << "Month   Balance Payment Rate   Interest Principle" << endl;
	cout << fixed << months << "       $" << balance << "   N/A    N/A      N/A    N/A" << endl;
	while (balance > 0) {
		interest = balance * (rate / 100);
		totalInterest += interest;
		if (balance < payment) {
			principle = balance;
			payment = principle + interest;
			balance = 0;
		}
		else {
			principle = payment - interest;
			balance -= principle;
		}
		months++;
		cout << fixed << months << "      $" << balance << "  $" << payment << "   ";
		cout.precision(1);
		cout << noshowpoint << rate;
		cout.precision(2);
		cout << fixed <<  "   $" << interest << "    $" << principle << endl;
	}
	cout << "**************************************************" << endl;
	cout << "It takes " << months << " months to pay off the loan." << endl;
	cout << "Total interest paid is: $" << totalInterest << endl;
}