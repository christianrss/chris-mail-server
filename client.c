#include "chrismail.h"

bool sendmail(Email *email, Server *server) {
    int8 buf[256];
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

    log("Connected to %s\n", $c server->server);

    zero(buf, 256);
    tmp = read($i s, $c buf, 255);
    dprintf($i s, "EHLO %s\n", $c email->domain);

    zero(buf, 256);
    tmp = read($i s, $c buf, 255);
    log("From server: '%s'\n", $c buf);
    close(s);

    return true;
}

int main(int argc, char *argv[]) {
    Email *e;
    Server *s;
    bool ret;

    e = (Email *)malloc(sizeof(struct s_email));
    zero($1 e, sizeof(struct s_email));
    s = (Server *)malloc(sizeof(struct s_server));
    zero($1 s, sizeof(struct s_server));

    strncpy($c e->src, $c "someemail@someserver.com.br", 63);
    e->domain = e->src + 11;
    strncpy($c s->server, $c "mx3.somedomain.com.br", 63);
    s->ip = inet_addr("someip");

    ret = sendmail(e, s);
    log("%d\n", ret);
    free(e);
    free(s);

    return 0;
}