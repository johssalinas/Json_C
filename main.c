#include <stdio.h>
#include "Ejemplo_1.h"

int main() {
    /*char* json_string = "{"
                            "\"name\": \"John\", "
                            "\"age\": 30, "
                            "\"city\": \"New York\""
                        "}";*/
    /*char* json_string = "{"
                            "\"name\": \"John\","
                            "\"age\": 30,"
                            "\"city\": \"New York\","
                            "\"isEmployed\": true,"
                        "\"children\": ["
                            "{"
                                "\"name\": \"Samantha\","x
                                "\"age\": 3"
                            "},"
                            "{"
                                "\"name\": \"Alex\","
                                "\"age\": 5"
                            "}"
                        "]"
                        "}";*/
   /* char *json_string = "{"
                        "\"squadName\": \"Super hero squad\","
                        "\"homeTown\": \"Metro City\","
                        "\"formed\": 2016,"
                        "\"secretBase\": \"Super tower\","
                        "\"active\": true,"
                        "\"members\": ["
                            "{"
                                "\"name\": \"Molecule Man\","
                                "\"age\": 29,"
                                "\"secretIdentity\": \"Dan Jukes\"," //root->head[0]->value.array_value.elements[0]->head[0]->next
                                "\"powers1\": ["
                                    "\"Radiation resistance\","//root->head[0]->value.array_value.elements[0]->head[0]->value.array_value.elements[0]->head[0]
                                    "\"Turning tiny\","
                                    "\"Radiation blast\""
                                "]"
                            "},"
                            "\"holaaaa\","
                            "{"
                                "\"name\": \"Madame Uppercut\","
                                "\"age\": 39,"
                                "\"secretIdentity\": \"Jane Wilson\","
                                "\"powers2\": ["
                                "\"Million tonne punch\","
                                "\"Damage resistance\","
                                "\"Superhuman reflexes\""
                                "]"
                            "},"
                            "{"
                                "\"name\": \"Eternal Flame\","
                                "\"age\": 1000000,"
                                "\"secretIdentity\": \"Unknown\","
                                "\"powers3\": ["
                                "\"Immortality\","
                                "\"Heat Immunity\","
                                "\"Inferno\","
                                "\"Teleportation\","
                                "\"Interdimensional travel\""
                                "]"
                            "}"
                        "]"
                        "}";*/
    char* json_string = "{"
                            "\"_type\": \"Project\","
                            "\"id\": 4,"
                            "\"identifier\": \"projet04-1\","
                            "\"name\": \"projet04\","
                            "\"active\": true,"
                            "\"public\": false,"
                            "\"description\": {"
                                "\"format\": \"markdown\","
                                "\"raw\": \"\","
                                "\"html\": \"\""
                            "},"
                            "\"createdAt\": \"2022-10-10T19:09:19Z\","
                            "\"updatedAt\": \"2022-10-10T19:09:19Z\","
                            "\"statusExplanation\": {"
                                "\"format\": \"markdown\","
                                "\"raw\": \"\","
                                "\"html\": \"\""
                            "},"
                            "\"Johs\": true,"
                            "\"_links\": {"
                                "\"self\": {"
                                    "\"href\": \"/api/v3/projects/4\","
                                    "\"title\": \"projet04\""
                                "},"
                                "\"createWorkPackage\": {"
                                    "\"href\": \"/api/v3/projects/4/work_packages/form\","
                                    "\"method\": \"post\""
                                "},"
                                "\"createWorkPackageImmediately\": {"
                                    "\"href\": \"/api/v3/projects/4/work_packages\","
                                    "\"method\": \"post\""
                                "},"
                                "\"workPackages\": {"
                                    "\"href\": \"/api/v3/projects/4/work_packages\""
                                "},"
                                "\"categories\": {"
                                    "\"href\": \"/api/v3/projects/4/categories\""
                                "},"
                                "\"versions\": {"
                                    "\"href\": \"/api/v3/projects/4/versions\""
                                "},"
                                "\"memberships\": {"
                                    "\"href\": \"/api/v3/memberships?filters=%5B%7B%22project%22%3A%7B%22operator%22%3A%22%3D%22%2C%22values%22%3A%5B%224%22%5D%7D%7D%5D\""
                                "},"
                                "\"types\": {"
                                    "\"href\": \"/api/v3/projects/4/types\""
                                "},"
                                "\"update\": {"
                                    "\"href\": \"/api/v3/projects/4/form\","
                                    "\"method\": \"post\""
                                "},"
                                "\"updateImmediately\": {"
                                    "\"href\": \"/api/v3/projects/4\","
                                    "\"method\": \"patch\""
                                "},"
                                "\"delete\": {"
                                    "\"href\": \"/api/v3/projects/4\","
                                    "\"method\": \"delete\""
                                "},"
                                "\"Yhon\": {},"
                                "\"schema\": {"
                                    "\"href\": \"/api/v3/projects/schema\""
                                "},"
                                "\"status\": {"
                                    "\"href\": null"
                                "},"
                                "\"ancestors\": [],"
                                "\"parent\": {"
                                    "\"href\": null"
                                "},"
                                "\"members\": ["
                                    "{"
                                        "\"name\": \"Molecule Man\","
                                        "\"age\": 29,"
                                        "\"secretIdentity\": \"Dan Jukes\","
                                        "\"powers1\": ["
                                            "\"Radiation resistance\","//root->head->value.object_value.head->value.array_value.elements[0]->head->value.array_value.elements[0]->head->value.string_value
                                            "\"Turning tiny\","
                                            "\"Radiation blast\""
                                        "]"
                                    "},"
                                    "\"Brayan\","
                                    "{"
                                        "\"name\": \"Madame Uppercut\","
                                        "\"age\": 39,"
                                        "\"secretIdentity\": \"Jane Wilson\","
                                        "\"powers2\": ["
                                            "\"Million tonne punch\","
                                            "\"Damage resistance\","
                                            "\"Superhuman reflexes\""
                                        "]"
                                    "},"
                                    "{"
                                        "\"name\": \"Eternal Flame\","
                                        "\"age\": 1000000,"
                                        "\"secretIdentity\": \"Unknown\","
                                        "\"powers3\": ["
                                            "\"Immortality\","
                                            "\"Heat Immunity\","
                                            "{"
                                                "\"Salinas\": \"Lopez\","
                                                "\"Esto es una\": \"prueba\""
                                            "},"
                                            "\"Inferno\","
                                            "\"Teleportation\","
                                            "\"Interdimensional travel\""
                                        "]"
                                    "}"
                                "]"
                            "}"
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
