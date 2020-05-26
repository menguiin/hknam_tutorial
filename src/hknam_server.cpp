#include "ros/ros.h"
#include "hknam_tutorial/srvtutorial.h"
#include "hknam_tutorial/msgtutorial.h"

int num1 = 0;

bool calculation(hknam_tutorial::srvtutorial::Request &req, hknam_tutorial::srvtutorial::Response &res)
{

    res.result = req.a * req.b + num1;

    ROS_INFO("sending back response:%ld \n", (long int)res.result); // 결과 값 출력 및 client로 전송

    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<hknam_tutorial::msgtutorial>("timeoffset", 100);
    hknam_tutorial::msgtutorial msg;

    res.stamp2 = ros::Time::now().toSec() - req.stamp1;
    printf("time offset: %fs\n", res.stamp2); // 응답 요청이 있을 때 시간과 publisher에서 입력받을 때 시간 차이 계산해서 출력 및 Client로 전송
    msg.stamp2 = res.stamp2;

    pub.publish(msg);

    return true;
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "hknam_server");
    ros::NodeHandle nh;

    ros::ServiceServer ros_tutorials_service_server = nh.advertiseService("ros_tutorial_srv", calculation);
    ros::Publisher pub = nh.advertise<hknam_tutorial::msgtutorial>("timeoffset", 100);

    ros::Rate loop_rate(10);

    ROS_INFO("ready srv server!");
    printf("입력좀: ");
    scanf("%d", &num1);

    ros::spin();

    return 0;
}