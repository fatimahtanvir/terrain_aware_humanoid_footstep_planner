# Terrain-Aware Humanoid Footstep Planner (ROS 2) Built @ Golden Gate Innovations · ROS 2 Humble

This project implements a **sampling-based humanoid footstep planner** inspired by **Atlas-class robots**.
It is written in **C++** and structured as a **ROS 2 node**.

## Features
- Alternating left/right foot planning
- Terrain-aware foothold sampling
- Stability and kinematic feasibility checks
- Cost-based foothold selection
- Modular architecture (planner, terrain, ROS node)

## Topics
### Subscribed
- `/terrain_map` (custom grid or heightmap)
- `/robot_state` (current foot poses)

### Published
- `/footstep_plan` (sequence of footsteps)

## Build
```bash
colcon build --packages-select footstep_planner
source install/setup.bash
