#ifndef TRANSLATORMANAGER_H
#define TRANSLATORMANAGER_H

#include <QMap>
#include <QMutex>
#include <QObject>
#include <QString>
#include <QTranslator>

class QTranslator;

typedef QMap<QString, QTranslator*> TranslatorMap;

class TranslatorManager
{
public:
    static TranslatorManager* instance();
    ~TranslatorManager();

     void switchTranslator(QTranslator& translator, const QString& filename);
     inline QString getCurrentLang()  { return m_keyLang; }

private:
    TranslatorManager();

    // Hide copy constructor and assignment operator.
    TranslatorManager(const TranslatorManager &);
    TranslatorManager& operator=(const TranslatorManager &);

    // Class instance.
    static TranslatorManager* m_Instance;

    TranslatorMap   m_translators;
    QString         m_keyLang;
    QString         m_langPath;
};

#endif // TRANSLATORMANAGER_H
