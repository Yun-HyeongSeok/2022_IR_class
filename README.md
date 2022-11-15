# 2022_IR_class

## Assignmetnt 1
Contains executable code in homework_ws.

[ROS Package, Node, Topic Project] 
1. Subscribe to more than one topic on one node. Nodes are configured as follows.
 - Anode : Publish a random value between 1 and 10 as A
 - Bnode : Publish a random value between 11 and 20 as B
 - Cnode : After subscribing to A and B, compute A+B and publish to C
 - Dnode : C subscribe cumulative average output
