#include "MotorDatosNoSQL.h"

void MotorDatosNoSQL::insertDocument(const std::string& id_document, const std::unordered_map<std::string, std::string>& fields) {
    if (tablaDocumentos.find(id_document) != tablaDocumentos.end()) {
        std::cout << "Error: El documento ya existe." << std::endl;
        return;
    }
    tablaDocumentos[id_document] = fields;
    std::cout << "Documento insertado." << std::endl;
}

void MotorDatosNoSQL::insertField(const std::string& id_document, const std::string& field_key, const std::string& field_value) {
    auto& document = tablaDocumentos[id_document];
    if (document.find(field_key) != document.end()) {
        std::cout << "Error: El campo ya existe en el documento." << std::endl;
        return;
    }
    document[field_key] = field_value;
    std::cout << "Campo insertado en el documento." << std::endl;
}

void MotorDatosNoSQL::updateField(const std::string& id_document, const std::string& field_key, const std::string& new_value) {
    auto it = tablaDocumentos.find(id_document);
    if (it == tablaDocumentos.end() || it->second.find(field_key) == it->second.end()) {
        std::cout << "Error: Documento o campo no encontrado." << std::endl;
        return;
    }
    it->second[field_key] = new_value;
    std::cout << "Campo actualizado en el documento." << std::endl;
}

void MotorDatosNoSQL::getField(const std::string& id_document, const std::string& field_key) const {
    auto doc_it = tablaDocumentos.find(id_document);
    if (doc_it != tablaDocumentos.end()) {
        auto field_it = doc_it->second.find(field_key);
        if (field_it != doc_it->second.end()) {
            std::cout << "Valor: " << field_it->second << std::endl;
            return;
        }
    }
    std::cout << "Error: Documento o campo no encontrado." << std::endl;
}

void MotorDatosNoSQL::deleteField(const std::string& id_document, const std::string& field_key) {
    auto doc_it = tablaDocumentos.find(id_document);
    if (doc_it != tablaDocumentos.end() && doc_it->second.erase(field_key)) {
        std::cout << "Campo eliminado del documento." << std::endl;
    } else {
        std::cout << "Error: Documento o campo no encontrado." << std::endl;
    }
}

void MotorDatosNoSQL::listDocument(const std::string& id_document) const {
    auto doc_it = tablaDocumentos.find(id_document);
    if (doc_it != tablaDocumentos.end()) {
        std::cout << "Documento " << id_document << ":" << std::endl;
        for (const auto& [field_key, field_value] : doc_it->second) {
            std::cout << "  Campo: " << field_key << " | Valor: " << field_value << std::endl;
        }
    } else {
        std::cout << "Error: Documento no encontrado." << std::endl;
    }
}

void MotorDatosNoSQL::listAll() const {
    if (tablaDocumentos.empty()) {
        std::cout << "No hay documentos." << std::endl;
        return;
    }
    for (const auto& [id_document, fields] : tablaDocumentos) {
        std::cout << "Documento " << id_document << ":" << std::endl;
        for (const auto& [field_key, field_value] : fields) {
            std::cout << "  Campo: " << field_key << " | Valor: " << field_value << std::endl;
        }
    }
}