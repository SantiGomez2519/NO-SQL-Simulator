# NoSQL Simulator

## Table of Contents
- [Description](#description)
- [Execution Instructions](#execution-instructions)
- [Available Commands](#available-commands)
- [Authors](#authors)

## Description
**NoSQL Simulator** is a basic NoSQL data engine developed in C++. It enables users to manage data documents using a hash table as the main data structure. Each document is organized into key-value pairs and uniquely identified by an `id_document`.

### Key Features
- Insert, update, retrieve, and delete fields within documents.
- List fields of a specific document or all documents.
- Interactive command-based system.

## Execution Instructions

### Compilation
To compile the project, run the following command in the terminal:
```bash
g++ main.cpp MotorDatosNoSQL.cpp NoSQLParser.cpp -o NoSQLDatabase
```

Alternatively, use the provided makefile:
```bash
make run
```

### Execution
Run the compiled program with:

```bash
./NoSQLDatabase
```

## Available Commands

### Insert a Document
Inserts a document with multiple key-value fields.
```bashh
INSERT_DOCUMENT <id_document> <key1=value1>, <key2=value2>, ...
```

#### Example
```bash
INSERT_DOCUMENT ABC name=John, surname=Doe
```

### Insert a Field
Inserts a new field into an existing document. If the document does not exist, it is created.
```bash
INSERT_FIELD <id_document> <field_key> <field_value>
```

#### Example
```bash
INSERT_FIELD ABC name Edison
```

### Update a Field
Updates the value of a field in an existing document.
```bash
UPDATE_FIELD <id_document> <field_key> <field_value>
```

#### Example
```bash
UPDATE_FIELD ABC name Lucas
```

### Get a Field Value
Retrieves the value of a specific field from a document.
```bash
GET_FIELD <id_document> <field_key>
```

#### Example
```bash
GET_FIELD ABC name
```

### Delete a Document
Deletes an entire document, including all its fields.
```bash
DELETE_DOCUMENT <id_document>
```

#### Example
```bash
DELETE_DOCUMENT ABC
```

### Delete a Field
Deletes a specific field from a document.
```bash
DELETE_FIELD <id_document> <field_key>
```

#### Example
```bash
DELETE_FIELD ABC name
```

### List a Document
Lists all fields and values of a specific document.
```bash
LIST_DOCUMENT <id_document>
```

#### Example
```bash
LIST_DOCUMENT ABC
```

### List All Documents
Lists all documents in the database along with their fields and values.
```bash
LIST_ALL
```

#### Example
```bash
LIST_ALL
```

### Exit the Program
Ends the execution of the program.
```bash
exit
```

## Authors
- Santiago Gómez Ospina
- Lucas Higuita Bedoya
- Miguel Angel Ortiz Puerta
- Juan Simón Ospina Martínez
