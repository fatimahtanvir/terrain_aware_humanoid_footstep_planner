#include "footstep_planner/terrain_utils.hpp"

TerrainCell TerrainMap::getCell(double x, double y) const
{
    TerrainCell cell;
    cell.height = heightAt(x, y);
    cell.slope = 0.05;      // Placeholder
    cell.roughness = 0.1;  // Placeholder
    return cell;
}

double TerrainMap::heightAt(double x, double y) const
{
    return 0.0; // Flat terrain for now
}
