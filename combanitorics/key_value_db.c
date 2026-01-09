#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TABLE_SIZE 101

typedef struct Entry {
    char *key;
    char *value;
    struct Entry *next;
} Entry;

typedef struct {
    Entry *buckets[TABLE_SIZE];
} HashTable;

unsigned int hash(const char *key) {
    unsigned int hash = 0;
    while (*key) {
        hash = (hash * 31) + *key++;
    }
    return hash%TABLE_SIZE;
}

HashTable* create_table() {
    HashTable *table = malloc(sizeof(HashTable));
    for(int i=0; i<TABLE_SIZE; i++){
        table->buckets[i] = NULL;
    }
    return table;
}

void set(HashTable *table, const char *key, const char *value) {
    unsigned int index = hash(key);
    Entry *curr = table->buckets[index];

    while(curr) {
        if(strcmp(curr->key, key) == 0) {
            free(curr->value);
            curr->value = strdup(value);
            return;
        }
        curr = curr->next;
    }

    Entry *entry = malloc(sizeof(Entry));
    entry->key = strdup(key);
    entry->value = strdup(value);
    entry->next = table->buckets[index];
    table->buckets[index] = entry;
}

char* get(HashTable* table, const char *key) {
    unsigned int index = hash(key);
    Entry *curr = table->buckets[index];

    while(curr){
        if(strcmp(curr->key, key) == 0) {
            return curr->value;
        }
        curr = curr->next;
    }
    return NULL;
}

void delete(HashTable *table, const char* key) {
    unsigned int index = hash(key);
    Entry *curr = table->buckets[index];
    Entry *prev = NULL;

    while(curr) {
        if(strcmp(curr->key, key) == 0){
            if(prev) prev->next = curr->next;
            else table->buckets[index] = curr->next;

            free(curr->key);
            free(curr->value);
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

void free_table(HashTable *table) {
    for(int i=0;i<TABLE_SIZE;i++){
        Entry *curr = table->buckets[i];
        while(curr){
            Entry *tmp = curr;
            curr = curr->next;
            free(tmp->key);
            free(tmp->value);
            free(tmp);
        }
    }
    free(table);
}

int main(){
    HashTable *db = create_table();
    char command[256];
    char key[128], value[128];

    printf("Simple Key-Value DB (SET, GET, DELETE, EXIT) \n");

    while(1) {
        printf("> ");
        fgets(command, sizeof(command), stdin);

        if (sscanf(command, "SET %127s %127s", key, value) == 2) {
            set(db, key, value);
            printf("OK\n");
        }
        else if (sscanf(command, "GET %127s", key) == 1) {
            char *result = get(db, key);
            if (result) printf("%s\n", result);
            else printf("NULL\n");
        }
        else if (sscanf(command, "DELETE %127s", key) == 1) {
            delete(db, key);
            printf("OK\n");
        }
        else if (strncmp(command, "EXIT", 4) == 0) {
            break;
        }
        else {
            printf("Invalid command\n");
        }
    }

    free_table(db);
    return 0;
}