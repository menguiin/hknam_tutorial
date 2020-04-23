#include "ros/ros.h"
#include "ros_tutorials_service/srvtutorial.h"

bool calculation(ros_tutorials_service::srvtutorial::Request &req, ros_tutorials_service::srvtutorial::Response &res)
{
    int num1 = 0;
    int num2 = 0;

    //scanf로 값을 입력받음
    printf("입력좀: ");
    scanf("%d %d", &num1, &num2);
    res.result = req.a * req.b + num1 + num2;
    double stamp2 = ros::Time::now().toSec();

    ROS_INFO("sending back response:%ld \n", (long int)res.result); // 결과 값 출력 및 client로 전송
    ROS_INFO("time offset: %ld\n", (long int)stamp2 - (long int)req.stamp1); // 응답 요청이 있을 때 시간과 publisher에서 입력받을 때 시간 차이 계산해서 출력 및 Client로 전송

    return true;
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "hknam_server");
    ros::NodeHandle nh;

    ros::ServiceServer ros_tutorials_service_server = nh.advertiseService("ros_tutorial_srv", calculation);

    ROS_INFO("ready srv server!");

    ros::spin();

    return 0;
}