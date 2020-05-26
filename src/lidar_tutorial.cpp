#include <ros/ros.h>
#include "hknam_tutorial/msgtutorial.h"
#include <sensor_msgs/LaserScan.h>


// 0.11m 에서 3.5 m 까지 인식
int num1, num2;
int count = 0;
bool distance1, distance2;
double first, second;
double first2, second2;

void laser_scan_Callback(const sensor_msgs::LaserScan::ConstPtr &scan)
{
    ros::Rate loop_rate(2); // 2Hz
    if((scan->ranges[num1] > 0.4) && (first < 0.4))
    {
        printf("첫번째 장애물이 사라졌음.\n");
    }

    if((scan->ranges[num1] < 0.4) && (first >0.4))
    {
        printf("첫번째 장애물이 나타남.\n");
    }

    if((scan->ranges[num2] > 0.4) && (second < 0.4))
    {
        printf("두번째 장애물이 사라졌음.\n");
    }

    if((scan->ranges[num2] < 0.4) && (second >0.4))
    {
        printf("두번째 장애물이 나타남.\n");
    }

    first = scan->ranges[num1];
    second = scan->ranges[num2];
    ROS_INFO("recieve msg: %f and %f", first, second);
    loop_rate.sleep();
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "lidar_tutorial");
    ros::NodeHandle nh;

    ros::Subscriber lidar_sub = nh.subscribe("/scan", 1, laser_scan_Callback);

    printf("각도 두 개 내놔.\n");
    scanf("%d %d", &num1, &num2);

    ros::spin();
    
    return 0;
}