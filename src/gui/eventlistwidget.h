/****************************************************************************
*   Copyright (C) 2012 by Jens Nissen jens-chessx@gmx.net                   *
****************************************************************************/

#ifndef EVENTLISTWIDGET_H
#define EVENTLISTWIDGET_H

#include <QWidget>
#include <QStringListModel>

#include "eventinfo.h"

class DatabaseInfo;

namespace Ui
{
class TagDetailWidget;
}

class EventListWidget : public QWidget
{
    Q_OBJECT

public:
    explicit EventListWidget(QWidget *parent = nullptr);
    ~EventListWidget();

signals:
    void filterRequest(QString ts);
    void renameRequest(QString ts);
    void filterEventPlayerRequest(QString player, QString event);

public slots:
    void selectEvent(const QString& player);
    void setDatabase(DatabaseInfo* dbInfo);
    void slotSelectEvent(const QString &event);

protected slots:
    void findEvent(const QString& s);
    void filterSelectedEvent();
    void filterSelectedEventAdd();
    void renameSelectedEvent();
    void slotReconfigure();
    void selectionChangedSlot();
    void slotLinkClicked(const QUrl& url);
    void eventSelected(const QString& player);

private:
    EventInfo m_event;
    QStringList m_list;
    Ui::TagDetailWidget *ui;
    QStringListModel* m_filterModel;
};


#endif // EVENTLISTWIDGET_H
