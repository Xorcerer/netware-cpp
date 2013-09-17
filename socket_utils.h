#ifndef SOCKET_UTILS_H
#define SOCKET_UTILS_H

// ref: `man select_tut` or http://www.tutorialspoint.com/unix_system_calls/select_tut.htm

#include <sys/socket.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

static int connect_socket (int connect_port,
                           char *address) {
    struct sockaddr_in a;
    int s;
    if ((s = socket (AF_INET, SOCK_STREAM, 0)) < 0) {
        perror ("socket");
        close (s);
        return -1;
    }


    memset (&a, 0, sizeof (a));
    a.sin_port = htons (connect_port);
    a.sin_family = AF_INET;


    if (!inet_aton
        (address,
         (struct in_addr *) &a.sin_addr.s_addr)) {
        perror ("bad IP address format");
        close (s);
        return -1;
    }


    if (connect
        (s, (struct sockaddr *) &a,
         sizeof (a)) < 0) {
        perror ("connect()");
        shutdown (s, SHUT_RDWR);
        close (s);
        return -1;
    }
    return s;
}

void shut_fd (int& fd)
{
    if (fd >= 0) {
        shutdown (fd, SHUT_RDWR);
        close (fd);
        fd = -1;
    }
}

#endif // SOCKET_UTILS_H
