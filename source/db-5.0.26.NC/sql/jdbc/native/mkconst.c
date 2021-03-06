#include <stdio.h>
#if HAVE_SQLITE3
#include <sqlite3.h>
#else
#if HAVE_SQLITE2
#include <sqlite.h>
#endif
#endif

#ifndef SQLITE_VERSION
/* last resort */
#include <sqlite.h>
#endif

#if defined(_WIN32) || (HAVE_SQLITE3)
#define PCONST(code)							\
    printf("    /* Error code: %d */\n", code);				\
    printf("    public static final int "#code" = %d;\n", code);
#else
#define PCONST(code)							\
    printf("    /**\n");						\
    printf("     * Error code: '%s'\n", sqlite_error_string(code));	\
    printf("     */\n");						\
    printf("    public static final int "#code" = %d;\n", code);
#endif

#define QCONST(code)							\
    printf("    public static final int "#code" = %d;\n", code);

int
main()
{
    int minor = 99999999;
    FILE *f = fopen("VERSION", "r");

    if (f) {
	fscanf(f, "%d", &minor);
	fclose(f);
    }
    printf("/* DO NOT EDIT */\n\n");
    printf("package SQLite;\n\n");
    printf("/**\n");
    printf(" * Container for SQLite constants.\n");
    printf(" */\n\n");
    printf("public final class Constants {\n");
    PCONST(SQLITE_OK);
    PCONST(SQLITE_ERROR);
    PCONST(SQLITE_INTERNAL);
    PCONST(SQLITE_PERM);
    PCONST(SQLITE_ABORT);
    PCONST(SQLITE_BUSY);
    PCONST(SQLITE_LOCKED);
    PCONST(SQLITE_NOMEM);
    PCONST(SQLITE_READONLY);
    PCONST(SQLITE_INTERRUPT);
    PCONST(SQLITE_IOERR);
    PCONST(SQLITE_CORRUPT);
    PCONST(SQLITE_NOTFOUND);
    PCONST(SQLITE_FULL);
    PCONST(SQLITE_CANTOPEN);
    PCONST(SQLITE_PROTOCOL);
    PCONST(SQLITE_EMPTY);
    PCONST(SQLITE_SCHEMA);
    PCONST(SQLITE_TOOBIG);
    PCONST(SQLITE_CONSTRAINT);
    PCONST(SQLITE_MISMATCH);
    PCONST(SQLITE_MISUSE);

#ifndef SQLITE_NOLFS
#define SQLITE_NOLFS (SQLITE_MISUSE + 1)
#endif
    PCONST(SQLITE_NOLFS);

#ifndef SQLITE_AUTH
#define SQLITE_AUTH (SQLITE_NOLFS + 1)
#endif
    PCONST(SQLITE_AUTH);

#ifndef SQLITE_FORMAT
#define SQLITE_FORMAT (SQLITE_AUTH + 1)
#endif
    PCONST(SQLITE_FORMAT);

#ifndef SQLITE_RANGE
#define SQLITE_RANGE (SQLITE_FORMAT + 1)
#endif
    PCONST(SQLITE_RANGE);

#ifndef SQLITE_NOTADB
#define SQLITE_NOTADB (SQLITE_RANGE + 1)
#endif
    PCONST(SQLITE_NOTADB);

#ifndef SQLITE_ROW
#define SQLITE_ROW 100
#endif
    QCONST(SQLITE_ROW);

#ifndef SQLITE_DONE
#define SQLITE_DONE (SQLITE_ROW + 1)
#endif
    QCONST(SQLITE_DONE);

#ifndef SQLITE_INTEGER
#define SQLITE_INTEGER 1
#endif
    QCONST(SQLITE_INTEGER);

#ifndef SQLITE_FLOAT
#define SQLITE_FLOAT 2
#endif
    QCONST(SQLITE_FLOAT);

#ifndef SQLITE_BLOB
#define SQLITE_BLOB 4
#endif
    QCONST(SQLITE_BLOB);

#ifndef SQLITE_NULL
#define SQLITE_NULL 5
#endif
    QCONST(SQLITE_NULL);

#ifndef SQLITE3_TEXT
#define SQLITE3_TEXT 3
#endif
    QCONST(SQLITE3_TEXT);

#ifndef SQLITE_NUMERIC
#define SQLITE_NUMERIC (-1)
#endif
    QCONST(SQLITE_NUMERIC);

#ifndef SQLITE_TEXT
#ifdef HAVE_SQLITE3
#define SQLITE_TEXT 3
#else
#define SQLITE_TEXT (-2)
#endif
#endif
    QCONST(SQLITE_TEXT);

#ifndef SQLITE2_TEXT
#define SQLITE2_TEXT (-2)
#endif
    QCONST(SQLITE2_TEXT);

#ifndef SQLITE_ARGS
#define SQLITE_ARGS (-3)
#endif
    QCONST(SQLITE_ARGS);

#ifndef SQLITE_COPY
#define SQLITE_COPY 0
#endif
    QCONST(SQLITE_COPY);

#ifndef SQLITE_CREATE_INDEX
#define SQLITE_CREATE_INDEX 1
#endif
    QCONST(SQLITE_CREATE_INDEX);

#ifndef SQLITE_CREATE_TABLE
#define SQLITE_CREATE_TABLE 2
#endif
    QCONST(SQLITE_CREATE_TABLE);

#ifndef SQLITE_CREATE_TEMP_INDEX
#define SQLITE_CREATE_TEMP_INDEX 3
#endif
    QCONST(SQLITE_CREATE_TEMP_INDEX);

#ifndef SQLITE_CREATE_TEMP_TABLE
#define SQLITE_CREATE_TEMP_TABLE 4
#endif
    QCONST(SQLITE_CREATE_TEMP_TABLE);

#ifndef SQLITE_CREATE_TEMP_TRIGGER
#define SQLITE_CREATE_TEMP_TRIGGER 5
#endif
    QCONST(SQLITE_CREATE_TEMP_TRIGGER);

#ifndef SQLITE_CREATE_TEMP_VIEW
#define SQLITE_CREATE_TEMP_VIEW 6
#endif
    QCONST(SQLITE_CREATE_TEMP_VIEW);

#ifndef SQLITE_CREATE_TRIGGER
#define SQLITE_CREATE_TRIGGER 7
#endif
    QCONST(SQLITE_CREATE_TRIGGER);

#ifndef SQLITE_CREATE_VIEW
#define SQLITE_CREATE_VIEW 8
#endif
    QCONST(SQLITE_CREATE_VIEW);

#ifndef SQLITE_DELETE
#define SQLITE_DELETE 9
#endif
    QCONST(SQLITE_DELETE);

#ifndef SQLITE_DROP_INDEX
#define SQLITE_DROP_INDEX 10
#endif
    QCONST(SQLITE_DROP_INDEX);

#ifndef SQLITE_DROP_TABLE
#define SQLITE_DROP_TABLE 11
#endif
    QCONST(SQLITE_DROP_TABLE);

#ifndef SQLITE_DROP_TEMP_INDEX
#define SQLITE_DROP_TEMP_INDEX 12
#endif
    QCONST(SQLITE_DROP_TEMP_INDEX);

#ifndef SQLITE_DROP_TEMP_TABLE
#define SQLITE_DROP_TEMP_TABLE 13
#endif
    QCONST(SQLITE_DROP_TEMP_TABLE);

#ifndef SQLITE_DROP_TEMP_TRIGGER
#define SQLITE_DROP_TEMP_TRIGGER 14
#endif
    QCONST(SQLITE_DROP_TEMP_TRIGGER);

#ifndef SQLITE_DROP_TEMP_VIEW
#define SQLITE_DROP_TEMP_VIEW 15
#endif
    QCONST(SQLITE_DROP_TEMP_VIEW);

#ifndef SQLITE_DROP_TRIGGER
#define SQLITE_DROP_TRIGGER 16
#endif
    QCONST(SQLITE_DROP_TRIGGER);

#ifndef SQLITE_DROP_VIEW
#define SQLITE_DROP_VIEW 17
#endif
    QCONST(SQLITE_DROP_VIEW);

#ifndef SQLITE_INSERT
#define SQLITE_INSERT 18
#endif
    QCONST(SQLITE_INSERT);

#ifndef SQLITE_PRAGMA
#define SQLITE_PRAGMA 19
#endif
    QCONST(SQLITE_PRAGMA);

#ifndef SQLITE_READ
#define SQLITE_READ 20
#endif
    QCONST(SQLITE_READ);

#ifndef SQLITE_SELECT
#define SQLITE_SELECT 21
#endif
    QCONST(SQLITE_SELECT);

#ifndef SQLITE_TRANSACTION
#define SQLITE_TRANSACTION 22
#endif
    QCONST(SQLITE_TRANSACTION);

#ifndef SQLITE_UPDATE
#define SQLITE_UPDATE 23
#endif
    QCONST(SQLITE_UPDATE);

#ifndef SQLITE_ATTACH
#define SQLITE_ATTACH 24
#endif
    QCONST(SQLITE_ATTACH);

#ifndef SQLITE_DETACH
#define SQLITE_DETACH 25
#endif
    QCONST(SQLITE_DETACH);

#ifndef SQLITE_DENY
#define SQLITE_DENY 1
#endif
    QCONST(SQLITE_DENY);

#ifndef SQLITE_IGNORE
#define SQLITE_IGNORE 2
#endif
    QCONST(SQLITE_IGNORE);

#ifndef SQLITE_OPEN_NOMUTEX
#define SQLITE_OPEN_NOMUTEX 0
#endif
    QCONST(SQLITE_OPEN_NOMUTEX);

#ifndef SQLITE_OPEN_FULLMUTEX
#define SQLITE_OPEN_FULLMUTEX 0
#endif
    QCONST(SQLITE_OPEN_FULLMUTEX);

#ifndef SQLITE_OPEN_READONLY
#define SQLITE_OPEN_READONLY 0
#endif
    QCONST(SQLITE_OPEN_READONLY);

#ifndef SQLITE_OPEN_READWRITE
#define SQLITE_OPEN_READWRITE 0
#endif
    QCONST(SQLITE_OPEN_READWRITE);

#ifndef SQLITE_OPEN_CREATE
#define SQLITE_OPEN_CREATE 0
#endif
    QCONST(SQLITE_OPEN_CREATE);

    printf("    public static final int drv_minor = %d;\n",
	   minor);

    printf("}\n");
    return 0;
}
