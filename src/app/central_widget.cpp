#include <central_widget.h>

DruidCentralWidget::DruidCentralWidget()
{
    setupUi( this );

    _top_layout->insertWidget( 0, &_menu );

    _right_layout->addWidget( &_timer );
    _right_layout->addWidget( &_volume );
    _right_layout->addWidget( &_notes );
}
