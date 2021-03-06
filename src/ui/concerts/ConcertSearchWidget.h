#pragma once

#include "data/TmdbId.h"
#include "globals/Globals.h"
#include "globals/ScraperInfos.h"
#include "globals/ScraperResult.h"

#include <QTableWidgetItem>
#include <QWidget>

namespace Ui {
class ConcertSearchWidget;
}

namespace mediaelch {
namespace scraper {
class ConcertSearchJob;
}
} // namespace mediaelch

class ConcertSearchWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ConcertSearchWidget(QWidget* parent = nullptr);
    ~ConcertSearchWidget() override;

public slots:
    void search(QString searchString);
    int scraperNo() const;
    TmdbId scraperId();
    QSet<ConcertScraperInfo> infosToLoad();

signals:
    void sigResultClicked();

private slots:
    void searchByComboIndex(int comboScraperIndex);
    void showResults(mediaelch::scraper::ConcertSearchJob* searchJob);
    void resultClicked(QTableWidgetItem* item);
    void chkToggled();
    void chkAllToggled(bool toggled);

private:
    Ui::ConcertSearchWidget* ui;
    int m_scraperNo = 0;
    TmdbId m_scraperId;
    QSet<ConcertScraperInfo> m_infosToLoad;

    void clear();
    void setCheckBoxesEnabled(QSet<ConcertScraperInfo> scraperSupports);
};
