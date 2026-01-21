#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : 
    _name("Form"), _signed(false), _gradeSign(1), _gradeExec(1) {
        // std::cout << "Form Default Constructor has been called" << std::endl;
}

AForm::AForm(const AForm& other) :
    _name(other._name), _signed(other._signed), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec) {
        // std::cout << "Form Default Copy Constructor has been called" << std::endl;
}

AForm& AForm::operator=(const AForm& other) {

    // std::cout << "Form Copy Assignment Operator has been called" << std::endl;
    if (this != &other)
        _signed = other._signed;
    return *this;
}

AForm::~AForm() {
    // std::cout << "Form Destructor has been called" << std::endl;
}

AForm::AForm(const std::string& name, int gradeSign, int gradeExec) :
    _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec) {

    // std::cout << "Form Constructor has been called for " << _name << std::endl;
    if (gradeSign > 150 || gradeExec > 150)
        throw GradeTooLowException();
    if (gradeSign < 1 || gradeExec < 1)
        throw GradeTooHighException();
}

// Getters / Setters

const std::string& AForm::getName() const {
    return _name;
}

bool AForm::getSigned() const {
    return _signed;
}

int AForm::getGradeSign() const {
    return _gradeSign;
}

int AForm::getGradeExec() const {
    return _gradeExec;
}

// Exceptions
const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is Too High!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is Too Low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not Signed!";
}

void AForm::beSigned(const Bureaucrat& b) {
    if (_signed)
        return ;
    if (b.getGrade() > _gradeSign)
        throw GradeTooLowException();
    _signed = true;
}

void AForm::execute(Bureaucrat const &executor) const {
    if (!_signed)
        throw FormNotSignedException();
    if (executor.getGrade() > _gradeExec)
        throw GradeTooLowException();
        
    executeForm(executor);
}

// << Operator overload

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    
    os << "Form \"" << form.getName() << "\"";
    if (form.getSigned())
        os << " is signed, ";
    else 
        os << " is not signed, ";
    os << "sign grade: " << form.getGradeSign() << ", execute grade: " 
        << form.getGradeExec() << ".";
    return os;
}

