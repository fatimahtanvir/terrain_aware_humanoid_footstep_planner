#pragma once

#include <vector>

enum class Foot { LEFT, RIGHT };

struct Footstep
{
    Foot foot;
    double x, y, z;
    double yaw;
};

struct TerrainCell
{
    double height;
    double slope;
    double roughness;
};

using FootstepPlan = std::vector<Footstep>;
