/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Tyler Coleman
 */

/*
* Quadratic equations are of the form
* a · x
* 2 + b · x + c = 0
* To solve these, one uses the quadratic formula:
* There is a problem, though: if b2–4ac is less than zero, then it will fail. Write a program that can calculate x for a
* quadratic equation. Create a function that prints out the roots of a quadratic equation, given a, b, c. When the program
* detects an equation with no real roots, have it print out a message. How do you know that your results are plausible? Can
* you check that they are correct?
*/

#include "std_lib_facilities.h"	

const double epsilon = 1.0e-7;
double found(double a, double b, double c, double x) {
    double e = a * x * x + b * x + c;
    if (e == 0) return x;
    if (0 < e && epsilon < e) {
        cout << "The root is off by: " << e << "\n";
    } else if (e < -epsilon) {
        cout << "The root is off by: " << e << "\n";
    }
    return x;
}

int main()
{
    try {
        double a, b, c;
        cout << "Quadratic Equation Solver: Enter three numbers separated by spaces (ex: A B C) to solve for (a * x * x) + (b * x) + c == 0: ";
        while (cin >> a >> b >> c) {
            if (a == 0) {
                if (b == 0) {
                    cout << "There is no root.\n";
                } else {
                    cout << "x == " << found(a, b, c, -c / b) << "\n";
                }
            } else if (b == 0) {
                double ca = -c / a;
                if (ca == 0) {
                    cout << "x == 0\n";
                } else if (ca < 0) {
                    cout << "There are no real roots for the numbers given.\n";
                } else {
                    cout << "There are two real roots: " << found(a, b, c, sqrt(ca)) << " and " << found(a, b, c, -sqrt(ca)) << "\n";
                }
            } else {
                double sq = b * b - 4 * a * c;
                if (sq == 0) {
                    cout << "There is one real root: " << found(a, b, c, -b / (2 * a)) << "\n";
                } else if (sq < 0) {
                    cout << "There are no real roots for the numbers given.\n";
                } else {
                    cout << "There are two real roots: " << found(a, b, c, (-b + sqrt(sq)) / (2 * a)) << " and " << found(a, b, c, (-b - sqrt(sq)) / (2 * a)) << "\n";
                }
            }
            cout << "Please try again (enter a b c): ";
        }
    }
    catch (runtime_error e) {
        cout << e.what() << "\n";
    }
}