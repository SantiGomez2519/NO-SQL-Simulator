# NoSQL Simulator

## Table of Contents
- [Description](#description)
- [Execution Instructions](#execution-instructions)
- [Available Commands](#available-commands)
  - [Insert a Document](#insert-a-document)
  - [Insert a Field](#insert-a-field)
  - [Update a Field](#update-a-field)
  - [Get a Field Value](#get-a-field-value)
  - [Delete a Document](#delete-a-document)
  - [Delete a Field](#delete-a-field)
  - [List a Document](#list-a-document)
  - [List All Documents](#list-all-documents)
  - [Exit the Program](#exit-the-program)
- [Usage Example](#usage-example)
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

## Authors
- Santiago Gómez Ospina
- Lucas Higuita Bedoya
- Miguel Angel Ortiz Puerta
- Juan Simón Ospina Martínez
