#ifndef MOTOR_DATOS_NOSQL_H
#define MOTOR_DATOS_NOSQL_H

#include <iostream>
#include <unordered_map>
#include <string>

class MotorDatosNoSQL {
    private:
        // Hash table to store the documents
        std::unordered_map<std::string, std::unordered_map<std::string, std::string>> documents_table;

    public:
        // Insert a document with the fields
        void insertDocument(const std::string& id_document, const std::unordered_map<std::string, std::string>& fields);

        // Insert a field in a document or create a new document with the field
        void insertField(const std::string& id_document, const std::string& field_key, const std::string& field_value);

        // Update a document field
        void updateField(const std::string& id_document, const std::string& field_key, const std::string& new_value);

        // Get a document field
        void getField(const std::string& id_document, const std::string& field_key) const;

        // Delete a document
        void deleteDocument(const std::string& id_document);

        // Delete a field from a document
        void deleteField(const std::string& id_document, const std::string& field_key);

        // List a document
        void listDocument(const std::string& id_document) const;

        // List all documents
        void listAll() const;
};

#endif