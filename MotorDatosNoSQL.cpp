#include "MotorDatosNoSQL.h"

// Insert a document with the fields
void MotorDatosNoSQL::insertDocument(const std::string& id_document, const std::unordered_map<std::string, std::string>& fields) {
    // Check if the document already exist
    if (documents_table.find(id_document) != documents_table.end()) {
        std::cout << "Error: The document already exist." << std::endl;
        return;
    }

    // Insert the document
    documents_table[id_document] = fields;
    std::cout << "Document inserted." << std::endl;
}

// Insert a field in a document or create a new document with the field
void MotorDatosNoSQL::insertField(const std::string& id_document, const std::string& field_key, const std::string& field_value) {
    // Check if the document already exist
    auto& document = documents_table[id_document];
    if (document.find(field_key) != document.end()) {
        std::cout << "Error: The field already exist in the document." << std::endl;
        return;
    }

    // Insert the field
    document[field_key] = field_value;
    std::cout << "Field inserted in the document." << std::endl;
}

// Update a document field
void MotorDatosNoSQL::updateField(const std::string& id_document, const std::string& field_key, const std::string& new_value) {
    // Check if the document and field exist
    auto it = documents_table.find(id_document);
    if (it == documents_table.end() || it->second.find(field_key) == it->second.end()) {
        std::cout << "Error: Document or field not found." << std::endl;
        return;
    }

    // Update the field
    it->second[field_key] = new_value;
    std::cout << "Field updated in the document." << std::endl;
}

// Get a document field
void MotorDatosNoSQL::getField(const std::string& id_document, const std::string& field_key) const {
    // Look the document and field in the hash table
    auto doc_it = documents_table.find(id_document);
    if (doc_it != documents_table.end()) {
        auto field_it = doc_it->second.find(field_key);
        // Print the value of the field
        if (field_it != doc_it->second.end()) {
            std::cout << "Value: " << field_it->second << std::endl;
            return;
        }
    }
    std::cout << "Error: Document or field not found." << std::endl;
}

// Delete a field from a document
void MotorDatosNoSQL::deleteField(const std::string& id_document, const std::string& field_key) {
    auto doc_it = documents_table.find(id_document);
    // Erase the field from the document
    if (doc_it != documents_table.end() && doc_it->second.erase(field_key)) {
        std::cout << "Field eliminated from document." << std::endl;
    } else {
        std::cout << "Error: Document or field not found." << std::endl;
    }
}

// List a document
void MotorDatosNoSQL::listDocument(const std::string& id_document) const {
    auto doc_it = documents_table.find(id_document);
    // Print the fields of the document
    if (doc_it != documents_table.end()) {
        std::cout << "Document " << id_document << ":" << std::endl;
        for (const auto& [field_key, field_value] : doc_it->second) {
            std::cout << "  Field: " << field_key << " | Value: " << field_value << std::endl;
        }
    } else {
        std::cout << "Error: Document not found." << std::endl;
    }
}

// List all documents
void MotorDatosNoSQL::listAll() const {
    if (documents_table.empty()) {
        std::cout << "There are no documents." << std::endl;
        return;
    }
    for (const auto& [id_document, fields] : documents_table) {
        std::cout << "Document " << id_document << ":" << std::endl;
        for (const auto& [field_key, field_value] : fields) {
            std::cout << "  Field: " << field_key << " | Value: " << field_value << std::endl;
        }
    }
}