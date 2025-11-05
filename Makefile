bookmark: main 
	gcc build/main.o build/goto.o build/entry.o build/path.o build/delete.o build/list.o -o bin/bookmark

main : goto entry path delete list 
	gcc -c src/main.c -o build/main.o

goto :
	gcc -c src/goto.c -o build/goto.o

entry : 
	gcc -c src/entry.c -o build/entry.o

path :
	gcc -c src/path.c -o build/path.o

delete :
	gcc -c src/delete.c -o build/delete.o

list : 
	gcc -c src/list.c -o build/list.o
