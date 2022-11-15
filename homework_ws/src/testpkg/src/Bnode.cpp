#include "ros/ros.h"
#include <std_msgs/String.h>
#include <std_msgs/UInt8.h>

ros::Publisher bnode_pub;

int main(int argc, char **argv)
{
    int rand_num;
    ros::init(argc, argv, "Bnode");
    ros::NodeHandle n;
    bnode_pub = n.advertise<std_msgs::UInt8>("B_node", 1000);

    std_msgs::UInt8 pub_num;
    ros::Rate publish_rate(20);

    while(ros::ok)
    {
        rand_num = rand() % 10 + 11;
        ROS_INFO("B node : %d", rand_num);
        pub_num.data = rand_num;
        bnode_pub.publish(pub_num);
        publish_rate.sleep();
    }

    ros::spin();    
    return 0;
}