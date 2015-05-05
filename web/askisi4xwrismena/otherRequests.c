#include "otherRequests.h"



void sendDelete(char *file, int new_socket, int typeCon){
   struct stat file_stat;
    char *contents_chopped = file + 1;

    int ret;
    int fd;
    int sent_bytes = 0;
#ifdef DEBUG
    printf("%s\n", contents_chopped);
#endif

        ret = remove(contents_chopped);
        if (ret!=0){
            printf("Den vrethike arxeio. \n");
            notfound(new_socket, typeCon);
            return;
        }
        else{
        char head[13] = "Delete OK\r\n";
        if (write(new_socket, ok, 17) < 0) {
            printf("ERROR: couldn't write to socket\n");
            exit(EXIT_FAILURE);
        };

        if (write(new_socket, "Server: Marios and Evanthia Server\r\n", 36) < 0) {
            printf("ERROR: couldn't write to socket\n");
            exit(EXIT_FAILURE);
        };
        if (write(new_socket, "Content-Length: ", 16) < 0) {
            printf("ERROR: couldn't write to socket\n");
            exit(EXIT_FAILURE);
        };

        if (write(new_socket, "11", 2) < 0) {
            printf("ERROR: couldn't write to socket\n");
            exit(EXIT_FAILURE);
        };

        if (write(new_socket, "\r\n", 2) < 0) {
            printf("ERROR: couldn't write to socket\n");
            exit(EXIT_FAILURE);
        };
        char cnc[25];
        printf("Epestrepse to arxeio: %s\n" ,contents_chopped );

        if (typeCon == 1) {
            strcpy(cnc, "Connection: keep-alive\r\n");

        } else {
            strcpy(cnc, "Connection: close\r\n");
        }

        if (write(new_socket, cnc, strlen(cnc)) < 0) {
            printf("ERROR: couldn't write to socket\n");
            exit(EXIT_FAILURE);
        };

#ifdef DEBUG
        printf("Hello Pire Tipo\n");
        printf("%s\n", tipos);
        printf("%s\n", len);
#endif
        if (write(new_socket, "Content-Type: text/plain", 24) < 0) {
            printf("ERROR: couldn't write to socket\n");
            exit(EXIT_FAILURE);
        };

        if (write(new_socket, "\r\n", 2) < 0) {
            printf("ERROR: couldn't write to socket\n");
            exit(EXIT_FAILURE);
        };
        if (write(new_socket, "\r\n", 2) < 0) {
            printf("ERROR: couldn't write to socket\n");
            exit(EXIT_FAILURE);
        };

        if (write(new_socket, head, strlen(head)) < 0) {
            printf("ERROR: couldn't write to socket\n");
            exit(EXIT_FAILURE);
        };
      }
    return;
}

void sendNotImpl(int new_socket, int typeCon){

    int ret;
    int fd;
    int sent_bytes = 0;
#ifdef DEBUG
    printf("%s\n", contents_chopped);
#endif

            printf("Den vrethike arxeio. \n");
        char notim[26]="Method not implemented.\r\n";

        if (write(new_socket, notImpl, 30) < 0) {
            printf("ERROR: couldn't write to socket\n");
            exit(EXIT_FAILURE);
        };

        if (write(new_socket, "Server: Marios and Evanthia Server\r\n", 36) < 0) {
            printf("ERROR: couldn't write to socket\n");
            exit(EXIT_FAILURE);
        };
        if (write(new_socket, "Content-Length: ", 16) < 0) {
            printf("ERROR: couldn't write to socket\n");
            exit(EXIT_FAILURE);
        };

        if (write(new_socket, "25",2) < 0) {
            printf("ERROR: couldn't write to socket\n");
            exit(EXIT_FAILURE);
        };

        if (write(new_socket, "\r\n", 2) < 0) {
            printf("ERROR: couldn't write to socket\n");
            exit(EXIT_FAILURE);
        };
        char cnc[25];

        if (typeCon == 1) {
            strcpy(cnc, "Connection: keep-alive\r\n");

        } else {
            strcpy(cnc, "Connection: close\r\n");
        }

        if (write(new_socket, cnc, strlen(cnc)) < 0) {
            printf("ERROR: couldn't write to socket\n");
            exit(EXIT_FAILURE);
        };   
#ifdef DEBUG
        printf("Hello Pire Tipo\n");
        printf("%s\n", tipos);
        printf("%s\n", len);
#endif
        if (write(new_socket, "Content-Type: text/plain", 24) < 0) {
            printf("ERROR: couldn't write to socket\n");
            exit(EXIT_FAILURE);
        };
        if (write(new_socket, "\r\n", 2) < 0) {
            printf("ERROR: couldn't write to socket\n");
            exit(EXIT_FAILURE);
        };
        if (write(new_socket, "\r\n", 2) < 0) {
            printf("ERROR: couldn't write to socket\n");
            exit(EXIT_FAILURE);
        };
        if (write(new_socket, notim, strlen(notim)) < 0) {
            printf("ERROR: couldn't write to socket\n");
            exit(EXIT_FAILURE);
        };
    return;
}

void notfound(int new_socket, int typeCon){


            printf("Den vrethike arxeio. \n");
        char notim[23]="Document not Found.\r\n";

        if (write(new_socket, notFound, 24) < 0) {
            printf("ERROR: couldn't write to socket\n");
            exit(EXIT_FAILURE);
        };

        if (write(new_socket, "Server: Marios and Evanthia Server\r\n", 36) < 0) {
            printf("ERROR: couldn't write to socket\n");
            exit(EXIT_FAILURE);
        };
        if (write(new_socket, "Content-Length: ", 16) < 0) {
            printf("ERROR: couldn't write to socket\n");
            exit(EXIT_FAILURE);
        };

        if (write(new_socket, "19", 2) < 0) {
            printf("ERROR: couldn't write to socket\n");
            exit(EXIT_FAILURE);
        };

        if (write(new_socket, "\r\n", 2) < 0) {
            printf("ERROR: couldn't write to socket\n");
            exit(EXIT_FAILURE);
        };
        char cnc[25];

        if (typeCon == 1) {
            strcpy(cnc, "Connection: keep-alive\r\n");

        } else {
            strcpy(cnc, "Connection: close\r\n");
        }

        if (write(new_socket, cnc, strlen(cnc)) < 0) {
            printf("ERROR: couldn't write to socket\n");
            exit(EXIT_FAILURE);
        };

       
#ifdef DEBUG
        printf("Hello Pire Tipo\n");
        printf("%s\n", tipos);
        printf("%s\n", len);
#endif
        if (write(new_socket, "Content-Type: text/plain", 24) < 0) {
            printf("ERROR: couldn't write to socket\n");
            exit(EXIT_FAILURE);
        };
        if (write(new_socket, "\r\n", 2) < 0) {
            printf("ERROR: couldn't write to socket\n");
            exit(EXIT_FAILURE);
        };
        if (write(new_socket, "\r\n", 2) < 0) {
            printf("ERROR: couldn't write to socket\n");
            exit(EXIT_FAILURE);
        };

        if (write(new_socket, "Document not Found.", 19) < 0) {
            printf("ERROR: couldn't write to socket\n");
            exit(EXIT_FAILURE);
        };
    return;
}


