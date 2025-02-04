from tutorial_interfaces.srv import Polygon 

import rclpy 
from rclpy.node import Node
from geometry_msgs.msg import Twist 
from turtlesim.msg import Pose
import math 

class DrawPolygon(Node):
    def __init__(self):
        super().__init__('draw_polygon_service')
        self.get_logger().info("Polygon service has started")
        self.srv=self.create_service(Polygon, 'draw_polygon', self.callback)
        self.new_vel=Twist()
        self.cmd_vel_pub=self.create_publisher(Twist, '/turtle1/cmd_vel',10)


    def callback(self, request, response):
        n=request.n
        self.draw_polygon(n,response)

    def draw_polygon(self,n,response):
        self.vel=(2*3.14)/n

        for i in range(n):
            self.draw_line()
            self.get_clock().sleep_for(rclpy.duration.Duration(seconds=1))

            self.new_vel.linear.x=0.0
            self.cmd_vel_pub.publish(self.new_vel)

            self.rotate()
            self.get_clock().sleep_for(rclpy.duration.Duration(seconds=1.5))
            self.new_vel.angular.z=0.0
            self.cmd_vel_pub.publish(self.new_vel)

        response.success = True
        self.get_logger().info("Polygon drawing complete.")
        return response 
    
    def draw_line(self):
        self.new_vel.linear.x=3.0
        self.cmd_vel_pub.publish(self.new_vel)

    def rotate(self):
        self.new_vel.linear.x=0.0
        self.new_vel.angular.z=self.vel
        self.cmd_vel_pub.publish(self.new_vel)

def main(args=None):
    rclpy.init(args=args)
    node = DrawPolygon()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()



