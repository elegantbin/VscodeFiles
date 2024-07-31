// 一个IPV4的网络地址，通常可以划分为网络号和主机号，网络号相同的两台主机位于同一个子网。为了
// 方便快速的确定一个地址所在的子网，我们通常需要提供一个IP地址的子网掩码。用这个子网掩码与给定的IPV4地址做按位与(&) 得到的就是网络号：
// IP地址：172.18.155.33，子网掩码：255.255.0.0， 网络号：172.18.0.0
// IP地址：172.18.155.33，子网掩码：255.255.255.0，网络号：172.18.155.0
// 假定用户输入两个IPV4地址，请实现以下函数，求出子网掩码，使得两个IP地址处于同一子网中，并且该
// 子网为满足条件的最小子网（能分配的主机最少）
// std::string CalculateNetmask(const char* Ihs, const char* rhs);
// 输入描述
// 输入两个合法的IPV4地址字符串
// 输出描述
// 满足上述条件的子网掩码

#include <iostream>
#include <vector>
#include <sstream>

std::string CalculateNetmask(const char* lhs, const char* rhs) {
    std::vector<std::string> lhs_str, rhs_str;
    std::string token;
    std::istringstream lhs_ss(lhs), rhs_ss(rhs);

    while (std::getline(lhs_ss, token, '.')) {
        lhs_str.push_back(token);
    }

    while (std::getline(rhs_ss, token, '.')) {
        rhs_str.push_back(token);
    }

    unsigned int lhs_ip = 0, rhs_ip = 0;
    for (int i = 0; i < 4; ++i) {
        lhs_ip = (lhs_ip << 8) + std::stoi(lhs_str[i]);
        rhs_ip = (rhs_ip << 8) + std::stoi(rhs_str[i]);
    }

    unsigned int mask = ~((lhs_ip ^ rhs_ip) - 1);

    std::string mask_str;
    for (int i = 0; i < 4; ++i) {
        mask_str += std::to_string((mask >> (24 - 8 * i)) & 0xFF);
        if (i != 3) {
            mask_str += '.';
        }
    }

    return mask_str;
}

int main() {
    const char* ip1 = "172.18.165.33";
    const char* ip2 = "172.18.155.34";

    std::string subnet_mask = CalculateNetmask(ip1, ip2);
    std::cout << "Subnet Mask: " << subnet_mask << std::endl;

    return 0;
}