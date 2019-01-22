#pragma once

#include <sqlite3.h>

#include <QString>

class DruidDb
{
    public:
        DruidDb();
        ~DruidDb();

        bool open( const QString &filename );
        bool close();

        bool exec( const QString &sql );

    private:
        sqlite3 *_db = nullptr;
};
