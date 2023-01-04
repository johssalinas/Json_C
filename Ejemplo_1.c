#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Ejemplo_1.h"





void skip_whitespace(JSONParser *parser) {
    while (parser->json[parser->index] == ' ' || parser->json[parser->index] == '\t' || parser->json[parser->index] == '\n' || parser->json[parser->index] == '\r') {
        parser->index++;
    }
}

int is_digit(char c) {
    return c >= '0' && c <= '9';
}

int is_hex_digit(char c) {
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
}

int is_alpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int is_alphanumeric(char c) {
    return is_alpha(c) || is_digit(c);
}

void parse_string(JSONParser *parser) {
    parser->current_token.type = TOKEN_STRING;
    int start_index = ++parser->index;
    while (parser->json[parser->index] != '\"') {
        if (parser->json[parser->index] == '\\') {
            parser->index++;
        }
        parser->index++;
    }
    int length = parser->index - start_index;
    memcpy(parser->current_token.value, parser->json + start_index, length);
    parser->current_token.value[length] = '\0';
}

void parse_number(JSONParser *parser) {
    parser->current_token.type = TOKEN_NUMBER;
    int start_index = parser->index;
    while (is_digit(parser->json[parser->index])) {
        parser->index++;
    }
    if (parser->json[parser->index] == '.') {
        parser->index++;
        while (is_digit(parser->json[parser->index])) {
            parser->index++;
        }
    }
    if (parser->json[parser->index] == 'e' || parser->json[parser->index] == 'E') {
        parser->index++;
        if (parser->json[parser->index] == '+' || parser->json[parser->index] == '-') {
            parser->index++;
        }
        while (is_digit(parser->json[parser->index])) {
            parser->index++;
        }
    }
    int length = parser->index - start_index;
    memcpy(parser->current_token.value, parser->json + start_index, length);
    parser->current_token.value[length] = '\0';
}

void parse_true(JSONParser *parser) {
    parser->current_token.type = TOKEN_TRUE;
    strcpy(parser->current_token.value, "true");
    parser->index += 4;
}

void parse_false(JSONParser *parser) {
    parser->current_token.type = TOKEN_FALSE;
    strcpy(parser->current_token.value, "false");
    parser->index += 4;
}

void parse_null(JSONParser *parser) {
    parser->current_token.type = TOKEN_NULL;
    strcpy(parser->current_token.value, "null");
    parser->index += 3;
}

void parse_token(JSONParser *parser) {
    skip_whitespace(parser);
    char c = parser->json[parser->index];
    switch (c) {
        case '{':
            parser->current_token.type = TOKEN_OBJECT_BEGIN;
            break;
        case '}':
            parser->current_token.type = TOKEN_OBJECT_END;
            break;
        case '[':
            parser->current_token.type = TOKEN_ARRAY_BEGIN;
            break;
        case ']':
            parser->current_token.type = TOKEN_ARRAY_END;
            break;
        case ':':
            parser->current_token.type = TOKEN_COLON;
            break;
        case ',':
            parser->current_token.type = TOKEN_COMMA;
            break;
        case '"':
            parse_string(parser);
            parser->index++;
            return;
        case 't':
            parse_true(parser);
            return;
        case 'f':
            parse_false(parser);
            return;
        case 'n':
            parse_null(parser);
            return;
        default:
            if (is_digit(c) || c == '-') {
                parse_number(parser);
                return;
            }
            break;
    }
    parser->index++;
}

void createObject(JSONObject *object){
    object->key = NULL;
    object->value_type = 0;
}

ListObjects* ceateListObjects(){
    ListObjects *plistObjects = malloc(sizeof(ListObjects));
    static int i = 0;
    plistObjects->head = malloc(sizeof(JSONObject));
    plistObjects->head[i] = malloc(sizeof(JSONObject));
    plistObjects->head[i] = NULL;
    plistObjects->sizeList = 0;
    return plistObjects;
}

void nextObjetc(JSONObject *object, ListObjects *listObjects,int i){
    if(listObjects->head[i] != NULL) {
        JSONObject *aux = listObjects->head[i];
        listObjects->head[i] = object;
        listObjects->head[i]->next = aux;
        listObjects->sizeList++;
    }else listObjects->head[i] = object;
}

