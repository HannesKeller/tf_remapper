TF Remapper
======================

Overview
---------------

This [ROS] package contains a simple node to republish [tf2_msgs/TFMessage] as [geometry_msgs/PoseWithCovarianceStamped.]

**Author: Hannes Keller, kellerh@student.ethz.ch<br />
Affiliation: Autonomous Systems Lab, ETH Zurich**

Installation
------------

### Dependencies

This software is built on the Robotic Operating System ([ROS]), which needs to be [installed](http://wiki.ros.org) first.
 

### Building

In order to install the TF remapper, clone the latest version from this repository into your rosbuild workspace and compile the package using ROS.

    cd rosbuild_workspace
    git clone https://github.com/HannesKeller/tf_remapper.git
    rosmake tf_remapper


Basic Usage
------------
Simply start the node, or add a launch file to remap topics.


Nodes
------------

### Node: tf_remapper

This is the only node present in the package. It republishes its [tf2_msgs/TFMessage] input topic in the form of a [geometry_msgs/PoseWithCovarianceStamped].

#### Subscribed Topics

* **`/tf`** ([tf2_msgs/TFMessage])

    The tf input message.

#### Published Topics

* **`/robot_pose`** ([geometry_msgs/PoseWithCovarianceStamped])

    The output message.

[ROS]: http://www.ros.org
[tf2_msgs/TFMessage]: http://docs.ros.org/api/tf2_msgs/html/msg/TFMessage.html
[geometry_msgs/PoseWithCovarianceStamped]: http://docs.ros.org/api/geometry_msgs/html/msg/PoseWithCovarianceStamped.html


