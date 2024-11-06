#ifndef GUARD_SEASON_H 
#define GUARD_SEASON_H

bool8 UpdateSeasonStepCounter(void);
void ResetSeason(void);
u8 getCurSeason(void);///TODO: remove? Is this still in scope at all?
u8 getSeasonWeather(const struct MapHeader *const mapHeader);

#endif // GUARD_SEASON_H