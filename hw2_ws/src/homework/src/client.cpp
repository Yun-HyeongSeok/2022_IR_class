#include "ros/ros.h"
#include "homework/testmsg.h"
#include "homework/testsrv.h"
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <math.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "client");
    ros::NodeHandle n;

    int input_num = 0;

    ros::ServiceClient client = n.serviceClient<homework::testsrv>("testsrv");
    homework::testsrv srv;

    ros::Rate loop_rate(1);

    while(ros::ok())
    {
        input_num = (rand() % 10 + 1);

        for(int i=0; i<input_num; i++)
        {
            int radius = rand() % 20 + 1;
            srv.request.input.push_back(radius);
            ROS_INFO("Input : %d \n", (int)srv.request.input[i]);
        }

        if(client.call(srv))
        {
            ROS_INFO("Input data send!!\n");
        }
        else
        {
            std::cout << "Error : failed to call service" << std::endl;
        }
        srv.request.input.clear();
        loop_rate.sleep();
    }

    return 0;
}
