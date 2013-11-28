#ifndef SOCKET_UTILS_H
#define SOCKET_UTILS_H

// ref: `man select_tut` or http://www.tutorialspoint.com/unix_system_calls/select_tut.htm

#include <sys/socket.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

static int connect_socket(int port, char const *address_str)
{
    struct sockaddr_in addr;
    int fd;
    if ((fd = socket (AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror ("socket()");
        close (fd);
        return -1;
    }

    memset (&addr, 0, sizeof (addr));
    addr.sin_port = htons (port);
    addr.sin_family = AF_INET;

    if (!inet_aton(address_str, (struct in_addr *) &addr.sin_addr.s_addr))
    {
        perror ("bad IP address format");
        close (fd);
        return -1;
    }


    if (connect(fd, (struct sockaddr *) &addr, sizeof (addr)) < 0)
    {
        perror ("connect()");
        shutdown (fd, SHUT_RDWR);
        close (fd);
        return -1;
    }
    return fd;
}

#endif // SOCKET_UTILS_H
