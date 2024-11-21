#include "MotorDatosNoSQL.h"
#include "NoSQLParser.h"

int main() {
    MotorDatosNoSQL db;
    NoSQLParser parser(db);

    while (true) {
        std::cout << "NoSQL> ";
        std::string command;
        std::getline(std::cin, command);

        if (command == "exit") {
            break;
        }

        parser.parseCommand(command);
    }

    return 0;
}