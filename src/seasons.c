#include "global.h"
#include "seasons.h"
#include "constants/seasons_constants.h"
#include "event_data.h"

#define SEASON_STEP_THRESHOLD 20///TODO: make this a reasonable number

static u8 nextSeason (u8 curSeason) {
	switch (curSeason) {
		case SEASON_SUMMER: return SEASON_FALL;
		case SEASON_FALL: return SEASON_WINTER;
		case SEASON_WINTER: return SEASON_SPRING;
		case SEASON_SPRING: return SEASON_SUMMER;
		default: return SEASON_SUMMER;
	}
}

bool8 UpdateSeasonStepCounter(void)
{
    u16 steps;

    steps = VarGet(VAR_SEASON_STEP_COUNTER);
    steps--;

    VarSet(VAR_SEASON_STEP_COUNTER, steps);

    DebugPrintf("Season steps: %d", steps);
    
    if (steps == 0)
    {
        u8 curSeason = VarGet(VAR_SEASON);
        VarSet(VAR_SEASON, nextSeason(curSeason));

	VarSet(VAR_SEASON_STEP_COUNTER, SEASON_STEP_THRESHOLD);/////TODO: will also need a scriopt and change the map

	DebugPrintf("Season: %d", VarGet(VAR_SEASON));
        return TRUE;
    }
	
    return FALSE;
}

//TODO: This won't work when using save file from normal firered
void ResetSeason (void) {
    VarSet(VAR_SEASON_STEP_COUNTER, SEASON_STEP_THRESHOLD);
    VarSet(VAR_SEASON, SEASON_SUMMER);

    DebugPrintf("ResetSeason");
}
