#include <ros/ros.h>
#include <thread>
#include <vector>
#include "udp_listen_socket.h"
#include "std_msgs/String.h"
#include <sstream>

class RunClass{
public:
    RunClass() {
        sock_1.Initialization(6501, "192.168.100.28");
        sock_2.Initialization(6502, "192.168.100.28");
        pub_ = n_.advertise<std_msgs::String>("chatter", 1000);
    };
    ~RunClass() {};

    void run(char * str){
        std_msgs::String msg;
        std::stringstream ss;
        ss << str;
        msg.data = ss.str();   
        pub_.publish(msg);     
    }

public:
    CudpListenSocket sock_1;    
    CudpListenSocket sock_2;
    ros::NodeHandle n_;
    ros::Publisher pub_;
    ros::Subscriber sub_;
};


int main(int argc, char* argv[]) {
    ros::init(argc, argv, "hauv_udp_comm_node");
    ros::NodeHandle nh;

    RunClass rc;
    
    std::thread t1([&](){
                            while(1){
                                int recv = rc.sock_1.receive();
                                ROS_INFO("%s\n", rc.sock_1.buf);
                                rc.run(rc.sock_1.buf);
                            }
                        });

    std::thread t2([&](){
                            while(1){
                                int recv = rc.sock_2.receive();
                                ROS_INFO("%s\n", rc.sock_2.buf);
                                rc.run(rc.sock_2.buf);
                            }
                        });

    ROS_INFO("Thread Runnin");
    ros::spin();
}

