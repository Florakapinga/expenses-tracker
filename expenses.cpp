#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
class Expense
{
public:
    std::string category;
    double amount;

    Expense(std::string cat, double amt) : category(cat), amount(amt) {}
};
class ExpenseTracker
{
private:
    std::vector<Expense> expenses;

public:
    void addExpense(const std::string &category, double amount)
    {
        expenses.emplace_back(category, amount);
    }