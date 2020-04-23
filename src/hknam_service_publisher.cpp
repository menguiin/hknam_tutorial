#include "ros/ros.h"
#include "ros_tutorials_service/msgtutorial.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "service_publisher");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<ros_tutorials_service::msgtutorial>("chatter", 100);

    ros::Rate loop_rate(10);
    ros_tutorials_service::msgtutorial msg;
    

    int count1 = 0;
    int num1 = 0;
    int num2 = 0;

    while(ros::ok())
    {
        printf("Put you message: ");
        scanf("%d\n", &num1);
        msg.stamp = ros::Time::now();

        printf("Put you message: ");
        scanf("%d\n", &num2);

        count1 += 1;

        msg.stamp = ros::Time::now();
        msg.data1 = num1;
        msg.data2 = num2;
        msg.data3 = count1;

        pub.publish(msg);
        loop_rate.sleep();
        
    }

    return 0;
}