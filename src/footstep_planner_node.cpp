#include "rclcpp/rclcpp.hpp"
#include "footstep_planner/planner.hpp"

class FootstepPlannerNode : public rclcpp::Node
{
public:
    FootstepPlannerNode() : Node("footstep_planner_node")
    {
        RCLCPP_INFO(get_logger(), "Footstep Planner Node Started");
    }

private:
    FootstepPlanner planner_;
};

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<FootstepPlannerNode>());
    rclcpp::shutdown();
    return 0;
}
