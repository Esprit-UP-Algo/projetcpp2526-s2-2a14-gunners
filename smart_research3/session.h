#ifndef SESSION_H
#define SESSION_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QMap>
#include <QColor>

class ColorSqlQueryModel : public QSqlQueryModel {
public:
    using QSqlQueryModel::QSqlQueryModel;

    QVariant data(const QModelIndex &item, int role = Qt::DisplayRole) const override {
        if (role == Qt::BackgroundRole && colors.contains(item))
            return colors.value(item);
        return QSqlQueryModel::data(item, role);
    }

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override {
        if (role == Qt::BackgroundRole) {
            colors[index] = value.value<QColor>();
            emit dataChanged(index, index, {Qt::BackgroundRole});
            return true;
        }
        return QSqlQueryModel::setData(index, value, role);
    }

private:
    QMap<QModelIndex, QColor> colors;
};

class Session
{
    int id_session;
    QString titre_session, lieu_session, type_session, listes_publication_session, listes_reviewers_session;
    QDate date_session;

public:
    Session();
    Session(int, QString, QDate, QString, QString, QString, QString);

    // Getters
    int get_id_session();
    QString get_titre_session();
    QDate get_date_session();
    QString get_lieu_session();
    QString get_type_session();
    QString get_listes_publication_session();
    QString get_listes_reviewers_session();

    // Setters
    void set_id_session(int);
    void set_titre_session(QString);
    void set_date_session(QDate);
    void set_lieu_session(QString);
    void set_type_session(QString);
    void set_listes_publication_session(QString);
    void set_listes_reviewers_session(QString);

    // CRUD
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int);
    static bool verifierId(int);
    static QMap<QString, int> getStatistics();

    // Search and Sort
    QSqlQueryModel * rechercherSession(QString);
    QSqlQueryModel * trierSessionASC();
    QSqlQueryModel * trierSessionDESC();
};

#endif // SESSION_H
