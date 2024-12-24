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