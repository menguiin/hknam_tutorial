#!/usr/bin/env python

from hknam_tutorial.srv import AddTwoInts,AddTwoIntsResponse
import rospy

def handle_add_two_ints(req):
    print "Returning [%s + %s = %s]" % (req.a, req.b, (req.a + req.b))
    return AddTwoIntsResponse(req.a + req.b)

def