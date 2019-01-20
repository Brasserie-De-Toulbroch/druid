#include <QTime>

#include <central_widget.h>
#include <iostream>

DruidCentralWidget::DruidCentralWidget()
{
    setupUi( this );

    _time_lcd->setDigitCount(8);

    connect( _time_start, &QPushButton::clicked, this, &DruidCentralWidget::time_start );
    connect( _time_stop, &QPushButton::clicked, this, &DruidCentralWidget::time_stop );
}

void DruidCentralWidget::time_start()
{
    const int hours = _time_hour->value();
    const int minutes = _time_minutes->value();
    const int msecs = ( hours * 60 * 60 + minutes * 60 ) * 1000;

    _timer.start( msecs );
    _time_lcd->display( DruidCentralWidget::msecs_to_string( msecs ) );
    _timer_stop = false;

    QTimer::singleShot( 1000, this, &DruidCentralWidget::time_update );
}

void DruidCentralWidget::time_update()
{
    if ( ! _timer_stop )
    {
        QTimer::singleShot(1000, this, &DruidCentralWidget::time_update);

        const int msecs = _timer.remainingTime();
        _time_lcd->display( DruidCentralWidget::msecs_to_string( msecs ) );
    }
}

void DruidCentralWidget::time_stop()
{
    _timer_stop = true;
}

QString DruidCentralWidget::msecs_to_string( const int millisecondes )
{
    int secondes = millisecondes/1000;
    int minutes = secondes/60;
    const int hours = minutes/60;

    minutes = minutes - hours * 60;
    secondes = secondes - hours * 60 * 60 - minutes * 60;

    const QTime time( hours, minutes, secondes );
    return time.toString( "hh:mm:ss" );
}
