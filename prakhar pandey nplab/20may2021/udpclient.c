#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#define SA struct sockaddr
int main(void)
{
    int socket_d;
    struct sockaddr_in server_addr;
    char server_message[100], client_message[100];
    int server_struct_length = sizeof(server_addr);

    // Clean buffers:
    memset(server_message, '\0', sizeof(server_message));
    memset(client_message, '\0', sizeof(client_message));

    // Create socket:
    socket_d = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    if (socket_d < 0)
    {
        printf("Error while creating socket\n");
        return -1;
    }
    printf("Socket created successfully\n");

    // Set port and IP:
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(2000);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Get input from the user:
    printf("Enter message: ");
    gets(client_message);

    // Send the message to server:
    if (sendto(socket_d, client_message, strlen(client_message), 0,
               (SA *)&server_addr, server_struct_length) < 0)
    {
        printf("Unable to send message\n");
        return -1;
    }

    // Receive the server's response:
    if (recvfrom(socket_d, server_message, sizeof(server_message), 0,
                 (SA *)&server_addr, &server_struct_length) < 0)
    {
        printf("Error while receiving server's msg\n");
        return -1;
    }

    printf("Server's response: %s\n", server_message);

    close(socket_d);

    return 0;
}