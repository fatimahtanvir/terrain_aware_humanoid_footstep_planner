# Terrain-Aware Humanoid Footstep Planner (ROS 2)

A real-time, sampling-based footstep planner for humanoid robots operating on
uneven terrain. Designed for research and thesis work.

## Features
- Sampling-based foothold planning
- Terrain-aware constraints
- COM / ZMP stability checks
- ROS 2 (C++)

## Build
```bash
colcon build --packages-select footstep_planner
