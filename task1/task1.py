import sqlite3
import sys

# Function to convert a SQLite database to human-readable text
def convert_db_to_text(db_file):
    # Connect to the SQLite database
    conn = sqlite3.connect(db_file)
    cursor = conn.cursor()

    # Get the list of table names in the database
    cursor.execute("SELECT name FROM sqlite_master WHERE type='table';")
    tables = cursor.fetchall()

    # Iterate through each table and extract the data
    for table in tables:
        table_name = table[0]
        print(f"Table: {table_name}\n")

        # Fetch all records from the table
        cursor.execute(f"SELECT * FROM {table_name};")
        rows = cursor.fetchall()

        # Get the column names
        column_names = [description[0] for description in cursor.description]

        # Print column names
        print("\t".join(column_names))

        # Print the data
        for row in rows:
            print("\t".join(map(str, row)))

        print("\n")

    if conn:
        conn.close()

def main():
    # Provide the path to the SQLite database file you want to convert
    db_file = sys.argv[1]
    
    # Call the function to convert the database to human-readable text
    convert_db_to_text(db_file)


if __name__ == "__main__":
    main()