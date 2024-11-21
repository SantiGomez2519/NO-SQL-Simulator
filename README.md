# NoSQL Simulator

## Contents

- [Description](#description)
- [Running Instruccions](#running-instructions)
- [Authors](#authors)

## Description
This project it's a basic NoSQL data engine in C++. The system let manage data documents using the Hash Table data structure to store the data with multiple fields key-value, identified for and unique `id_document`.

## Running Instructions
Compile the project with the following command:

```bash
g++ main.cpp MotorDatosNoSQL.cpp NoSQLParser.cpp -o NoSQLDatabase
```

Or you can use the makefile of the project, in the terminal
```
make run
```

To run the program, use the followings instructions:

#### Create a document
```
INSERT_DOCUMENT <id_document> <key1=value>, <key2=value2> ...
```

**Example**
```
INSERT_DOCUMENT ABC nombre=santi apellido=gomez
```

#### Insert field
```
INSERT_FIELD <id_document> <field_key> <field_value>
```

**Example**
```
INSERT_FIELD ABCD nombre Edison
```

#### Update field
```
UPDATE_FIELD <id_document> <field_key> <field_value>
```

**Example**
```
UPDATE_FIELD ABCD nombre Lucas
```

#### Get field
```
GET_FIELD <id_document> <field_key>
```

**Example**
```
GET_FIELD ABC nombre
```

#### Delete document
```
DELETE_DOCUMENT <id_document>
```

**Example**
```
DELETE_DOCUMENT ABC
```

#### Delete field
```
DELETE_FIELD <id_document> <field_key>
```

**Example**
```
DELETE_FIELD ABC nombre
```

#### List document
```
LIST_DOCUMENT <id_document>
```

**Example**
```
LIST_DOCUMENT ABC
```

#### List all documents
```
LIST_ALL
```

**Example**
```
LIST_ALL
```

#### Finish the program
```
exit
```

## Authors
- Santiago Gómez Ospina
- Lucas Higuita Bedoya