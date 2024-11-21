#include "MotorDatosNoSQL.h"


int main() {
    MotorDatosNoSQL db;
    db.insertField("ABC123", "nombre", "Edison");
    db.insertField("ABC123", "edad", "52");
    db.insertField("ABC123", "programa", "Ingenieria de Sistemas");
    db.insertField("XYZ789", "nombre", "Juan");
    db.insertField("XYZ789", "edad", "25");
    db.insertField("XYZ789", "programa", "Ingenieria de Software");
    
    db.insertDocument("ERDA", {{"nombre", "Edison"}, {"edad", "52"}, {"programa", "Ingenieria de Sistemas"}});
    db.insertField("ERDA", "apellido", "Gómez");

    std::cout << "\nList document: ABC123\n" << std::endl;
    db.listDocument("ABC123");

    db.updateField("ABC123", "edad", "53");

    std::cout << "\nList document: ABC123\n" << std::endl;
    db.listDocument("ABC123");

    std::cout << "\nList all documents\n" << std::endl;
    db.listAll();

    std::cout << "\nGet field: ERDA, apellido\n" << std::endl;
    db.getField("ERDA", "apellido");

    std::cout << "\nDelete field: ERDA, apellido\n" << std::endl;
    db.deleteField("ERDA", "apellido");
    db.listDocument("ERDA");

    return 0;
}