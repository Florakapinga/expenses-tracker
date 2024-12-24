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
int main()
{
    ExpenseTracker tracker;
    int choice;
    std::string category;
    double amount;
    do
    {
        std::cout << "1. Add Expense\n2. View Expenses\n3. Total Expenses\n4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            std::cout << "Enter category: ";
            std::cin >> category;
            std::cout << "Enter amount: ";
            std::cin >> amount;
            tracker.addExpense(category, amount);
            break;
        case 2:
            tracker.displayExpenses();
            break;
        case 3:
            std::cout << "Total Expenses: $" << tracker.totalExpenses() << "\n";
            break;
        case 4:
            std::cout << "Exiting the program.\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
    return 0;
}
