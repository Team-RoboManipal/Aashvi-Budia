import rclpy
from rclpy.node import Node
from tutorial_interfaces.srv import Polygon

class PolygonClient(Node):
    def __init__(self):
        super().__init__('polygon_client')
        self.client = self.create_client(Polygon, 'draw_polygon')

        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Waiting for service to be available')

        self.request = Polygon.Request()

    def send_request(self, sides):
        self.request.n = sides  # Fixed typo here
        future = self.client.call_async(self.request)
        rclpy.spin_until_future_complete(self, future)
        return future.result()

def main(args=None):  # Fixed function name
    rclpy.init(args=args)
    polygon_client = PolygonClient()

    num_sides = int(input("Enter the number of sides for the polygon: "))

    response = polygon_client.send_request(num_sides)

    if response.success:
        polygon_client.get_logger().info(f"Successfully drew a polygon with {num_sides} sides.")
    else:
        polygon_client.get_logger().info("Failed to draw the polygon.")

    polygon_client.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
