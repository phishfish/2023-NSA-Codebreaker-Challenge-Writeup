#include <stdio.h>
#include <sqlite3.h>

// Function to convert a SQLite database to human-readable text
void convertDbToText(const char* dbFile) 
{
    sqlite3* db;
    char* errMsg = 0;

    // Open the SQLite database
    if (sqlite3_open(dbFile, &db) == SQLITE_OK) 
    {
        sqlite3_stmt* stmt;
        const char* query = "SELECT name FROM sqlite_master WHERE type='table';";
        
        // Execute the query to get table names
        if (sqlite3_prepare_v2(db, query, -1, &stmt, 0) == SQLITE_OK) 
	{
            while (sqlite3_step(stmt) == SQLITE_ROW) 
	    {
                const unsigned char* tableName = sqlite3_column_text(stmt, 0);
                printf("Table: %s\n\n", tableName);

                const char* selectQuery = "SELECT * FROM %s;";
                char fullQuery[256];
                snprintf(fullQuery, sizeof(fullQuery), selectQuery, tableName);

                sqlite3_stmt* dataStmt;

                // Execute the query to get table data
                if (sqlite3_prepare_v2(db, fullQuery, -1, &dataStmt, 0) == SQLITE_OK) 
		{
                    int columnCount = sqlite3_column_count(dataStmt);

                    // Print column names
                    for (int i = 0; i < columnCount; i++) 
		    {
                        printf("%s\t", sqlite3_column_name(dataStmt, i));
                    }
                    printf("\n");

                    // Print the data
                    while (sqlite3_step(dataStmt) == SQLITE_ROW) 
		    {
                        for (int i = 0; i < columnCount; i++) 
			{
                            const unsigned char* value = sqlite3_column_text(dataStmt, i);
                            printf("%s\t", value);
                        }
                        printf("\n");
                    }

                    printf("\n");
                    sqlite3_finalize(dataStmt);
                }
            }

            sqlite3_finalize(stmt);
        }

        sqlite3_close(db);
    } 
    else 
    {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
    }
}

int main(int argc, char* argv[]) 
{
    if (argc != 2) 
    {
        fprintf(stderr, "Usage: %s <database_file>\n", argv[0]);
        return 1;
    }

    const char* dbFile = argv[1];

    // Call the function to convert the database to human-readable text
    convertDbToText(dbFile);

    return 0;
}
