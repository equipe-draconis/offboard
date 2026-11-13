#include "offboard.h"

int main(int argc, char *argv[])
{
    std::cout << "Iniciando no de controle offboard (px4_1)..." << std::endl;
    setvbuf(stdout, NULL, _IONBF, BUFSIZ);
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<OffboardControl>());

    rclcpp::shutdown();
    return 0;
}