XYZ.exe:main.o pal.o web_browser.o
 gcc -o XYZ.exe main.o pal.o web_browser.o
main.o:main.c
 gcc -c main.c
pal.o:pal.c
 gcc -c pal.c
web_browser.o:web_browser.c
 gcc -c web_browser.c
