#include "ros/ros.h"
#include <std_msgs/String.h>
#include <std_msgs/UInt8.h>

int count = 0;
int acc_C = 0;
float avg_C = 0.0;
ros::Subscriber sub_C;

void CnodeCallback(const std_msgs::UInt8::ConstPtr &msgs_)
{
    count++;
    acc_C += msgs_->data;
    avg_C = acc_C / count;
    ROS_INFO("C node average : %f", avg_C);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "Dnode");
    ros::NodeHandle n;
    sub_C = n.subscribe("/C_node", 1000, CnodeCallback);

    ros::spin();
    return 0;
}