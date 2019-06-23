#include <stdio.h>
#include "sqlite3.h"

int main()
{
	sqlite3* conn;
	sqlite3_stmt* stmt;
	int retcode;

	///////
	retcode = sqlite3_open_v2("test_sqlite.db", 
			&conn, SQLITE_OPEN_READONLY, NULL);
	if (retcode != SQLITE_OK) {
		printf("Error connecting to database: %d - %s\n", retcode, sqlite3_errmsg(conn));
		return 1;
	}

	printf("Connection open!\n");

	retcode = sqlite3_prepare_v2(conn, "select * from pessoa", 
			-1, &stmt, NULL);
	if (retcode != SQLITE_OK) {
		printf("Error compiling statement: %d - %s\n", retcode, sqlite3_errmsg(conn));
	}

	printf("|Nome                   |Idade|\n");
	printf("|-----------------------|-----|\n");
	while (1) {
		retcode = sqlite3_step(stmt);
		if (retcode == SQLITE_ROW) {
			printf("|%-23s|%5d|\n",
					sqlite3_column_text(stmt, 0),
					sqlite3_column_int(stmt, 1));
		} else if (retcode == SQLITE_DONE) {
			printf("----- No more data\n");
			break;
		} else {
			printf("Error executing statement: %d - %s\n", retcode, sqlite3_errmsg(conn));
			break;
		}
	}

	sqlite3_finalize(stmt);

	if (sqlite3_close_v2(conn) == SQLITE_OK) {
		printf("Connection successfully closed\n");
	} else {
		printf("Error closing connection!");
	}

	return 0;
}
