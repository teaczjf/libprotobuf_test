#include <stdio.h>

#include <iostream>
#include "my_easylogging.h"

#include "datastruct.pb.h"

#include <google/protobuf/util/json_util.h>
#include <google/protobuf/timestamp.pb.h>

using google::protobuf::util::JsonStringToMessage;
// #define HDDD
using namespace std;

// struct student
// {
//     string name;
//     int age;
//     string ID;
//     float money;
// };

#if 0
void FUNC1(student st_info)
{
    LOG(INFO) << "学生姓名" << st_info.name;
    std::cout << "学生姓名" << st_info.name << std::endl;
}
#endif

void test(HT_JD *pdata, int message_len)
{
    char cmd_buffer[message_len];
    memset(cmd_buffer, 0, message_len);
    pdata->SerializeToArray(cmd_buffer, message_len); //压缩
    cout << "11111111111111111压缩后的数组  size =" << message_len << " buff = " << endl;
    LogInfoDump("buff = ", cmd_buffer, message_len);
}

int main()
{

    google::protobuf::util::JsonPrintOptions options;
    if (0)
    {
        options.add_whitespace = true;
        options.always_print_primitive_fields = true;
        options.preserve_proto_field_names = true;
    }
    else
    {
        options.add_whitespace = false;
        options.always_print_primitive_fields = false;
        options.preserve_proto_field_names = false;
    }

    easylogginginit(); //日志初始化
    // log_test();        //日志自测函数   里面可以看细节的用法

    printf("Hello world\n\r");
    // test1();
    // test2();

    HT_JD ph_jd;
    ph_jd.set_wx_name("ping_hu");
    for (int i = 0; i < 5; i++)
    {
        wx_info *wx_info = ph_jd.add_infos();
        wx_info->set_age(1);
        wx_info->set_id("123456");
    }
#if 1 // JSON格式打印收到的数据
    string json_string;
    MessageToJsonString(ph_jd, &json_string, options);
    LOG(INFO) << "size = " << json_string.size() << " JSON \n"
              << json_string;
#endif
    int message_len = ph_jd.ByteSizeLong();
    char cmd_buffer[message_len];

    memset(cmd_buffer, 0, message_len);
    ph_jd.SerializeToArray(cmd_buffer, message_len); //压缩
    cout << "压缩后的数组  size =" << message_len << " buff = \n "
         << cmd_buffer << endl;

    test(&ph_jd, message_len);
    LOG(INFO)
        << "========= 经过网络传输后 =======================";
    HT_JD xxxx_jd;

    xxxx_jd.ParseFromArray(cmd_buffer, message_len);

    LOG(INFO) << "NAME = " << xxxx_jd.wx_name();

    int wx_num = xxxx_jd.infos_size(); //获取长度
    LOG(INFO) << "现在我们有 " << wx_num << " 颗卫星";
    for (int i = 0; i < wx_num; i++)
    {
        wx_info wx_info = xxxx_jd.infos(i); //获取repeated
        LOG(INFO) << i << " " << wx_info.age() << " " << wx_info.id() << " " << wx_info.money();
    }
    return 0;
}
#if 0
    student stu_info;
    stu_info.set_name("zhoujian");
    stu_info.set_age(18);
    stu_info.set_money(2.333);
    LOG(INFO) << stu_info.name() << " " << stu_info.age() << " " << stu_info.money();

    // stu_info.clear_name();
    // LOG(INFO) << "clear名字" << stu_info.name()
    //           << " " << stu_info.age() << "  " << stu_info.money();

#if 1 // JSON格式打印收到的数据
    string json_string;
    MessageToJsonString(stu_info, &json_string, options);
    LOG(INFO) << "size = " << json_string.size() << " JSON \n"
              << json_string;
#endif
    // 发布  json_string
    int message_len = stu_info.ByteSizeLong();
    char cmd_buffer[message_len];
    memset(cmd_buffer, 0, message_len);
    stu_info.SerializeToArray(cmd_buffer, message_len); //压缩
    cout << "压缩后的数组  size =" << message_len << " \n"
         << cmd_buffer << endl;

    LOG(INFO) << "经过网络传输后 =======================";
    // cmd_buffer
    student stu_info_1;

    stu_info_1.ParseFromArray(cmd_buffer, message_len);
    LOG(INFO) << "接收到的数据" << stu_info_1.name() << " " << stu_info_1.age() << " " << stu_info_1.money();
#endif
