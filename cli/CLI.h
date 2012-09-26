#ifndef CLI_H
#define CLI_H

#include <QObject>
#include <QStringList>

#include "data/Movie.h"
#include "globals/DownloadManager.h"
#include "globals/DownloadManagerElement.h"
#include "globals/Globals.h"
#include "scrapers/TMDb.h"

class CLI : public QObject
{
    Q_OBJECT
public:
    explicit CLI(QObject *parent, QStringList arguments);

signals:
    void finished();

public slots:
    void run();

private slots:
    void onScraperSearchDone(QList<ScraperSearchResult> results);
    void onScraperLoadDone();
    void onDownloadsFinished();
    void onDownloadFinished(DownloadManagerElement elem);

private:
    QStringList m_arguments;
    QString m_file;
    QString m_scraper;
    QString m_scraperId;
    QString m_searchTerm;
    bool m_useFolderName;
    Movie *m_movie;
    TMDb *m_tmdb;
    QList<int> m_infosToLoad;
    DownloadManager *m_downloadManager;

    bool parseArguments(QStringList arguments);
    void showHelp();
};

#endif // CLI_H
