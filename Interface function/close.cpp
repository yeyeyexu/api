#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

enum ErrorCode {
    SUCCESS = 0,
    INVALID_HANDLE,
    CLOSE_FAILURE
};

int close(const std::vector<int32_t>& vecHandle) {
    for (int32_t handle : vecHandle) {
        // 关闭通道的操作
        if (handleIsValid(handle)) {
            if (closeChannel(handle) != 0) {
                // 关闭通道失败
                return CLOSE_FAILURE;
            }
        } else {
            // 无效
            return INVALID_HANDLE;
        }
    }

    return SUCCESS;
}

bool handleIsValid(int32_t handle) {
    // 假设所有非负数都是有效的
    return handle >= 0;
}

int closeChannel(int32_t handle) {
    // 假设关闭通道总是成功的
    return 0;
}
