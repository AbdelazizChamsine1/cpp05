#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& t)
    : AForm("ShrubberyCreationForm", 145, 137), target(t) {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    checkExecute(executor);
    std::ofstream out((target + "_shrubbery").c_str());
    out << "   ^   \n  /|\\  \n /_|_\\ \n   |   \n  / \\ " << std::endl;
}
