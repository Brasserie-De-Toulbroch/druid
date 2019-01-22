#include <QHBoxLayout>

#include "menu.h"

DruidMenu::DruidMenu()
{
    QHBoxLayout *layout = new QHBoxLayout();

    _edit = new QPushButton( "Edit" );
    layout->addWidget( _edit );

    _save = new QPushButton( "Save" );
    layout->addWidget( _save );

    _load = new QPushButton( "Load" );
    layout->addWidget( _load );

    setLayout( layout );
}
