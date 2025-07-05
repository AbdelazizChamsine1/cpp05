#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string& t)
    : AForm("RobotomyRequestForm", 72, 45), target(t) {
    std::srand(std::time(NULL));
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    checkExecute(executor);
    std::cout << "Bzzzzzz... DRILLING noises..." << std::endl;
    if (std::rand() % 2)
        std::cout << target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed on " << target << "!" << std::endl;
}
