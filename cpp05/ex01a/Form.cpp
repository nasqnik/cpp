#include "Form.hpp"

Form::Form() : 
    _name("Default"), _signed(false), _gradeSign(75), _gradeExec(75) {
    std::cout << "Form Default Constructor has been called" << std::endl;
} 

Form::Form(const Form& other) : 
    _name(other._name), _signed(other._signed), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec) {
    std::cout << "Form Copy Constructor has been called for " << _name << std::endl;
}

Form& Form::operator=(const Form& other) {
    std::cout << "Form Copy Assignment Operator has been called for " << _name << std::endl;
    if (this != &other)
        _signed = other._signed;
    return *this;

}

Form::~Form() {
    std::cout << "Form Destructor has been called for " << _name << std::endl;
}

// -----Constructor-----

Form::Form(const std::string& name, int gradeSign, int gradeExec) :
    _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec) {
    std::cout << "Form Constructor has been called for " << _name << std::endl;

    if (gradeSign < 1 || gradeExec < 1)
        throw GradeTooHighException();
    if (gradeSign > 150 || gradeExec > 150)
        throw GradeTooLowException();
}

// -----Getters-----

const std::string& Form::getName() const {
    return _name;
}

bool Form::isSigned() const {
    return _signed;
}

int Form::getGradeSign() const {
    return _gradeSign;
}

int Form::getGradeExec() const {
    return _gradeExec;
}

// -----Actions-----

void Form::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > _gradeSign)
        throw GradeTooLowException();
    _signed = true;
}

// -----Exceptions-----

const char* Form::GradeTooHighException:: what() const throw() {
    return "Form: grade is too high!";
}

const char* Form::GradeTooLowException:: what() const throw() {
    return "Form: grade is too low!";
}

// -----Operator Overload-----
std::ostream& operator<<(std::ostream& os, const Form &f)
{
    os << "Form \"" << f.getName() << "\" [signed: "
       << (f.isSigned() ? "yes" : "no")
       << ", sign grade: " << f.getGradeSign()
       << ", exec grade: " << f.getGradeExec() << "]";
    return os;
}