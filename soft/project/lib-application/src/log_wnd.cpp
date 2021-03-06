
#include "log_wnd.h"
#include "ui_log_wnd.h"

class LogWnd::PD
{
public:
    Ui_LogWnd ui;
    int linesCnt;
    QQueue<QString> l;
    QString log;
};

LogWnd::LogWnd( QWidget * parent )
: QWidget( parent )
{
    pd = new PD();
    pd->linesCnt = 128;
    pd->ui.setupUi( this );

    connect( this, SIGNAL(sigLog(const QString &)), this, SLOT(slotLog(const QString &)), Qt::QueuedConnection );
    connect( this, SIGNAL(sigLinesCnt(int)),        this, SLOT(slotLinesCnt(int)),        Qt::QueuedConnection );
    connect( this, SIGNAL(sigClear()),              this, SLOT(slotClear()),              Qt::QueuedConnection );

    connect( pd->ui.clear, SIGNAL(clicked()), this, SLOT(slotClear()), Qt::QueuedConnection );
}

LogWnd::~LogWnd()
{
    delete pd;
}

void LogWnd::log( const QString & stri )
{
    emit sigLog( stri );
}

void LogWnd::setLinesCnt( int cnt )
{
    emit sigLinesCnt( cnt );
}

void LogWnd::clear()
{
    emit sigClear();
}

void LogWnd::slotLog( const QString & stri )
{
    if ( stri.size() > 0 )
        pd->l.enqueue( stri );
    while ( pd->l.size() > pd->linesCnt )
        pd->l.dequeue();
    // ������� � ������.
    pd->log.clear();
    QQueue< QString >::iterator i;
    for ( i=pd->l.begin(); i!=pd->l.end(); i++ )
    {
        pd->log.append( *i );
        pd->log.append( "<br>" );
    }
    pd->ui.log->setHtml( pd->log );
    // �������� � ����� ������.
    //moveCursor( QTextCursor::End, QTextCursor::MoveAnchor );
    // �������� ��������� ���, ����� ������ ��� �������.
    //ensureCursorVisible();
    pd->ui.log->verticalScrollBar()->setValue( pd->ui.log->verticalScrollBar()->maximum() );

}

void LogWnd::slotLinesCnt( int cnt )
{
    pd->linesCnt = cnt;
}

void LogWnd::slotClear()
{
    pd->l.clear();
    pd->ui.log->clear();
}


