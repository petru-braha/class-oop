#pragma once
#include <ostream>

class JsonValue {
public:
    bool container = false;
    virtual ~JsonValue() = 0;

    virtual void print(std::ostream& out, int identation = 0) const = 0;
    virtual operator unsigned()const { return 1; }
};

class NullValue : public JsonValue
{
    void print(std::ostream& out, int identation)const;
}; 

class NumberValue : public JsonValue
{
    int value;
public:
    NumberValue(const int& value):value(value){}
    void print(std::ostream& out, int identation)const;
};

class BoolValue : public JsonValue 
{
    bool value;
public:
    BoolValue(const bool& value): value(value){}
    void print(std::ostream& out, int identation)const;
};

#define str 255
class StringValue : public JsonValue 
{
    char* value;
public:
    StringValue(const char* name);
    void print(std::ostream& out, int identation)const;
    ~StringValue() { delete[]value; }
}; 

#define arr 16
class ArrayValue : public JsonValue 
{
    size_t size;
    JsonValue* elements[arr];
public:
    ArrayValue();
    void add(JsonValue* pointer_element);
    void print(std::ostream& out, int identation)const;
    ~ArrayValue();
};

class ObjectValue : public JsonValue 
{
    struct pair
    {
        char* name;
        JsonValue* value;
        pair() : name(nullptr), value(nullptr){}
    } elements[arr];
    size_t size;

public:
    ObjectValue() { container = true; size = 0; }
    
    void add(const char* name, JsonValue* pointer_element);
    void print(std::ostream& out, int identation)const;
    operator unsigned() const; // return the nr of nodes
    
    ~ObjectValue();
}; 

// name of the file should not have " " characters.
// the output file will be placed in the same directory where "homework" can be found.
std::ostream& standard_VS_file();