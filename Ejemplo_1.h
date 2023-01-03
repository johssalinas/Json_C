

#define MAX_TOKEN_LEN 128

typedef struct {
    struct JSONObject **head;
    int sizeList;
}ListObjects;

typedef struct {
    int size;
    ListObjects **elements;
}JSONArray;

typedef struct JSONObject {
    char *key;
    union {
        char *string_value;
        double number_value;
        ListObjects object_value;
        JSONArray array_value;
        int bool_value;
    } value;
    int value_type;
    struct JSONObject *next;
} JSONObject;

typedef enum {
    TOKEN_OBJECT_BEGIN,
    TOKEN_OBJECT_END,
    TOKEN_ARRAY_BEGIN,
    TOKEN_ARRAY_END,
    TOKEN_COLON,
    TOKEN_COMMA,
    TOKEN_STRING,
    TOKEN_NUMBER,
    TOKEN_TRUE,
    TOKEN_FALSE,
    TOKEN_NULL
} TokenType;

typedef struct {
    TokenType type;
    char value[MAX_TOKEN_LEN];
} Token;

typedef struct {
    char *json;
    int index;
    Token current_token;
} JSONParser;




void skip_whitespace(JSONParser *parser);
int is_digit(char c);
int is_hex_digit(char c);
int is_alpha(char c);
int is_alphanumeric(char c);
void parse_string(JSONParser *parser);
void parse_number(JSONParser *parser);
void parse_true(JSONParser *parser);
void parse_false(JSONParser *parser);
void parse_null(JSONParser *parser);
void parse_token(JSONParser *parser);
ListObjects *parse_object(JSONParser *parser,ListObjects *listObjects);
JSONArray parse_array(JSONParser *parser);
ListObjects *parse_json(char *json);
void free_json_object(JSONObject *object);
ListObjects *ceateListObjects();