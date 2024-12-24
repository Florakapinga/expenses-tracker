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
    void displayExpenses() const
    {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Expenses Summary:\n";
        for (const auto &expense : expenses)
        {
            std::cout << "Category: " << expense.category
                      << ", Amount: $" << expense.amount << "\n";
        }
    }
    double totalExpenses() const
    {
        double total = 0.0;
        for (const auto &expense : expenses)
        {
            total += expense.amount;
        }
        return total;
    }
};