#include "ros/ros.h"
#include "hknam_tutorial/Message1.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "hknam_publisher");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<hknam_tutorial::Message1>("chatter", 100);

    ros::Rate loop_rate(10);
    hknam_tutorial::Message1 msg;

    int count1 = 0;
    int count2 = 0;
    int num1 = 0;
    int num2 = 0;

    while(ros::ok())
    {
        printf("Put you message: ");
        scanf("%d\n", &num1);
        count1 += 2;
        msg.stamp = ros::Time::now();

        printf("Put you message: ");
        scanf("%d\n", &num2);
        count2 = count1 + 1;

        msg.stamp = ros::Time::now();
        msg.data1 = num1;
        msg.data2 = num2;
        msg.data3 = count1;
        msg.data4 = count2;

        pub.publish(msg);
        loop_rate.sleep();
        
    }

    return 0;
}