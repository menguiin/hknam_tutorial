#!/usr/bin/env python
import rospy
from std_msgs.msg import String
from hknam_tutorial.msg import Message1

def callback(msg):
    rospy.loginfo("receieve time = %d" % msg.stamp1.to_sec())
    rospy.loginfo("receieve msg1 = %d" % msg.data1)
    rospy.loginfo("receieve count = %d" % msg.data3)

    rospy.loginfo("receieve time = %d" % msg.stamp1.to_sec())
    rospy.loginfo("receieve msg2 = %d" % msg.data2)
    rospy.loginfo("receieve count = %d" % msg.data4)

    rospy.loginfo("msg sum = %d" % msg.data1 + msg.data2)
    
def listener():
    rospy.init_node('listener', anonymous=True)

    rospy.Subscriber("chatter", Message1, callback)

    rospy.spin()

if __name__ == '__main__':
    listener()