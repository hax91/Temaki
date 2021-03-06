#ifndef PROJECT_H
#define PROJECT_H

#include <QObject>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

class Project : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
public:
    explicit Project(QObject *parent = nullptr);
    void setId(const int id) {
        if (id != m_id) {
            m_id = id;
            emit idChanged();
        }
    }
    int id() const {
        return m_id;
    }

    void setName(const QString& name) {
        if (name != m_name) {
            m_name = name;
            emit nameChanged();
        }
    }
    QString name() const {
        return m_name;
    }

signals:
    void idChanged();
    void nameChanged();

private:
    int m_id = -1; // set to -1 as default (TODO: find a better way to do this)
    QString m_name;

public slots:
    QList<QVariant> getAllForUser(int userId);
    QVariant create(const QString& name, const QList<int>& memberIds, const int& currentUserId);
};

#endif // PROJECT_H
