#include <stdio.h>
#include <stdlib.h>

void web() {
    // Define the website you want to display
    const char *url = "https://google.com";
    
    printf("Opening %s in your default web browser...\n", url);

    #if defined(_WIN32) || defined(_WIN64)
        // Windows command to launch default browser via command prompt
        // UseShellExecute-equivalent approach via system line
        char cmd[256];
        snprintf(cmd, sizeof(cmd), "cmd /c start %s", url);
        system(cmd);

    #elif defined(__APPLE__)
        // macOS native command to open links
        char cmd[256];
        snprintf(cmd, sizeof(cmd), "open %s", url);
        system(cmd);

    #elif defined(__linux__)
        // Linux Desktop standard command to resolve default applications
        char cmd[256];
        snprintf(cmd, sizeof(cmd), "xdg-open %s", url);
        system(cmd);

    #else
        printf("Unsupported operating system.\n");
    #endif

    //return 0;
}
