#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

// 错误码定义
enum ErrorCode {
    SUCCESS = 0,
    INVALID_HANDLE,
    INVALID_STATE,
};

// 获取当前工作状态
int getState(const std::vector<int32_t> &vecHandle, std::vector<int32_t> &vecState) {
    // 检查输入句柄列表是否为空
    if (vecHandle.empty()) {
        return INVALID_HANDLE;
    }

    // 具体实现应根据实际情况
    for (const auto &handle : vecHandle) {
        // 模拟根据句柄获取状态，实际应根据实际情况实现
        int32_t state = (handle % 2 == 0) ? 0 : 1;
        vecState.push_back(state);
    }

    return SUCCESS;
}