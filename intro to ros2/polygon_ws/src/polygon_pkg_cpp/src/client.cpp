#include "rclcpp/rclcpp.hpp"
#include "tutorial_interfaces/srv/polygon.hpp"

class PolygonClient : public rclcpp::Node
{
public:
    PolygonClient() : Node("polygon_client")
    {
        client_ = this->create_client<tutorial_interfaces::srv::Polygon>("draw_polygon");

        while (!client_->wait_for_service(std::chrono::seconds(1))) {
            RCLCPP_INFO(this->get_logger(), "Waiting for service to be available...");
        }
    }

    void send_request(int sides)
    {
        auto request = std::make_shared<tutorial_interfaces::srv::Polygon::Request>();
        request->n = sides;
        
        auto future = client_->async_send_request(request);
        if (rclcpp::spin_until_future_complete(shared_from_this(), future) != rclcpp::FutureReturnCode::SUCCESS) {
            RCLCPP_ERROR(this->get_logger(), "Failed to call service draw_polygon");
        } else {
            RCLCPP_INFO(this->get_logger(), "Polygon drawn successfully with %d sides", sides);
        }
    }

private:
    rclcpp::Client<tutorial_interfaces::srv::Polygon>::SharedPtr client_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto polygon_client = std::make_shared<PolygonClient>();

    int num_sides;
    std::cout << "Enter the number of sides for the polygon: ";
    std::cin >> num_sides;

    polygon_client->send_request(num_sides);
    rclcpp::shutdown();
    return 0;
}