ListObjects *parse_object(JSONParser *parser,ListObjects *listObjects) {
    static int i = 0;
    JSONObject *object = malloc(sizeof(JSONObject));
    createObject(object);
    parse_token(parser);
    while (parser->current_token.type != TOKEN_OBJECT_END) {
        if(parser->current_token.type == TOKEN_OBJECT_BEGIN)
            parse_token(parser);
        /*if (parser->current_token.type != TOKEN_STRING) {
// error
            return NULL;
        }*/
        object->key = strdup(parser->current_token.value);
            parse_token(parser);
        if (parser->current_token.type != TOKEN_COLON) {
// error
            return NULL;
        }
        parse_token(parser);
        switch (parser->current_token.type) {
            case TOKEN_STRING:
                object->value_type = 1;
                object->value.string_value = strdup(parser->current_token.value);
                break;
            case TOKEN_NUMBER:
                object->value_type = 2;
                object->value.number_value = atof(parser->current_token.value);
                break;
            case TOKEN_OBJECT_BEGIN:
                object->value_type = 3;
                object->value.object_value = *parse_object(parser,listObjects);
                break;
            case TOKEN_ARRAY_BEGIN:
                object->value_type = 4;
                object->value.array_value = parse_array(parser);
                break;
            case TOKEN_TRUE:
                object->value_type = 5;
                object->value.bool_value = 1;
                break;
            case TOKEN_FALSE:
                object->value_type = 5;
                object->value.bool_value = 0;
                break;
            case TOKEN_NULL:
                object->value_type = 6;
                break;
            default:
// error
                return NULL;
        }
        parse_token(parser);
        nextObjetc(object,listObjects,i);
        if (parser->current_token.type == TOKEN_COMMA) {
            parse_object(parser,listObjects);
        }
    }
    return listObjects;
}

JSONArray parse_array(JSONParser *parser) {
    JSONArray array;
    array.size = 0;
    array.elements = malloc(sizeof(ListObjects*));
    parse_token(parser);
    static int i = 0;
    array.elements[array.size] = malloc(sizeof(JSONArray));
    array.elements[array.size]->head = malloc(sizeof(JSONObject));
    while (parser->current_token.type != TOKEN_ARRAY_END) {
        ListObjects *listObjects = ceateListObjects();
        array.elements = realloc(array.elements, (array.size + 1) * sizeof(ListObjects));
        array.elements[array.size] = realloc(array.elements[0], (array.size + 1) * sizeof(ListObjects));
        array.elements[array.size]->head = realloc(array.elements[array.size]->head, (i+1)*sizeof(ListObjects));
        array.elements[array.size]->head[i] = malloc(sizeof(JSONObject*));
       // array.elements[array.size]->head[i] = realloc(array.elements[array.size]->head[i],sizeof(JSONObject));
        switch (parser->current_token.type) {
            case TOKEN_STRING:
                array.elements[array.size] = malloc(sizeof(JSONObject));
                array.elements[array.size]->head[i]->key = NULL;
                array.elements[array.size]->head[i]->value_type = 1;
                array.elements[array.size]->head[i]->value.string_value = strdup(parser->current_token.value);
                break;
            case TOKEN_NUMBER:
                array.elements[array.size] = malloc(sizeof(JSONObject));
                array.elements[array.size]->head[i]->key = NULL;
                array.elements[array.size]->head[i]->value_type = 2;
                array.elements[array.size]->head[i]->value.number_value = atof(parser->current_token.value);
                break;
            case TOKEN_OBJECT_BEGIN:
                parse_object(parser, listObjects);
                array.elements[array.size]->head[i] = listObjects->head[0];
                break;
            case TOKEN_ARRAY_BEGIN:
                array.elements[array.size] = malloc(sizeof(JSONObject));
                array.elements[array.size]->head[i]->key = NULL;
                array.elements[array.size]->head[i]->value_type = 4;
                array.elements[array.size]->head[i]->value.array_value = parse_array(parser);
                break;
            case TOKEN_TRUE:
                array.elements[array.size] = malloc(sizeof(JSONObject));
                array.elements[array.size]->head[i]->key = NULL;
                array.elements[array.size]->head[i]->value_type = 5;
                array.elements[array.size]->head[i]->value.bool_value = 1;
                break;
            case TOKEN_FALSE:
                array.elements[array.size] = malloc(sizeof(JSONObject));
                array.elements[array.size]->head[i]->key = NULL;
                array.elements[array.size]->head[i]->value_type = 5;
                array.elements[array.size]->head[i]->value.bool_value = 0;
                break;
            case TOKEN_NULL:
                array.elements[array.size] = malloc(sizeof(JSONObject));
                array.elements[array.size]->head[i]->key = NULL;
                array.elements[array.size]->head[i]->value_type = 6;
                break;
            default:
// error
                return array;
        }
        i++;
        parse_token(parser);
        if (parser->current_token.type == TOKEN_COMMA) {
            parse_token(parser);
        }
    }
    array.size++;
    return array;
}

ListObjects *parse_json(char *json) {
    JSONParser parser;
    parser.json = json;
    parser.index = 0;
    ListObjects *listObjects = ceateListObjects();
    return parse_object(&parser,listObjects);
}

/*void free_json_object(JSONObject *object) {
    if (object->key != NULL) {
        free(object->key);
    }
    switch (object->value_type) {
        case 1:
            free(object->value.string_value);
            break;
        case 3:
            free_json_object(object->value.object_value);
            break;
        case 4:
            for (int i = 0; i < object->value.array_value.size; i++) {
                free_json_object(object->value.array_value.elements[i]);
            }
            free(object->value.array_value.elements);
            break;
    }
    free(object);
}*/

