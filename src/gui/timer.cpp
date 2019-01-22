#include <QTime>

#include <timer.h>

DruidTimer::DruidTimer()
{
    setupUi( this );

    _lcd->setDigitCount(8);

    connect( _start, &QPushButton::clicked, this, &DruidTimer::start );
    connect( _stop, &QPushButton::clicked, this, &DruidTimer::stop );
}

void DruidTimer::start()
{
    const int hours = _hour->value();
    const int minutes = _minutes->value();
    const int msecs = ( hours * 60 * 60 + minutes * 60 ) * 1000;

    _lcd->display( DruidTimer::msecs_to_string( msecs ) );
    QTimer::singleShot( 1000, this, &DruidTimer::update );
    _timer.start( msecs );
    _timer_stop = false;
}

void DruidTimer::update()
{
    if ( ! _timer_stop )
    {
        const int msecs = _timer.remainingTime();
        _lcd->display( DruidTimer::msecs_to_string( msecs ) );

        if ( msecs/1000 > 0 )
        {
            QTimer::singleShot(1000, this, &DruidTimer::update);
        }
        else
        {
            _timer.stop();
        }
    }
}

void DruidTimer::stop()
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
