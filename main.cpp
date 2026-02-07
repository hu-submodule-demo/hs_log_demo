/**
 * @file      main.cpp
 * @brief     程序入口文件
 * @author    huenrong (sgyhy1028@outlook.com)
 * @date      2026-02-07 16:23:12
 *
 * @copyright Copyright (c) 2026 huenrong
 *
 */

#include <iostream>

#include "hs_log.hpp"

void on_log_full(void)
{
    HS_LOG_BASIC_INFO("xxxxxxxxxxxxxxxxxx log file is full!");
}

void on_log_output(const std::string &log_time, const std::string &log_level, const std::string &log_file,
                   const int &log_line, const std::string &log_func, const std::string &log_content,
                   const std::string &log_formatted)
{
    HS_LOG_BASIC_INFO("xxxxxxxxxxxxxxxxxx log_time: {}", log_time);
    HS_LOG_BASIC_INFO("xxxxxxxxxxxxxxxxxx log_level: {}", log_level);
    HS_LOG_BASIC_INFO("xxxxxxxxxxxxxxxxxx log_file: {}", log_file);
    HS_LOG_BASIC_INFO("xxxxxxxxxxxxxxxxxx log_line: {}", log_line);
    HS_LOG_BASIC_INFO("xxxxxxxxxxxxxxxxxx log_func: {}", log_func);
    HS_LOG_BASIC_INFO("xxxxxxxxxxxxxxxxxx log_content: {}", log_content);
    HS_LOG_BASIC_INFO("xxxxxxxxxxxxxxxxxx log_formatted: {}", log_formatted);
}

/**
 * @brief 程序入口
 *
 * @param[in] argc: 参数个数
 * @param[in] argv: 参数列表
 *
 * @return 成功: 0
 * @return 失败: 其它
 */
int main(int argc, char *argv[])
{
    hs_log::init("./output/log/demo.log", (50 * 1024), 4, on_log_full, on_log_output);

    while (true)
    {
        HS_LOG_BASIC_DEBUG("this is basic debug");
        HS_LOG_BASIC_INFO("this is basic info");
        HS_LOG_BASIC_WARN("this is basic warn");
        HS_LOG_BASIC_ERROR("this is basic error");

        HS_LOG_FULL_DEBUG("this is full debug");
        HS_LOG_FULL_INFO("this is full info");
        HS_LOG_FULL_WARN("this is full warn");
        HS_LOG_FULL_ERROR("this is full error");

        sleep(1);
    }

    return 0;
}
