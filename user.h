#ifndef USER_H
#define USER_H

#include <QObject>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QQmlEngine>

class User : public QObject
{
    Q_OBJECT
    Q_ENUMS(UserRole)
    Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString username READ username WRITE setUsername NOTIFY usernameChanged)
    Q_PROPERTY(int role_id READ role_id WRITE setRoleId NOTIFY roleIdChanged)
    Q_PROPERTY(QList<QVariant> project_members READ project_members WRITE setProjectMembers NOTIFY projectMembersChanged)
public:
    explicit User(QObject *parent = nullptr);
    enum UserRole {
      Editor = 1,
      Viewer = 2
    };
    Q_ENUM(UserRole)

    static void declareQML() {
        qmlRegisterType<User>("MyQMLEnums", 13, 37, "User");
    }
    void setId(const int id) {
        if (id != m_id) {
            m_id = id;
            emit idChanged();
        }
    }
    int id() const {
        return m_id;
    }

    void setUsername(const QString& username) {
        if (username != m_username) {
            m_username = username;
            emit usernameChanged();
        }
    }
    QString username() const {
        return m_username;
    }

    void setRoleId(const int role_id) {
        if (role_id != m_role_id) {
            m_role_id = role_id;
            emit roleIdChanged();
        }
    }
    int role_id() const {
        return m_role_id;
    }
    QList<QVariant> project_members() const {
        return m_project_members;
    }
    void setProjectMembers(const QList<QVariant> project_members) {
        if (project_members != m_project_members) {
            m_project_members = project_members;
            emit projectMembersChanged();
        }
    }

signals:
    void idChanged();
    void usernameChanged();
    void roleIdChanged();
    void projectMembersChanged();

private:
    int m_id;
    QString m_username;
    int m_role_id;
    QList<QVariant> m_project_members;

public slots:
    QVariant login(const QString& username, const QString& password);
    QVariant signUp(const QString& username, const QString& email, const QString& password, const int& roleId);
    QList<QVariant> search(const QString& entry, const QStringList& ignoreUserIds = QStringList()); /* search users by username/email and return User list */
    QList<QVariant> getProjectMembers(int projectId); /* get all users (project members) from project_id */
    bool removeProjectMember(int projectId, int userId);
    bool addProjectMembers(int projectId, const QStringList& userIds);
    QString getUsernameById(int id);
    int usernameExists(const QString& username);
};

#endif // USER_H
