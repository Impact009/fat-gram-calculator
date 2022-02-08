// Fat Gram Calculator.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	// Declare variables to store values for the month, the year, and the total amount collected at the cash register
	char reply = 'n';
	double fatPercent = .27, fatPercentage = 27, lowFatThreshold;
	int fatGrams = 6, totalCalories = 200, fatCalories = 54;

	// Program information and example
	cout << "This program displays the percentage of calories from fat. If the calories from\n"
		 << "fat are less than 30% of the total calories of the food, it will also indicate\n"
		 << "that the food is low in fat. For example, if a " << totalCalories << "-calorie food has " << fatGrams << " grams of\n"
		 << "fat, then it has " << fatCalories << " of calories from fat, which is " << fatPercentage << "% fat, and is thus low in\n"
		 << "fat.\n\n"

	// Ask the user if he or she wants to enter information.
		 << "This program requires the number of calories and fat grams in a food. Would you\n"
		 << "like to calculate the calories from fat of the food? (y/n) ";
	cin >> reply;

	if (reply == 'y' || reply == 'Y')
	{
		// Clear the screen for calculation
		system("cls");

		// Input information
		cout << "Enter the number of calories:  ";
		cin >> totalCalories;
		cout << "Enter the number of fat grams: ";
		cin >> fatGrams;

		// Calculations
		fatCalories = fatGrams * 9;
		fatPercent = static_cast<double>(fatCalories) / totalCalories;
		fatPercentage = fatPercent * 100;
		lowFatThreshold = totalCalories * .3;

		// Outputs data
		if (totalCalories > 0 && fatGrams >= 0 && totalCalories > fatCalories)
		{
			cout << "\nCalories from fat:               " << fatCalories << endl
				 << "Percentage of calories from fat: " << fatPercentage << "%\n";

			if (fatCalories < lowFatThreshold)
				cout << "\nThe food is low in fat.\n";
		}
		else
			if (totalCalories < 0)
				cout << "\nError: the number of calories cannot be negative.\n";
		else
			// Prevents division by 0.
			if (totalCalories == 0)
				cout << "\nThe food has " << totalCalories << " calories.\n";
		else
			if (fatGrams < 0)
				cout << "\nError: the number of fat grams cannot be negative.\n";
		else
			if (totalCalories < fatCalories)
				cout << "\nError: the number of calories from fat exceeds the total number of calories.\n";
	}

	cout << "\nHave a great day!\n\n";
	return 0;
}