#include "ros/ros.h"
#include "homework/testmsg.h"
#include "homework/testsrv.h"
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <math.h>

ros::Publisher pub_;

int count = 0;

bool cal(homework::testsrv::Request &req, homework::testsrv::Response &res)
{
    homework::testmsg pub_data;
    pub_data.radius.clear();
    pub_data.area.clear();
    
    pub_data.header.frame_id = "/map";

    for(int i=0; i<req.input.size(); i++)
    {
        float cir_area = req.input[i] * req.input[i] * M_PI;
        res.output.push_back(cir_area);
        ROS_INFO("Circle area : %f \n", cir_area);

        pub_data.header.seq = count;
        pub_data.header.stamp = ros::Time::now();

        pub_data.radius.push_back(req.input[i]);
        pub_data.area.push_back(res.output[i]);
    }
    pub_.publish(pub_data);
    ++count;
    ROS_INFO("custom_msg published\n");
    return true;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "server");
    ros::NodeHandle n;
    ros::ServiceServer service = n.advertiseService("testsrv", cal);

    pub_ = n.advertise<homework::testmsg>("custom_msg", 1);

    ROS_INFO("Ready to cal area!");

    ros::spin();
    return 0;
}
