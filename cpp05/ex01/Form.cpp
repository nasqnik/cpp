#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : 
    _name("Form"), _signed(false), _gradeSign(1), _gradeExec(1) {
        std::cout << "Form Default Constructor has been called" << std::endl;
}

Form::Form(const Form& other) :
    _name(other._name), _signed(other._signed), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec) {
        std::cout << "Form Default Copy Constructor has been called" << std::endl;
}

Form& Form::operator=(const Form& other) {

    std::cout << "Form Copy Assignment Operator has been called" << std::endl;
    if (this != &other)
        _signed = other._signed;
    return *this;
}

Form::~Form() {
    std::cout << "Form Default Destructor has been called" << std::endl;
}

Form::Form(const std::string& name, int gradeSign, int gradeExec) :
    _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec) {

    std::cout << "Form Constructor has been called for " << _name << std::endl;
    if (gradeSign > 150 || gradeExec > 150)
        throw GradeTooLowException();
    if (gradeSign < 1 || gradeExec < 1)
        throw GradeTooHighException();
}

// Getters / Setters

const std::string& Form::getName() const {
    return _name;
}

bool Form::getSigned() const {
    return _signed;
}

int Form::getGradeSign() const {
    return _gradeSign;
}

int Form::getGradeExec() const {
    return _gradeExec;
}

void Form::setSigned(bool sign) {
    _signed = sign;
}

// Exceptions
const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is Too High!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is Too Low!";
}

const char* Form::FormAlreadySignedException::what() const throw() {
    return "Form is Already Signed!";
}

void Form::beSigned(const Bureaucrat& b) {
    if (_signed)
        throw FormAlreadySignedException();
    if (b.getGrade() > _gradeSign)
        throw GradeTooLowException();
    _signed = true;
}


// << Operator overload

std::ostream& operator<<(std::ostream& os, const Form& form) {
    
    os << "Form \"" << form.getName() << "\"";
    if (form.getSigned())
        os << " is signed, ";
    else 
        os << " is not signed, ";
    os << "sign grade: " << form.getGradeSign() << ", execute grade: " 
        << form.getGradeExec() << ".";
    return os;
}

