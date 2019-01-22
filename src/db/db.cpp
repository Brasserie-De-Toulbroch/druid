#include "db.h"

DruidDb::DruidDb()
{
}

DruidDb::~DruidDb()
{
    close();
}

bool DruidDb::open( const QString &filename )
{
    if ( _db )
    {
        close();
    }

    return sqlite3_open(filename.toStdString().c_str(), &_db);
}

bool DruidDb::close()
{
    if ( _db )
    {
        sqlite3_close(_db);
        _db = nullptr;
    }
}

bool DruidDb::exec( const QString &sql )
{
    return sqlite3_exec(_db, sql.toStdString().c_str(), 0, 0, 0 );
}
