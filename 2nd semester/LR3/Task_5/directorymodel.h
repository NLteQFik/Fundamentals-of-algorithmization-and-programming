#ifndef DIRECTORYMODEL_H
#define DIRECTORYMODEL_H

#include <QFileSystemModel>

class DirectoryModel : public QFileSystemModel
{
public:
    DirectoryModel(QObject *parent = nullptr);
    QVariant data(const QModelIndex &index, int role) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
};

#endif // DIRECTORYMODEL_H
