#include "settingsmanager.h"

SettingsManager::SettingsManager(QObject *parent) : QObject(parent)
{
    m_settings << new MGConfItem("/uk/co/piggz/amazfish/profile/name", this);
    m_settings << new MGConfItem("/uk/co/piggz/amazfish/profile/dob", this);
    m_settings << new MGConfItem("/uk/co/piggz/amazfish/profile/gender", this);
    m_settings << new MGConfItem("/uk/co/piggz/amazfish/profile/weight", this);
    m_settings << new MGConfItem("/uk/co/piggz/amazfish/profile/height", this);
}

QVariant SettingsManager::value(const QString &key)
{
    Q_FOREACH(MGConfItem* item, m_settings) {
        item->sync();
        if (item->key() == key) {
            return item->value();
        }
    }
    return QVariant();
}
