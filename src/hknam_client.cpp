#include "ros/ros.h"
#include "hknam_tutorial/srvtutorial.h"
#include "hknam_tutorial/msgtutorial.h"
#include <cstdlib>

void chatterCallback(const hknam_tutorial::msgtutorial::ConstPtr &msg);
void timeCallback(const hknam_tutorial::msgtutorial::ConstPtr &msg);
ros::ServiceClient *clientPtr;

int main(int argc, char** argv)
{
    ros::init(argc, argv, "service_client");
    ros::NodeHandle nh;

    ros::ServiceClient ros_tutorials_service_client = nh.serviceClient<hknam_tutorial::srvtutorial>("ros_tutorial_srv");
    ros::Subscriber    ros_tutorials_subsciber      = nh.subscribe("chatter", 100, chatterCallback);
    ros::Subscriber    sub                          = nh.subscribe("timeoffset", 100, timeCallback);
    clientPtr = &ros_tutorials_service_client;

    ros::spin();

    return 0;
}

void chatterCallback(const hknam_tutorial::msgtutorial::ConstPtr &msg)
{
    int num1 = msg->data1;
    int num2 = msg->data2;
    int count = msg->data3;
    double time = msg->stamp.sec;
    int sum = num1 + num2;
    
    hknam_tutorial::srvtutorial srv;

    printf(" %d : %d + %d = %d\n", count, num1, num2, sum);
    printf("time: %f\n", time);

    srv.request.a = num1;
    srv.request.b = num2;
    srv.request.stamp1 = msg->stamp.sec;

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

void timeCallback(const hknam_tutorial::msgtutorial::ConstPtr &msg)
{
    ROS_INFO("time offset: %f\n", msg->stamp2);
}