#include "includes/user_service.h"

User::User(std::string name, int id) : user_name_(name), user_id_(id) {
    std::cout << "User Constructor (name: " << user_name_ << ")" << std::endl;
}

// User::User(const User &rhs) : user_name(rhs) {
//
// }

User::~User() {
    std::cout << "User Destructor(name: " << user_name_ << ")" << std::endl;
}

// const User & User::operator=(const User & rhs) {

// }

const int User::GetId() {
    return user_id_;
}

//setid
void User::SetId(int id) {
    user_id_ = id;
}

//getname
const std::string User::GetName() {
    return user_name_;
}
