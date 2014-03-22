#pragma once

#include <QObject>
#include <QByteArray>
#include <QDateTime>
#include "peer_id.h"

// For now, store a file per chat ID.
class ChatHistory : public QObject
{
    Q_OBJECT

    class Private;
    std::shared_ptr<Private> m_pimpl;

public:
    /**
     * @param id binary chat identifier.
     */
    ChatHistory(ssu::peer_id const& id, QObject* parent = 0);
    ~ChatHistory();

public slots:
    void insertHistoryLine(const QString& originator, const QDateTime timestamp, const QString& message);

private slots:
    void newHistorySynced();
};
