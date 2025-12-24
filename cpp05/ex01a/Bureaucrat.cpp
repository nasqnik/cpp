#include "Bureaucrat.hpp"

// -----Orthodox Canonical Form-----

Bureaucrat::Bureaucrat() : 
    _grade(150), _name("Default") {
    std::cout << "Bureaucrat Default Constructor has been called" << std::endl;
} 

Bureaucrat::Bureaucrat(const Bureaucrat& other) : 
    _grade(other._grade), _name(other._name) {
    std::cout << "Bureaucrat Copy Constructor has been called for " << _name << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    std::cout << "Bureaucrat Copy Assignment Operator has been called for " << _name << std::endl;
    if (this != &other)
        _grade = other._grade;
    return *this;

}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat Destructor has been called for " << _name << std::endl;
}

// -----Constructor-----

Bureaucrat::Bureaucrat(const std::string& name, int grade) :
    _grade(grade), _name(name) {
    std::cout << "Bureaucrat Constructor has been called for " << _name << std::endl;

    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
        
}

// -----Getters-----

const std::string& Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

// -----Actions-----

void Bureaucrat::incrementGrade() {
    if (_grade <= 1)
        throw GradeTooHighException();
    --_grade;
}

void Bureaucrat::decrementGrade() {
    if (_grade >= 150)
        throw GradeTooLowException();
    ++_grade;
}

void Bureaucrat::signForm(Form &f) {
    try {
        f.beSigned(*this);
        std::cout << _name << " signed " << f.getName() << std::endl;
    } catch (const std::exception &e) {
        std::cout << _name << " couldn’t sign " << f.getName()
            << " because " << e.what() << std::endl;
    }
}

// -----Exceptions-----

const char* Bureaucrat::GradeTooHighException:: what() const throw() {
    return "Bureaucrat: grade is too high!";
}

const char* Bureaucrat::GradeTooLowException:: what() const throw() {
    return "Bureaucrat: grade is too low!";
}

// -----Operator Overload-----
std::ostream& operator<<(std::ostream& os, const Bureaucrat &b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}