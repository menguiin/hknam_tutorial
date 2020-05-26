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
    int num1 = 0;
    int num2 = 0;
    char ch;

    while(ros::ok())
    {
        double time = ros::Time::now().toSec();
        printf("START TIME: %f\n", time);
        
        printf("Put you message: ");
        scanf("%d", &num1);
        count1 += 1;
        msg.data1 = num1;
        msg.data3 = count1;
        msg.stamp1 = ros::Time::now();

        printf("Put you message: ");
        scanf("%d", &num2);
        count1 += 1;
        msg.stamp2 = ros::Time::now();
        msg.data2 = num2;
        msg.data4 = count1;

        if(num1 == 0 && num2 == 0)
        {
            break;
        }

        pub.publish(msg);
        loop_rate.sleep();
        
    }

    return 0;
}