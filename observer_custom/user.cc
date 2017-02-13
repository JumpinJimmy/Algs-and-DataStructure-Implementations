#include <sstream>
#include "includes/user.h"

User::User(std::string name, int id) : user_name_(name), user_id_(id) {
    std::cout << "User Constructor (name: " << user_name_ << ")" << std::endl;
}

User::User(const User &rhs) : user_name_(rhs.GetName()), user_id_(rhs.Id()) {}

User::~User() {
    std::cout << "User Destructor(name: " << user_name_ << ")" << std::endl;
}

const User & User::operator=(const User & rhs) {
    std::cout << "Operator=" << std::endl;
    if (this != &rhs) {
        this->user_name_ = rhs.GetName();
        this->user_id_ = rhs.Id();
    }
    return *this;
}

const int User::Id() const {
    return user_id_;
}

void User::SetId(int id) {
    user_id_ = id;
}

const std::string User::GetName() const {
    return user_name_;
}

std::string User::toString() {
    std::stringstream ss;
    ss << GetName() << " " << Id();
    return ss.str();
}

std::ostream& operator<<(std::ostream &os, const User& user) {
    os << user.GetName() << " " << user.Id();
    return os;
}
