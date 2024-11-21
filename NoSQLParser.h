#ifndef NO_SQL_PARSER_H
#define NO_SQL_PARSER_H

#include "MotorDatosNoSQL.h"
#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <regex>

class NoSQLParser {
    private:
        // Reference to the database
        MotorDatosNoSQL db;

        // Variables to store the command parts
        std::string command;
        std::string id_document;
        std::string field_key;
        std::string field_value;
        std::unordered_map<std::string, std::string> fields;

        // Methods to parse the command
        void parseInsertDocument(std::istringstream& stream);
        void parseInsertField(std::istringstream& stream);
        void parseUpdateField(std::istringstream& stream);
        void parseGetField(std::istringstream& stream);
        void parseListDocument(std::istringstream& stream);
        void parseListAll(std::istringstream& stream);

        // Auxiliary methods
        // Process a list of strings separated by commas
        std::vector<std::string> processList(const std::string& parte);

        // Process a list of assignments in the format key1=value1,key2=value2,...
        std::unordered_map<std::string, std::string> processAssignments(const std::string& parte);
        
        // Clean a string removing leading and trailing spaces
        std::string clean(const std::string& string);

    public:
        NoSQLParser(MotorDatosNoSQL& db);
        void parseCommand(const std::string& command);
};

#endif