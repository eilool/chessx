/***************************************************************************
 *   (C) 2005-2006 Marius Roets <roets.marius@gmail.com>                   *
 *   (C) 2005-2006 William Hoggarth <whoggarth@users.sourceforge.net>      *
 *   (C) 2007-2009 Michal Rudolf <mrudolf@kdewebdev.org>                   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/

#ifndef SEARCH_H_INCLUDED
#define SEARCH_H_INCLUDED

class Database;

class FilterX;

#include "filteroperator.h"
#include "gameid.h"

#include <QtCore>
#include <QPointer>

/**
 * @defgroup Search Search - different ways to lookup games
 **/

/** @ingroup Search
The Search class is a base class that represents a search on a database with one criteria.
*/
class Search : public QObject
{
    Q_OBJECT

public:
    enum Type { NullSearch, PositionSearch, EloSearch, DateSearch, TagSearch, FilterSearch, NumberSearch, DuplicateSearch, ListSearch};

    /** Standard constructor. */
    explicit Search(Database* db = nullptr);
    /** Standard destructor. */
    virtual ~Search();
    virtual void Prepare(volatile bool&) {};
    virtual int matches(GameId index) const = 0;

    void AddSearch(Search* search, FilterOperator op);

    FilterOperator searchOperator() const;
    Search *nextSearch() const;

    FilterX *getInputFilter() const;
    void setInputFilter(FilterX *value);

    FilterX *getOutputFilter() const;
    void setOutputFilter(FilterX *value);

signals:
    void prepareUpdate(int);
protected:
    QPointer<Database> m_database;
    QPointer<Search> m_nextSearch;
    QPointer<FilterX> inputFilter;
    QPointer<FilterX> outputFilter;
    FilterOperator m_searchOperator;
};

/** @ingroup Search
The NullSearch class is empty search, doing nothing. */
class NullSearch : public Search
{
    Q_OBJECT

public :
    NullSearch();
    virtual int matches(GameId index) const;
};


#endif // SEARCH_H_INCLUDED
