#include <iostream>
#include <list>
#include <set>
#include <string>

int main() {
    std::list<std::string> list1 = {"user1@example.com", "user2@example.com", "user3@example.com"};
    std::list<std::string> list2 = {"user2@example.com", "user4@example.com", "user5@example.com"};
    std::list<std::string> list3 = {"user3@example.com", "user4@example.com", "user6@example.com"};

    std::set<std::string> unique_emails;

    for (const auto& email : list1) {
        unique_emails.insert(email);
    }

    for (const auto& email : list2) {
        unique_emails.insert(email);
    }

    for (const auto& email : list3) {
        unique_emails.insert(email);
    }

    std::list<std::string> unique_list(unique_emails.begin(), unique_emails.end());

    for (const auto& email : unique_list) {
        std::cout << email << '\n';
    }

    return 0;
}
