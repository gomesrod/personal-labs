
all: sqlite3.o test_sqlite.o
	cc sqlite3.o test_sqlite.o -o test_sqlite.exe

sqlite3.o: sqlite3.c
	cc -c sqlite3.c -o sqlite3.o

test_sqlite.o: test_sqlite.c
	cc -c test_sqlite.c -o test_sqlite.o

clean:
	rm  test_sqlite.exe sqlite3.o test_sqlite.o
