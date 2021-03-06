#ifndef EXPENSEMENAGER_H
#define EXPENSEMENAGER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

#include "Expense.h"
#include "PlikiZExpenses.h"
#include "DataMenager.h"
#include "Markup.h"
#include "data.h"
#include "AdditionalMethods.h"

using namespace std;

class ExpenseMenager
{
    const int ID_LOGGED_USER;

    vector <Expense> expenses;
    vector <Data> daty;
    PlikiZExpenses plikiZExpenses;
    DataMenager dataMenager;

    Expense getNewItemData(char sign, string givenData);
    int getIDNewExpense();
    void showExpense(Expense expense);
    void showExpenseFromThisMonth(Expense expense);
    void showExpenseFromPreviousMonth(Expense expense);
    void sortingExpense(vector <Expense> &expense);
    bool isCorrectDate(string data);
    void showExpenseFromRangeProvided(string dataPoczatkowa,string dataKoncowa);
    void wyswietlDate(Data data);

public:
    ExpenseMenager(string nameFileExpenses,int idLoggedUser): plikiZExpenses(nameFileExpenses),ID_LOGGED_USER(idLoggedUser){
        expenses = plikiZExpenses.loadExpensesFromFile(ID_LOGGED_USER);
        daty = dataMenager.loadData(ID_LOGGED_USER);
        };
    void addExpense();
    void wyswietlWszystkieItemy();
    void wyswietlWszystkieDaty();
    void showItemsFromThisMonth();
    void showItemsFromPreviousMonth();
    void sorting();
    float calculateExpensesFromThisMonth();
    float calculateExpensesFromPreviousMonth();
    void showItemsFromRangeProvided(string dataPoczatkowa,string dataKoncowa);
    float calculateExpensesFromRangeProvided(string dataPoczatkowa,string dataKoncowa);
};

#endif
