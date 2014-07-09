/*
 * tfRemapper.cpp
 *
 *  Created on: Jul 3, 2014
 *      Author: Hannes Keller
 */

#include <ros/ros.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <tf2_msgs/TFMessage.h>

class TfRemapper
{
 public:
  TfRemapper(ros::NodeHandle nh);
  ~TfRemapper() {}

 private:
  void tfCallback(const tf2_msgs::TFMessage::ConstPtr& msg);

  ros::NodeHandle nh_;
  ros::Subscriber tfSub_;
  ros::Publisher posePub_;
};

TfRemapper::TfRemapper(ros::NodeHandle nh): nh_(nh)
{
  tfSub_ = nh_.subscribe("/tf", 1000, &TfRemapper::tfCallback, this);
  posePub_ = nh_.advertise<geometry_msgs::PoseWithCovarianceStamped>("/robot_pose", 1000);
}

void TfRemapper::tfCallback(const tf2_msgs::TFMessage::ConstPtr& msg)
{
  geometry_msgs::PoseWithCovarianceStamped poseMsg;
  poseMsg.header.stamp = msg->transforms[0].header.stamp;
  poseMsg.pose.pose.position.x = msg->transforms[0].transform.translation.x;
  poseMsg.pose.pose.position.y = msg->transforms[0].transform.translation.y;
  poseMsg.pose.pose.position.z = msg->transforms[0].transform.translation.z;
  poseMsg.pose.pose.orientation = msg->transforms[0].transform.rotation;
  for(int i = 0; i < 36; i++)
    poseMsg.pose.covariance[i] = 0;

  posePub_.publish(poseMsg);
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "tf_remapper");

  ros::NodeHandle nh;

  TfRemapper tfRemapper(nh);

  ros::spin();

  return 0;
}


