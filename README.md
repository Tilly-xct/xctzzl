# xctzzl
# 2020年新工科联盟-Xilinx暑期学校
## 设计概述 /Design Introduction
本项目通过构建FPGA-ESP32-AWS IoT数据通信平台，目的实现对开发板板载陀螺仪产生的数据进行实时的云端监控和数据采集。
## 系统组成及功能说明 /System Construction & Function Description
系统组成主要分为三部分：FPGA模块，ESP32,AWS IOT平台</br>
功能：搭建 FPGA+ESP32+AWS IOT通信平台</br>
### （1）.FPGA:主要含有四个模块，IIC driver、Gyro driver、RAM、QSPI Slave.
Gyro driver模块负责解析原始陀螺仪数据，并对数据进行滤波处理。</br>
IIC driver模块负责解析Gyro driver模块传输的数据，实现对板载陀螺仪数据的读取与发送。</br>
RAM 模块接受并存放数据。</br>
QSPI Slave模块读取PFGA存放在RAM中的数据，通过QSPI通信将数据输送给ESP32。</br>
### （2）.ESP32模块：
通过QSPI通信，读取FPGA发送的数据。并通过WIFI功能与AWS IoT构建的数据传输平台将数据上传到AWS IOT平台。</br>
### （3）AWS IOT:
一款托管的云平台，使互联设备可以轻松安全地与云应用程序及其他设备交互。可以对消息进行处理并将其安全可靠地路由至AWS终端节点和其他设备。
通过ESP32芯片可搭建SEA Board本地传感器与AWS IOT云的数据传输平台。</br>
## 技术方向
陀螺仪数据采集模块：对温度、角速度、磁力的采集</br>
ESP32与FPGA的QSPI通信</br>
通过WIFI将数据传输到AWS云端</br>
MQTT订阅观测数据</br>
