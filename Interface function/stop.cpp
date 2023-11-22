#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


// 停止流程的函数
int stop(const std::vector<uint32_t>& vecHandle) {
    for (uint32_t handle : vecHandle) {
        std::cout << "Stopping process for handle: " << handle << std::endl;
        // 添加停止通道或流程的逻辑
        // ...
    }

    return 0; // 停止成功
}

