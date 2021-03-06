#include "helpers.h"

char *giveContentType(char *file) {
    char temp[18];
    char *split;
    char *word;
    split = strtok(file, ".");
    while (split != NULL) {
        word = split;
        split = strtok(NULL, ".");
    }

    if ((strcmp(word, "txt") == 0) || (strcmp(word, "sed") == 0) || (strcmp(word, "awk") == 0)) {
        strcpy(temp, "text/plain\0");

    }
    if ((strcmp(word, "h") == 0) || (strcmp(word, "c") == 0)) {
        strcpy(temp, "text/plain\0");

    }

    if ((strcmp(word, "html") == 0) || (strcmp(word, "htm") == 0)) {

        temp[0] = '\0';
        strcpy(temp, "text/html\0");

    }
    if ((strcmp(word, "jpeg") == 0) || (strcmp(word, "jpg") == 0)||(strcmp(word, "png") == 0)) {
        strcpy(temp, "image/jpeg\0");
    }
    
    if (strcmp(word, "gif") == 0) {
        strcpy(temp, "image/gif\0");
    }
    if (strcmp(word, "pdf") == 0) {
        strcpy(temp, "application/pdf\0");
    }
    char *str = malloc(18);
    strcpy(str, temp);
    return str;
}



void readConfig() {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    fp = fopen("config.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    char tmp[8];
    while ((read = getline(&line, &len, fp)) != -1) {
        if (strstr(line, "THREADS")) {
            memcpy(tmp, &line[8], 7);
            tmp[7] = '\0';
            WORKERS = atoi(tmp);
            printf("WORKERS : %d \n", WORKERS);
        }
        else if (strstr(line, "PORT")) {
            memcpy(tmp, &line[5], 7);
            tmp[7] = '\0';
            PORT = atoi(tmp);
            printf("PORT : %d \n", PORT);
        }
    }
    fclose(fp);
    if (line)
        free(line);
}
