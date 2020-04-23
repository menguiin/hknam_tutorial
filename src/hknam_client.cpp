#include "ros/ros.h"
#include "hknam_tutorial/srvtutorial.h"
#include "hknam_tutorial/msgtutorial.h"
#include <cstdlib>

void chatterCallback(const hknam_tutorial::msgtutorial::ConstPtr &msg);
ros::ServiceClient *clientPtr;

int main(int argc, char** argv)
{
    ros::init(argc, argv, "service_client");
    ros::NodeHandle nh;
    /* if(argc!=3)
    {
        ROS_INFO("cmd : rosrun ros_tutorials_service service_client arg0 arg1");
        ROS_INFO("arg0: double number, arg1: double number");
        return 1;
    } */

    ros::ServiceClient ros_tutorials_service_client = nh.serviceClient<hknam_tutorial::srvtutorial>("ros_tutorial_srv");
    ros::Subscriber    ros_tutorials_subsciber      = nh.subscribe("chatter", 100, chatterCallback);
    clientPtr = &ros_tutorials_service_client;

    ros::spin();

    return 0;
}

void chatterCallback(const hknam_tutorial::msgtutorial::ConstPtr &msg)
{
    int num1 = msg->data1;
    int num2 = msg->data2;
    int count = msg->data3;
    int time = msg->stamp.sec;
    int sum = num1 + num2;
    
    hknam_tutorial::srvtutorial srv;

    printf(" %d : %d + %d = %d\n", count, num1, num2, sum);
    printf("time: %d\n", time);

    srv.request.a = num1;
    srv.request.b = num2;
    srv.request.stamp1 = time;

    ros::ServiceClient ros_tutorials_service_client = (ros::ServiceClient)*clientPtr;

    if(ros_tutorials_service_client.call(srv))
    {
        ROS_INFO("send srv, srv.Request.a and b: %ld, %ld", (long int)srv.request.a, (long int)srv.request.b);
        ROS_INFO("receive srv, srv.Response.result: %ld", (long int)srv.response.result);
    }
    else 
    {
        ROS_ERROR("Failed to call service ros_tutorial_srv");
    } 
}