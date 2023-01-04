#include <stdio.h>
#include "Ejemplo_1.h"

int main() {
    /*char* json_string = "{"
                            "\"name\": \"John\", "
                            "\"age\": 30, "
                            "\"city\": \"New York\""
                        "}";*/
    char* json_string = "{"
                            "\"name\": \"John\","
                            "\"age\": 30,"
                            "\"city\": \"New York\","
                            "\"isEmployed\": true,"
                        "\"children\": ["
                            "\"prubea\" : ["
                                "{"
                                    "\"name\": \"Samantha\","
                                    "\"age\": 3"
                                "}"
                            "],"
                            "{"
                                "\"name\": \"Alex\","
                                "\"age\": 5"
                            "}"
                        "]"
                        "}";
//{"name": "John","age": 30,"city": "New York","isEmployed": true,"children": [{"name": "Samantha","age": 3},{"name": "Alex","age": 5}]}
    ListObjects* root = parse_json(json_string);

    if (root == NULL) {
        printf("Error parsing JSON\n");
        return 1;
    }



    /*// Access object value
    ListObjects name = *root;
    while (name.head != NULL) {
        if (strcmp(name.head->key, "name") == 0) {
            printf("Name: %s\n", name.head->value.string_value);
            break;
        }
        name.head = name.head->next;
    }

    // Access array value
    ListObjects age = *root;
    while (age.head != NULL) {
        if (strcmp(age.head->key, "age") == 0) {
            printf("Age: %s\n", age.head->value.string_value);
            break;
        }
        age.head = age.head->next;
    }

    // Access object value
    ListObjects city = *root;
    while (city.head != NULL) {
        if (strcmp(city.head->key, "city") == 0) {
            printf("City: %s\n", city.head->value.string_value);
            break;
        }
        city.head = city.head->next;
    }*/

    // Free memory
    //free_json_object(root->head);

    return 0;
}
