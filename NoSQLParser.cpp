#include "NoSQLParser.h"

// Constructor
NoSQLParser::NoSQLParser(MotorDatosNoSQL& db) : db(db) {}

// Parse the command and call the corresponding method
void NoSQLParser::parseCommand(const std::string& command) {
    std::istringstream stream(command);
    std::string key_word;
    stream >> key_word;

    // Transform the key_word to lowercase
    std::transform(key_word.begin(), key_word.end(), key_word.begin(), ::tolower);

    if (key_word == "insert_document") {
        parseInsertDocument(stream);
    } else if (key_word == "insert_field") {
        parseInsertField(stream);
    } else if (key_word == "update_field") {
        parseUpdateField(stream);
    } else if (key_word == "get_field") {
        parseGetField(stream);
    } else if (key_word == "delete_document") {
        parseDeleteDocument(stream);
    } else if (key_word == "delete_field") {
        parseDeleteField(stream);
    } else if (key_word == "list_document") {
        parseListDocument(stream);
    } else if (key_word == "list_all") {
        parseListAll(stream);
    } else {
        std::cout << "Error: Comando no reconocido." << std::endl;
    }
}

// Insert a document with the fields
void NoSQLParser::parseInsertDocument(std::istringstream& stream) {
    stream >> id_document;

    std::string fields_str;
    std::getline(stream, fields_str);
    fields = processAssignments(fields_str);

    db.insertDocument(id_document, fields);
}

// Insert a field in a document or create a new document with the field
void NoSQLParser::parseInsertField(std::istringstream& stream) {
    stream >> id_document >> field_key >> field_value;
    db.insertField(id_document, field_key, field_value);
}

// Update a document field
void NoSQLParser::parseUpdateField(std::istringstream& stream) {
    stream >> id_document >> field_key >> field_value;
    db.updateField(id_document, field_key, field_value);
}

// Get a document field
void NoSQLParser::parseGetField(std::istringstream& stream) {
    stream >> id_document >> field_key;
    db.getField(id_document, field_key);
}

// Delete a document
void NoSQLParser::parseDeleteDocument(std::istringstream& stream) {
    stream >> id_document;
    db.deleteDocument(id_document);
}

// Delete a field from a document
void NoSQLParser::parseDeleteField(std::istringstream& stream) {
    stream >> id_document >> field_key;
    db.deleteField(id_document, field_key);
}

// List a document
void NoSQLParser::parseListDocument(std::istringstream& stream) {
    stream >> id_document;
    db.listDocument(id_document);
}

// List all documents
void NoSQLParser::parseListAll(std::istringstream& stream) {
    db.listAll();
}

// Process the assignments in the format key1=value1,key2=value2,...
std::unordered_map<std::string, std::string> NoSQLParser::processAssignments(const std::string& parte) {
    std::unordered_map<std::string, std::string> assignments;
    std::string assignment;
    std::istringstream stream(parte);
    while (std::getline(stream, assignment, ',')) {
        std::istringstream assignment_stream(assignment);
        std::string key, value;
        std::getline(assignment_stream, key, '=');
        std::getline(assignment_stream, value, '=');
        assignments[clean(key)] = clean(value);
    }
    return assignments;
}

// Clean the string by removing leading and trailing spaces
std::string NoSQLParser::clean(const std::string& string) {
    std::string cleaned = string;
    cleaned.erase(std::remove_if(cleaned.begin(), cleaned.end(), ::isspace), cleaned.end());
    return cleaned;
}