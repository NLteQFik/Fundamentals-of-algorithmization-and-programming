#include "directorymodel.h"

DirectoryModel::DirectoryModel(QObject *parent) : QFileSystemModel(parent) {}

QVariant DirectoryModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {

        if(index.column() != 0) return "   ";
        QString path = QDir::toNativeSeparators(filePath(index));
        QFileInfo fileInfo(path);
        return fileInfo.fileName();
    }
    return QVariant();
}

int DirectoryModel::columnCount(const QModelIndex &parent) const {
    return 1;
}
