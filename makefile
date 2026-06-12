XYZ.exe:server.o
    gcc -o XYZ.exe server.o
server.o:server.c
    gcc -c server.c
