#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

#include <fstream>

class ShrubberyCreationForm : public AForm {

    private:
        std::string _target;

    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        ~ShrubberyCreationForm();

        ShrubberyCreationForm(const std::string& target);

        const std::string& getTarget() const;
        void setTarget(const std::string& target);

    protected:
        virtual void executeForm(Bureaucrat const &executor) const;
};

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& form);

#endif