This code is a C program that implements a list of employees as a linked list. The program has functions to add a new employee to the list, remove an employee from the list, display the list, and search the list by name.

The structure Zaposlenik represents an employee and has fields for OIB (personal identification number), name, surname, height, weight, father's name, mother's name, and date of birth.

The structure Lista represents the list of employees and contains an integer zadnji which keeps track of the last element in the list, and an array elementi of type Zaposlenik that holds the actual employee data.

The function ubaci inserts a new employee in the list at the specified position. The function ispis displays the list of employees. The function obrisi deletes an employee from the list at a specified position. The function ispis_pretrage_ime searches the list for employees with a given name and displays the results.