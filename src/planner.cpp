#include "footstep_planner/planner.hpp"
#include <cmath>
#include <limits>

static constexpr double MAX_STEP = 0.6;
static constexpr double MAX_SLOPE = 0.3;
static constexpr double MAX_ROUGHNESS = 0.4;

FootstepPlan FootstepPlanner::plan(
    const Footstep& left,
    const Footstep& right,
    const TerrainMap& terrain,
    const Footstep& goal)
{
    FootstepPlan plan;
    Footstep stance = left;
    Foot current = Foot::LEFT;

    while (std::hypot(stance.x - goal.x, stance.y - goal.y) > 0.2)
    {
        auto samples = sampleFootholds(stance, terrain);

        std::vector<Footstep> valid;
        for (auto& s : samples)
            if (isValidFoothold(s, stance, terrain))
                valid.push_back(s);

        if (valid.empty())
            break;

        Footstep best = selectBest(valid, goal, terrain);
        plan.push_back(best);

        stance = best;
        current = (current == Foot::LEFT) ? Foot::RIGHT : Foot::LEFT;
    }

    return plan;
}

std::vector<Footstep> FootstepPlanner::sampleFootholds(
    const Footstep& stance,
    const TerrainMap& terrain)
{
    std::vector<Footstep> samples;

    for (double dx = 0.2; dx <= MAX_STEP; dx += 0.1)
    {
        for (double dy = -0.3; dy <= 0.3; dy += 0.1)
        {
            Footstep c;
            c.x = stance.x + dx;
            c.y = stance.y + dy;
            c.z = terrain.heightAt(c.x, c.y);
            c.yaw = stance.yaw;
            c.foot = stance.foot;
            samples.push_back(c);
        }
    }
    return samples;
}

bool FootstepPlanner::isValidFoothold(
    const Footstep& c,
    const Footstep& stance,
    const TerrainMap& terrain)
{
    auto cell = terrain.getCell(c.x, c.y);

    if (cell.slope > MAX_SLOPE) return false;
    if (cell.roughness > MAX_ROUGHNESS) return false;
    if (std::hypot(c.x - stance.x, c.y - stance.y) > MAX_STEP) return false;

    return true;
}

double FootstepPlanner::computeCost(
    const Footstep& c,
    const Footstep& goal,
    const TerrainMap& terrain)
{
    auto cell = terrain.getCell(c.x, c.y);

    return
        1.0 * std::hypot(c.x - goal.x, c.y - goal.y) +
        0.5 * cell.roughness +
        0.3 * std::hypot(c.x, c.y) +
        0.2 * std::abs(c.yaw - goal.yaw);
}

Footstep FootstepPlanner::selectBest(
    const std::vector<Footstep>& candidates,
    const Footstep& goal,
    const TerrainMap& terrain)
{
    double best_cost = std::numeric_limits<double>::infinity();
    Footstep best;

    for (auto& c : candidates)
    {
        double cost = computeCost(c, goal, terrain);
        if (cost < best_cost)
        {
            best_cost = cost;
            best = c;
        }
    }
    return best;
}
