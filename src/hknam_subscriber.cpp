#include "ros/ros.h"
#include "hknam_tutorial/Message1.h"

void chatterCallback(const hknam_tutorial::Message1::ConstPtr& msg)
{
    ROS_INFO("receieve time = %d", msg->stamp1.sec);
    ROS_INFO("receieve msg1 = %d", msg->data1);
    ROS_INFO("receieve count = %d", msg->data3);

    ROS_INFO("receieve time = %d", msg->stamp2.sec);
    ROS_INFO("receieve msg2 = %d", msg->data2);
    ROS_INFO("receieve count = %d", msg->data4);

    ROS_INFO("msg sum = %d", (msg->data1) + (msg->data2));
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "hknam_subscriber");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("chatter", 100, chatterCallback);

    ros::spin();

    return 0;
}