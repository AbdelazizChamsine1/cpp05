#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, int s, int e)
    : name(name), isSigned(false), gradeToSign(s), gradeToExecute(e) {
    if (s < 1 || e < 1)
        throw GradeTooHighException();
    if (s > 150 || e > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& o) : name(o.name), isSigned(o.isSigned), gradeToSign(o.gradeToSign), gradeToExecute(o.gradeToExecute) {}

AForm& AForm::operator=(const AForm& o) {
    if (this != &o) isSigned = o.isSigned;
    return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName() const { return name; }
bool AForm::getIsSigned() const { return isSigned; }
int AForm::getGradeToSign() const { return gradeToSign; }
int AForm::getGradeToExecute() const { return gradeToExecute; }

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

void AForm::checkExecute(Bureaucrat const & executor) const {
    if (!isSigned)
        throw NotSignedException();
    if (executor.getGrade() > gradeToExecute)
        throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw() { return "Grade too high!"; }
const char* AForm::GradeTooLowException::what() const throw() { return "Grade too low!"; }
const char* AForm::NotSignedException::what() const throw() { return "Form not signed!"; }

std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << f.getName() << ", signed: " << f.getIsSigned()
       << ", sign grade: " << f.getGradeToSign()
       << ", exec grade: " << f.getGradeToExecute();
    return os;
}
