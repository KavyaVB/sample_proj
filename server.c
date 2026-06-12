#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 2048

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // 1. Create a socket file descriptor (IPv4, TCP protocol)
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // 2. Define the server address and bind to PORT 8080
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; // Accept connections from any IP
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // 3. Start listening for incoming requests (backlog queue of 3)
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server successfully launched! Open your browser and go to http://localhost:%d\n", PORT);

    // 4. Infinite loop to keep the website active and accept connections
    while (1) {
        new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_list_t*)&addrlen);
        if (new_socket < 0) {
            perror("Accept connection failed");
            continue;
        }

        // Read the incoming HTTP request from the browser
        read(new_socket, buffer, BUFFER_SIZE);
        
        // Define the HTTP header and HTML page content to send back
        char *http_header = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
        char *html_content = 
            "<!DOCTYPE html>"
            "<html>"
            "<head><title>My C Website</title></head>"
            "<body style='font-family:Arial; text-align:center; margin-top:50px;'>"
            "<h1>Welcome to my C-Powered Website!</h1>"
            "<p>This entire page is served using raw C socket programming.</p>"
            "</body>"
            "</html>";

        // Send the HTTP header first, then the HTML body
        send(new_socket, http_header, strlen(http_header), 0);
        send(new_socket, html_content, strlen(html_content), 0);

        // Close the connection for the current request
        close(new_socket);
    }

    close(server_fd);
    return 0;
}
