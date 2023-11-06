#include <vector>
#include <string>
#include <cstdint>

int init() {
    return 0; 
}


void  uninit ();


int getVersion(const std::string &version) {
    return 0; 
}


int open(const std::vector<int32_t> &vecChannelID, std::vector<int32_t> &vecHandle) {  
    return 0; 
}


int close(const std::vector<int32_t> &vecHandle) {
    return 0; 
}


int  start(const std::vector<int32_t> &vecHandle) {
    return 0;
}


int stop(const std::vector<int32_t> &vecHandle) {
    return 0; 
}


int getCurrentSize(const std::vector<int32_t> &vecHandle, std::vector<uint64_t> &vecCurrentSize) {
    return 0; 
}


int getHandleInfo(
    const std::vector<int32_t> &vecHandle,
    std::vector<std::string> &vecFileName,
    std::vector<uint64_t> &vecCurrentSize,
    std::vector<int64_t> &vecCurrentDuration
) {
    return 0; 
}


int getState(const std::vector<int32_t> &vecHandle, std::vector<int32_t> &vecState) {
    return 0; 
}


int setOption(int32_t handle, int32_t optName, void *optVal, uint32_t optLen) {
    return 0; 
}


int getOption(int32_t handle, int32_t optName, void *optVal, uint32_t optLen) {
    return 0; 
}


const char* ezsms_get_version(){
    return 0;
}

int ezsms_get_module_alive(uint32_t u32_module_id, bool *p_b_alive){
    return 0;
}

int ezsms_get_disk_status(ezsms_disk_array_t *p_st_info){
    return 0;
}

int ezsms_get_work_para(int u32_module_id, ezsms_work_para_t *p_st_para){
    return 0;
}

int ezsms_get_other_info(int u32_module_id, std::vector<ezsms_kv_t> &v_kv){
    return 0;
}