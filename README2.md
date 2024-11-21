# Reto Final: Motor de Datos NoSQL

**Fecha límite de entrega:** 22 de noviembre de 2024

## Descripción del Reto

El objetivo de este reto final es desarrollar un motor de datos NoSQL básico en C++, Python o Java. Este sistema permitirá gestionar documentos de datos utilizando una estructura de tipo hash (como `unordered_map` en C++ o `dict` en Python) para almacenar registros con múltiples campos clave-valor, identificados por un `id_document` único. Este proyecto pondrá a prueba los conocimientos adquiridos en el manejo de estructuras de datos, manipulación de datos y diseño de sistemas.

### Estructura de un Documento

Cada documento tendrá la siguiente estructura:

```plaintext
{id_document: "ABC123", nombre: "Edison", edad: 52, programa: "Ingenieria de Sistemas"}
```

### Comandos CRUD

El motor de datos debe implementar las siguientes operaciones CRUD (Create, Read, Update, Delete) a través de comandos:

- **INSERT_FIELD**: Inserta un campo en un documento o crea el documento si no existe.
- **UPDATE_FIELD**: Actualiza el valor de un campo en un documento existente.
- **GET_FIELD**: Recupera el valor de un campo específico en un documento.
- **DELETE_FIELD**: Elimina un campo específico de un documento.
- **LIST_DOCUMENT**: Lista todos los campos y valores de un documento.
- **LIST_ALL**: Lista todos los documentos en la base de datos junto con sus respectivos campos y valores.

## Descripción de la Sintaxis en BNF

La siguiente es la descripción en BNF de la sintaxis esperada para cada uno de los comandos CRUD:

```bnf
<command> ::= <insert_field> 
            | <update_field> 
            | <get_field> 
            | <delete_field> 
            | <list_document> 
            | <list_all>

<insert_field> ::= "INSERT_FIELD" <id_document> <field_key> <field_value>
<update_field> ::= "UPDATE_FIELD" <id_document> <field_key> <new_value>
<get_field> ::= "GET_FIELD" <id_document> <field_key>
<delete_field> ::= "DELETE_FIELD" <id_document> <field_key>
<list_document> ::= "LIST_DOCUMENT" <id_document>
<list_all> ::= "LIST_ALL"

<id_document> ::= <string>
<field_key> ::= <string>
<field_value> ::= <string>
<new_value> ::= <string>
```

## Código Base (Opcional)

A continuación, se proporciona un código base en C++ que pueden utilizar como punto de partida para desarrollar el motor de datos NoSQL. Este código es opcional y pueden adaptarlo o usar otro lenguaje (Python o Java) si lo prefieren.

```cpp
#include <iostream>
#include <unordered_map>
#include <string>

class MotorDatosNoSQL {
private:
    std::unordered_map<std::string, std::unordered_map<std::string, std::string>> tablaDocumentos;

public:
    void insertField(const std::string& id_document, const std::string& field_key, const std::string& field_value) {
        auto& document = tablaDocumentos[id_document];
        if (document.find(field_key) != document.end()) {
            std::cout << "Error: El campo ya existe en el documento." << std::endl;
            return;
        }
        document[field_key] = field_value;
        std::cout << "Campo insertado en el documento." << std::endl;
    }

    void updateField(const std::string& id_document, const std::string& field_key, const std::string& new_value) {
        auto it = tablaDocumentos.find(id_document);
        if (it == tablaDocumentos.end() || it->second.find(field_key) == it->second.end()) {
            std::cout << "Error: Documento o campo no encontrado." << std::endl;
            return;
        }
        it->second[field_key] = new_value;
        std::cout << "Campo actualizado en el documento." << std::endl;
    }

    void getField(const std::string& id_document, const std::string& field_key) const {
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

    void deleteField(const std::string& id_document, const std::string& field_key) {
        auto doc_it = tablaDocumentos.find(id_document);
        if (doc_it != tablaDocumentos.end() && doc_it->second.erase(field_key)) {
            std::cout << "Campo eliminado del documento." << std::endl;
        } else {
            std::cout << "Error: Documento o campo no encontrado." << std::endl;
        }
    }

    void listDocument(const std::string& id_document) const {
        auto doc_it = tablaDocumentos.find(id_document);
        if (doc_it != tablaDocumentos.end()) {
            std::cout << "Documento "" << id_document << "":" << std::endl;
            for (const auto& [field_key, field_value] : doc_it->second) {
                std::cout << "  Campo: " << field_key << " | Valor: " << field_value << std::endl;
            }
        } else {
            std::cout << "Error: Documento no encontrado." << std::endl;
        }
    }

    void listAll() const {
        if (tablaDocumentos.empty()) {
            std::cout << "No hay documentos." << std::endl;
            return;
        }
        for (const auto& [id_document, fields] : tablaDocumentos) {
            std::cout << "Documento "" << id_document << "":" << std::endl;
            for (const auto& [field_key, field_value] : fields) {
                std::cout << "  Campo: " << field_key << " | Valor: " << field_value << std::endl;
            }
        }
    }
};

int main() {
    MotorDatosNoSQL db;
    db.insertField("ABC123", "nombre", "Edison");
    db.insertField("ABC123", "edad", "52");
    db.insertField("ABC123", "programa", "Ingenieria de Sistemas");
    db.listDocument("ABC123");

    return 0;
}
```

## Ejemplos de Uso

### Insertar un Campo en un Documento Nuevo

```plaintext
Comando:
INSERT_FIELD "ABC123" "nombre" "Edison"
Descripción: Inserta el campo "nombre" con el valor "Edison" en el documento con ID "ABC123".
```

### Listar Todos los Campos de un Documento

```plaintext
Comando:
LIST_DOCUMENT "ABC123"
Descripción: Muestra todos los campos y valores del documento con ID "ABC123".
```

## Rubrica de Evaluación

| Criterio                | Excelente (5) | Bueno (4) | Regular (3) | Deficiente (2) | No satisfactorio (1) |
|-------------------------|---------------|-----------|-------------|----------------|-----------------------|
| **Funcionalidad CRUD**  | Todos los comandos CRUD funcionan correctamente. | La mayoría de los comandos funcionan con errores mínimos. | La mayoría de los comandos funcionan, pero tienen errores. | Algunos comandos funcionan, con errores importantes. | No se implementaron correctamente los comandos CRUD. |
| **Estructura de datos** | Eficiente y adecuada para operaciones de NoSQL. | Adecuada, con ligeras ineficiencias. | Funcional pero con problemas de eficiencia. | Ineficiente, impactando las operaciones. | No se utilizó una estructura adecuada. |
| **Manejo de errores y CLI** | Manejo adecuado de errores con mensajes claros. | La mayoría de los errores se manejan bien. | Algunos errores de entrada no se manejan adecuadamente. | Muchos errores no se manejan y la CLI es confusa. | No maneja errores y la CLI es difícil de usar. |
| **Claridad del código y estilo** | Código claro y bien organizado. | Claro pero con inconsistencias menores. | Claro en su mayoría, con algunas secciones confusas. | Confuso y con nombres inconsistentes. | No es legible ni está bien estructurado. |
| **Documentación y README** | Documentación excelente en el código y un documento. | Documentación clara pero podrían ser más detallados. | Documentación mínima en el código y documento. | Documentación insuficiente. | No se incluyó documentación en el código. |

## Entrega

- **Formato de entrega**: Envía el código fuente, el archivo word o pdf, con una breve explicación de la solución propuesta. 
- **Fecha límite**: 22 de noviembre de 2024.

---
