#pragma once
#include "types.hpp"

class TerrainMap
{
public:
    TerrainCell getCell(double x, double y) const;
    double heightAt(double x, double y) const;
};
