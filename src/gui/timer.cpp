#include <QTime>

#include <timer.h>

DruidTimer::DruidTimer()
{
    setupUi( this );

    _time_lcd->setDigitCount(8);

    connect( _time_start, &QPushButton::clicked, this, &DruidTimer::time_start );
    connect( _time_stop, &QPushButton::clicked, this, &DruidTimer::time_stop );
}

void DruidTimer::time_start()
{
    const int hours = _time_hour->value();
    const int minutes = _time_minutes->value();
    const int msecs = ( hours * 60 * 60 + minutes * 60 ) * 1000;

    _time_lcd->display( DruidTimer::msecs_to_string( msecs ) );
    QTimer::singleShot( 1000, this, &DruidTimer::time_update );
    _timer.start( msecs );
    _timer_stop = false;
}

void DruidTimer::time_update()
{
    if ( ! _timer_stop )
    {
        const int msecs = _timer.remainingTime();
        _time_lcd->display( DruidTimer::msecs_to_string( msecs ) );

        if ( msecs/1000 > 0 )
        {
            QTimer::singleShot(1000, this, &DruidTimer::time_update);
        }
        else
        {
            _timer.stop();
        }
    }
}

void DruidTimer::time_stop()
{
    _timer_stop = true;
}

QString DruidTimer::msecs_to_string( const int millisecondes )
{
    int secondes = millisecondes/1000;
    int minutes = secondes/60;
    const int hours = minutes/60;

    minutes = minutes - hours * 60;
    secondes = secondes - hours * 60 * 60 - minutes * 60;

    const QTime time( hours, minutes, secondes );
    return time.toString( "hh:mm:ss" );
}
