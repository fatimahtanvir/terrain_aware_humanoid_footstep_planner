#pragma once

#include "types.hpp"
#include "terrain_utils.hpp"

class FootstepPlanner
{
public:
    FootstepPlan plan(
        const Footstep& left,
        const Footstep& right,
        const TerrainMap& terrain,
        const Footstep& goal
    );

private:
    std::vector<Footstep> sampleFootholds(
        const Footstep& stance,
        const TerrainMap& terrain
    );

    bool isValidFoothold(
        const Footstep& candidate,
        const Footstep& stance,
        const TerrainMap& terrain
    );

    double computeCost(
        const Footstep& candidate,
        const Footstep& goal,
        const TerrainMap& terrain
    );

    Footstep selectBest(
        const std::vector<Footstep>& candidates,
        const Footstep& goal,
        const TerrainMap& terrain
    );
};
