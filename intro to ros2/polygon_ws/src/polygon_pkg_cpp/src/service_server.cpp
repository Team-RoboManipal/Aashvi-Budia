#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "tutorial_interfaces/srv/polygon.hpp"
#include "turtlesim/msg/pose.hpp"
#include <cmath>

class DrawPolygon : public rclcpp::Node
{
public:
    DrawPolygon() : Node("draw_polygon_service")
    {
        srv_ = this->create_service<tutorial_interfaces::srv::Polygon>("draw_polygon", std::bind(&DrawPolygon::callback, this, std::placeholders::_1, std::placeholders::_2));
        cmd_vel_pub_ = this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);
    }

private:
    void callback(const std::shared_ptr<tutorial_interfaces::srv::Polygon::Request> request, std::shared_ptr<tutorial_interfaces::srv::Polygon::Response> response)
    {
        int n = request->n;
        RCLCPP_INFO(this->get_logger(), "Received request to draw a polygon with %d sides", n);
        draw_polygon(n);
        response->success = true;
    }

    void draw_polygon(int n)
    {
        double vel = (2 * M_PI) / n;  // Correct angular velocity for rotation
        geometry_msgs::msg::Twist new_vel;

        for (int i = 0; i < n; ++i) {
            draw_line(new_vel);
            cmd_vel_pub_->publish(new_vel);
            rclcpp::sleep_for(std::chrono::seconds(1));  // Sleep for 1 second while moving forward
            new_vel.linear.x = 0.0;  // Stop forward movement
            cmd_vel_pub_->publish(new_vel);
            rotate(new_vel, vel);  // Rotate the turtle
            rclcpp::sleep_for(std::chrono::seconds(2));  // Sleep for 2 seconds to allow for the rotation
            new_vel.angular.z = 0.0;  // Stop rotation
            cmd_vel_pub_->publish(new_vel);
        }
    }

    void draw_line(geometry_msgs::msg::Twist &new_vel)
    {
        new_vel.linear.x = 2.0;  // Forward speed
    }

    void rotate(geometry_msgs::msg::Twist &new_vel, double vel)
    {
        new_vel.linear.x = 0.0;  // Stop moving forward
        new_vel.angular.z = vel;  // Set the angular speed for rotation
        cmd_vel_pub_->publish(new_vel);
    }

    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub_;
    rclcpp::Service<tutorial_interfaces::srv::Polygon>::SharedPtr srv_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<DrawPolygon>());
    rclcpp::shutdown();
    return 0;
}
