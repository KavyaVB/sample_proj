XYZ.exe: pal.o
 gcc -o XYZ.exe pal.o
pal.o: pal.c
 gcc -c pal.c
