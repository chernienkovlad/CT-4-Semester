#include <iostream>
#include <string>

void SendSms(const std::string& number, const std::string& message)
{
    std::cout << "Send \"" << message << "\" to number " << number << std::endl;
}

void SendEmail(const std::string& email, const std::string& message)
{
    std::cout << "Send \"" << message << "\" to email " << email << std::endl;
}

class INotifier
{
    public:
        INotifier() {}
    
        virtual void Notify(const std::string& message) = 0;
};

class SmsNotifier: public INotifier
{
    public:
        std::string number_;
    
        SmsNotifier(const std::string& number): number_(number) {};

        void Notify(const std::string& message)
        {
            SendSms(number_, message);
        }
};

class EmailNotifier: public INotifier
{
    public:
        std::string email_;
    
        EmailNotifier(const std::string& email): email_(email) {};
    
        void Notify(const std::string& message)
        {
            SendEmail(email_, message);
        }
};

void Notify(INotifier& notifier, const std::string& message)
{
    notifier.Notify(message);
}

int main()
{
    SmsNotifier sms{"+7-991-957-57-03"};
    EmailNotifier email{"chernienko.va@phystech.edu"};

    Notify(sms, "Alo, eto Mbappe?");
    Notify(email, "Da, eto ya");

    return 0;
}