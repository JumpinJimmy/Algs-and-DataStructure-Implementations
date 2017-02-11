#include "includes/user_service.h"

UserService::UserService(std::string name) : service_name_(name) {
    std::cout << "UserService Constructor" << std::endl;
}

UserService::UserService(const UserService &rhs) : service_name_(rhs.GetName()) {}

UserService::~UserService() {
    std::cout << "UserService Destructor" << std::endl;
}

const UserService & UserService::operator=(const UserService & rhs) {
    std::cout << "Operator=" << std::endl;
    if (this != &rhs) {
        this->service_name_ = rhs.GetName();
    }
    return *this;
}

const std::string UserService::GetName() const {
    return service_name_;
}

std::ostream& operator<<(std::ostream &os, const UserService& us) {
    os << us.GetName();
    return os;
}
