#include <stdio.h>
#include <stdint.h>

typedef enum
{
    JSON_NULL,
    JSON_BOOLEAN,
    JSON_NUMBER,
    JSON_STRING,
    JSON_ARRAY,
    JSON_OBJECT
} JsonType;

typedef struct JsonValue
{
    JsonType type;
    union
    {
        int boolean;
        double number;
        char *string;
        struct
        {
            struct JsonValue *values;
            size_t count;
        } array;
        struct
        {
            char **keys;
            struct JsonValue *values;
            size_t count;
        } object;
    } value;
} JsonValue;

char *json_object = "{\"ten\":\"Nguyen A\", \"tuoi\": 19, \"diachi\": \"HCM\"}";

void parse_json(char *json_object)
{

    char key[10];
    char value[20];
    int index = 0;
    int i = 0;

    while (1)
    {
        if (*json_object == '{')
            json_object++;
        if (*json_object == '\"')
            json_object++;
        while (*json_object != '\"')
        {
            key[i] = *(json_object++);
            i++;
        }

        printf("Key: %s\n", key);

        break;
    }
}

int main(int argc, char const *argv[])
{
    parse_json(json_object);
    return 0;
}
