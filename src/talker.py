#!/usr/bin/env python

import rospy
from std_msgs.msg import String
from hknam_tutorial.msg import Message1

def talker():
    pub = rospy.Publisher('chatter', Message1, queue_size=10)
    rospy.init_node('talker', anonymous=True)
    rate = rospy.Rate(10)
    
    msg = Message1()
    num1 = 0
    num2 = 0
    count = 0
    while not rospy.is_shutdown():
        time = rospy.get_time()
        print("START TIME", time)
        num1 = input('Put your message: ')
        msg.data1 = num1
        count += 1
        msg.data3 = count
        msg.stamp1 = rospy.get_rostime()

        num2 = input('Put your message: ')
        msg.data2 = num2
        count += 1
        msg.data4 = count
        msg.stamp2 = rospy.get_rostime()

        pub.publish(msg)
        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass