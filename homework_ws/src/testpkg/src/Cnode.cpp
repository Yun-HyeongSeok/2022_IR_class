#include "ros/ros.h"
#include <std_msgs/String.h>
#include <std_msgs/UInt8.h>

int A_data = 0;
int B_data = 0;

ros::Publisher cnode_pub;
ros::Subscriber sub_A;
ros::Subscriber sub_B;

void sum_AB(int A, int B)
{
    std_msgs::UInt8 pub_num;
    int sum_AB;
    sum_AB = A_data + B_data;
    ROS_INFO("A node + B node : %d", sum_AB);
    pub_num.data = sum_AB;
    cnode_pub.publish(pub_num);
}

void AnodeCallback(const std_msgs::UInt8::ConstPtr &msgs_)
{
    A_data = msgs_->data;
    sum_AB(A_data, B_data);
}

void BnodeCallback(const std_msgs::UInt8::ConstPtr &msgs_)
{
     B_data = msgs_->data;
     sum_AB(A_data, B_data);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "Cnode");
    ros::NodeHandle n;

    sub_A = n.subscribe<std_msgs::UInt8>("/A_node", 1000, AnodeCallback);
    sub_B = n.subscribe<std_msgs::UInt8>("/B_node", 1000, BnodeCallback);
    cnode_pub = n.advertise<std_msgs::UInt8>("C_node", 1000);

    ros::spin();
    return 0;
}