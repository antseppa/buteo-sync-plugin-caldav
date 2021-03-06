/*
 * This file is part of buteo-sync-plugin-caldav package
 *
 * Copyright (C) 2013 Jolla Ltd. and/or its subsidiary(-ies).
 *
 * Contributors: Mani Chandrasekar <maninc@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * version 2.1 as published by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
 *
 */

#ifndef PUT_H
#define PUT_H

#include "request.h"

#include <QObject>
#include <QNetworkReply>
#include <QSslError>
#include <QStringList>

#include <incidence.h>

class QNetworkAccessManager;
class Settings;

class Put : public Request
{
    Q_OBJECT

public:
    explicit Put(QNetworkAccessManager *manager, Settings *settings, QObject *parent = 0);

    void updateEvent(const QString &serverPath, KCalCore::Incidence::Ptr incidence, const QString &eTag);
    void createEvent(const QString &serverPath, KCalCore::Incidence::Ptr incidence);

    QHash<QString,QString> updatedETags() const;

private Q_SLOTS:
    void requestFinished();

private:
    QStringList mUidList;
    QHash<QString,QString> mUpdatedETags;
};

#endif // PUT_H
