#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {

    private:
        std::string _target;

    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        ~PresidentialPardonForm();

        PresidentialPardonForm(const std::string& target);

        const std::string& getTarget() const;
        void setTarget(const std::string& target);

    protected:
        virtual void executeForm(Bureaucrat const& executor) const;

};

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& form);

#endif