#include "chrismail.h"

bool sendmail(Email *email, Server *server) {
    struct sockaddr_in sock;
    signed int tmp;
    int16 s;

    tmp = socket(AF_INET, SOCK_STREAM, 0);
    assert(tmp > 0);
    s = (int16)tmp;

    sock.sin_family = AF_INET;
    sock.sin_port = htons(25);
    sock.sin_addr.s_addr = server->ip;
    tmp = connect($i s, (struct sockaddr *)&sock, sizeof(struct sockaddr));
    assert(!tmp);
}

int main(int argc, char *argv[]) {
    return 0;
}