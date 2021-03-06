#pragma once

#include "scrapers/tv_show/EpisodeScrapeJob.h"

#include "scrapers/tv_show/imdb/ImdbTvApi.h"

namespace mediaelch {
namespace scraper {

class ImdbTvEpisodeScrapeJob : public EpisodeScrapeJob
{
    Q_OBJECT

public:
    ImdbTvEpisodeScrapeJob(ImdbTvApi& api, Config _config, QObject* parent = nullptr);
    ~ImdbTvEpisodeScrapeJob() = default;
    void execute() override;

private:
    void loadSeason();
    void loadEpisode(const ImdbId& episodeId);

private:
    ImdbTvApi& m_api;
};

} // namespace scraper
} // namespace mediaelch
