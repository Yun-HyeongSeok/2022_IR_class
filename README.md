# 2022_IR_class

## Assignmetnt 1
Contains executable code in homework_ws.

[ROS Package, Node, Topic Project] 
1. Subscribe to more than one topic on one node. Nodes are configured as follows.
 - Anode : Publish a random value between 1 and 10 as A
 - Bnode : Publish a random value between 11 and 20 as B
 - Cnode : After subscribing to A and B, compute A+B and publish to C
 - Dnode : C subscribe cumulative average output

## Assignmetnt 2
Contains executable code in homework_ws.

[ROS Message, Service, Param Project]
1. Implementation of a service that randomly generates n radii every second and calculates the area by calculating each radius. At this time, Publish the radius and width as a message.
 - Randomly generate n radii every second
 - Create srv with Int array as input and float array as output
 - Calculate the area of a circle with each value in the input array as the radius and return it to the output array
 - Publish as custom msg including header header, int array (radius), and float array (width)
 - Check the result with Rostopic echo [topic name]
