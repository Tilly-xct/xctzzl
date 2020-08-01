# xctzzl
High-Level-Synthesis-Flow-on-Zynq-using-Vivado-HLS-master
2020年新工科联盟-Xilinx暑期学校
摇摇乐项目描述
成员：2018112768  2018112873
设计概述
该项目名称为摇摇乐。该项目是基于SEA-S7开发平台去实现的，通过对板载陀螺仪产生的姿态数据进行滤波处理，然后将通过FPGA上的IIC接口将数据传输至RAM中，随后通过的QSPI接口把数据传输至ESP32，最后利用ESP32的WIFI联网功能，将数据上传至AWS IOT平台，从而实现摇摇乐。
项目功能完成SEA Board开发板自带的6轴加速度计和陀螺仪LSM6DS3TR的采集数据并换算出手摇开发板次数，并将数据传输到AWS云端服务器节点上完成数据监测，从而实现摇摇乐功能。项目主要实现了SEA-Board板载ESP32与FPGA的协同工作、SEA-Board板载FPGA读取板载陀螺仪相关数据以及使用SEA-Board板载ESP32建立与PC和AWS IOT平台的连接。
系统组成及功能说明
系统组成主要分为三部分：FPGA模块，ESP32,AWS IOT平台
功能：搭建 FPGA+ESP32+AWS IOT通信平台
1.FPGA:主要含有四个模块，IIC driver、Gyro driver、RAM、QSPI Slave.
功能：
Gyro driver模块负责解析原始陀螺仪数据，并对数据进行滤波处理。
IIC driver模块负责解析Gyro driver模块传输的数据，实现对板载陀螺仪数据的读取与发送。
RAM 模块接受并存放数据。
QSPI Slave模块读取PFGA存放在RAM中的数据，通过QSPI通信将数据输送给ESP32。
2.ESP32模块：
通过QSPI通信，读取FPGA发送的数据。并通过WIFI功能与AWS IoT构建的数据传输平台将数据上传到AWS IOT平台。
3.AWS IOT:是一款托管的云平台，使互联设备可以轻松安全地与云应用程序及其他设备交互。可以支持数十亿台设备和数万亿条消息，并且可以对这些消息进行处理并将其安全可靠地路由至AWS终端节点和其他设备。通过ESP32芯片可搭建SEA Board本地传感器与AWS IOT云的数据传输平台。
